// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/SkeletalMeshSocket.h"
#include "DrawDebugHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/KismetSystemLibrary.h"
// Sets default values
AShooter::AShooter() :
	BaseTurnRate(45.f),
	BaseLookUpRate(45.f),
	MouseVerticalSensitivity(1.f),
	MouseHorizontalSensitivity(1.f),
	bIsAiming(false),
	FollowCameraDefaultFOV(0.f),
	FollowCameraAimingFOV(60.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create a camera which has camera boom retract enabled
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.f;// Follow Distance
	CameraBoom->bUsePawnControlRotation = true;// Rotate arm based on controller
	CameraBoom->SocketOffset = FVector(0.f, 50.f, 50.f);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = true;

	GetCharacterMovement()->bOrientRotationToMovement = false; //orient towards direction of movement
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);//.. at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;



}

// Called when the game starts or when spawned
void AShooter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay() has been called!!"));
	
	if (FollowCamera) {
		FollowCameraDefaultFOV = GetFollowCamera()->FieldOfView; 
	}
	


}

void AShooter::MoveForward(float Value)
{
	if (Controller && Value != 0.0f) {
		const FRotator ControllerRotation{ Controller->GetControlRotation() };
		const FRotator YawControllerRotation{ 0, ControllerRotation.Yaw, 0 };
		const FVector ForwardVector{ FRotationMatrix{YawControllerRotation}.GetUnitAxis(EAxis::X) };

		AddMovementInput(ForwardVector, Value);
	}
}

void AShooter::MoveRight(float Value)
{
	if (Controller && Value != 0.0f) {
		const FRotator ControllerRotation{ Controller->GetControlRotation() };
		const FRotator YawControllerRotation{ 0, ControllerRotation.Yaw, 0 };
		const FVector RightVector{ FRotationMatrix{YawControllerRotation}.GetUnitAxis(EAxis::Y) };

		AddMovementInput(RightVector, Value);
	}
}

void AShooter::TurnRight(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->DeltaTimeSeconds);

}

void AShooter::LookUp(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->DeltaTimeSeconds);

}

void AShooter::MouseTurnRight(float MouseX)
{
	AddControllerYawInput(MouseX * MouseHorizontalSensitivity);
}

void AShooter::MouseLookUp(float MouseY)
{
	AddControllerPitchInput(MouseY * MouseVerticalSensitivity);
}

// Called every frame
void AShooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShooter::AimButtonPressed() {

	bIsAiming = true;
	GetFollowCamera()->FieldOfView = FollowCameraAimingFOV;
}

void AShooter::AimButtonReleased() {

	bIsAiming = false;
	GetFollowCamera()->FieldOfView = FollowCameraDefaultFOV;
}

//FireWeapon
void AShooter::FireWeapon() {
	UE_LOG(LogTemp, Warning, TEXT("Firing Weapon"));
	if (FireSound) {
		UGameplayStatics::PlaySound2D(this, FireSound);
	}
	const USkeletalMeshSocket* BarrelSocket = GetMesh()->GetSocketByName("BarrelSocket");

	if (BarrelSocket) {
		const FTransform SocketTransform = BarrelSocket->GetSocketTransform(GetMesh());
		
		if (MuzzleFlash) {
			UE_LOG(LogTemp, Warning, TEXT("MuzzleFlash"));
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleFlash, SocketTransform);
		}
		

		FVector2D ViewPortSize;
		if (GEngine && GEngine->GameViewport) {
			GEngine->GameViewport->GetViewportSize(ViewPortSize);
		}
		
		FVector2D CrosshairLocation(ViewPortSize.X / 2.f, ViewPortSize.Y / 2.f);
		CrosshairLocation.Y -= 50.f;

		FVector CrosshairWorldLocation;
		FVector CrosshairWorldDirection;

		bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(UGameplayStatics::GetPlayerController(this, 0),
			CrosshairLocation, CrosshairWorldLocation, CrosshairWorldDirection);

		if (bScreenToWorld) {
			FHitResult ScreenTraceHit;
			const FVector Start{ CrosshairWorldLocation };
			const FVector End{ CrosshairWorldLocation + CrosshairWorldDirection * 50'000.f };
			FVector BeamEndPoint{ End };

			GetWorld()->LineTraceSingleByChannel(ScreenTraceHit, Start, End, ECollisionChannel::ECC_Visibility);

			if (ScreenTraceHit.bBlockingHit) {
				BeamEndPoint = ScreenTraceHit.Location;
				//UKismetSystemLibrary::PrintString(this, "Impact from crosshair");
			}


			FHitResult WeaponTraceHit;
			const FVector WeaponTraceStart{ SocketTransform.GetLocation() };
			const FVector WeaponTraceEnd{ BeamEndPoint };

			GetWorld()->LineTraceSingleByChannel(WeaponTraceHit, WeaponTraceStart, WeaponTraceEnd, ECollisionChannel::ECC_Visibility);

			if (WeaponTraceHit.bBlockingHit) {
				BeamEndPoint = WeaponTraceHit.Location;
				//UKismetSystemLibrary::PrintString(this, "Impact from Weapon");
			}

			if ((ScreenTraceHit.bBlockingHit || WeaponTraceHit.bBlockingHit) && ImpactParticles) {
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, BeamEndPoint);
			}

			if (BeamParticles) {
				UParticleSystemComponent* Beam = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BeamParticles, SocketTransform);
				if (Beam) {
					Beam->SetVectorParameter(FName("Target"), BeamEndPoint);
				}
			}
		}
	}

	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (HipFireMontage && AnimInstance) {
		AnimInstance->Montage_Play(HipFireMontage);
		AnimInstance->Montage_JumpToSection(FName("StartFire"));
	}

}

// Called to bind functionality to input
void AShooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AShooter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AShooter::MoveRight);
	PlayerInputComponent->BindAxis("TurnRight", this, &AShooter::TurnRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AShooter::LookUp);
	PlayerInputComponent->BindAxis("TurnX", this, &AShooter::MouseTurnRight);
	PlayerInputComponent->BindAxis("LookY", this, &AShooter::MouseLookUp);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	
	PlayerInputComponent->BindAction("FireButton", IE_Pressed, this, &AShooter::FireWeapon);

	PlayerInputComponent->BindAction("AimButton", IE_Pressed, this, &AShooter::AimButtonPressed);
	PlayerInputComponent->BindAction("AimButton", IE_Released, this, &AShooter::AimButtonReleased);
}


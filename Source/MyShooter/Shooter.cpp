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
#include <MyShooter/Item.h>
#include "Components/WidgetComponent.h"

// Sets default values
AShooter::AShooter() :
	//Base aim rates
	BaseTurnRate(45.f),
	BaseLookUpRate(45.f),
	//Aim sensitivities 
	MouseVerticalSensitivity(1.f),
	MouseHorizontalSensitivity(1.f),
	HipMouseVerticalSensitivity(1.f),
	HipMouseHorizontalSensitivity(1.f),
	AimMouseVerticalSensitivity(.5f),
	AimMouseHorizontalSensitivity(.5f),
	//Aim state
	bIsAiming(false),
	//follow camera aim properties
	FollowCameraDefaultFOV(0.f),
	FollowCameraAimingFOV(40.f),
	FollowCameraCurrentFOV(0.f),
	FollowCameraAimSpeed(30.f),
	//shoot timer variables
	bShooting(false),
	CrosshairSpreadShoot(0.f),
	ShootTimeDuration(.05f),
	//weapon fire variables
	bFireButtonPressed(false),
	bShouldFire(true),
	AutoFireRate(.1f),
	//Item trace variables
	bShouldTraceForItems(false),
	OverlappedItemCount(0)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentLookItem = nullptr;
	//create a camera which has camera boom retract enabled
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 180.f;// Follow Distance
	CameraBoom->bUsePawnControlRotation = true;// Rotate arm based on controller
	CameraBoom->SocketOffset = FVector(0.f, 50.f, 70.f);

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
		FollowCameraCurrentFOV = FollowCameraDefaultFOV = GetFollowCamera()->FieldOfView; 
	}
	
	MouseVerticalSensitivity = HipMouseVerticalSensitivity;
	MouseHorizontalSensitivity = HipMouseHorizontalSensitivity;

	CrosshairSpreadMultiplier = CrosshairSpreadAim = CrosshairSpreadAir = CrosshairSpreadHip = CrosshairSpreadMotion = 0.f;
}

// Called every frame
void AShooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	UpdateAim(DeltaTime);
	
	UpdateMouseSensitivity();
	
	CalculateCrosshairSpreadMultiplier(DeltaTime);
	
	FString CrosshairSpreadMessage = FString::Printf(TEXT("CrossHairSpreadMultiplier : %f"), CrosshairSpreadMultiplier);
	GEngine->AddOnScreenDebugMessage(1, 0.f, FColor::Red, CrosshairSpreadMessage);

	
	if (bShouldTraceForItems) {
		TraceForItems();
	}

}

void AShooter::UpdateMouseSensitivity() {
	MouseVerticalSensitivity = (bIsAiming) ? AimMouseVerticalSensitivity : HipMouseVerticalSensitivity;
	MouseHorizontalSensitivity = (bIsAiming) ? AimMouseHorizontalSensitivity : HipMouseHorizontalSensitivity;
}

void AShooter::CalculateCrosshairSpreadMultiplier(const float& DeltaTime)
{
	FVector2D WalkSpeedRange = { 0.f, 600.f };
	FVector2D SpeedMultiplierRange = { 0.f, 1.f };
	FVector Velocity{ GetVelocity() };
	Velocity.Z = 0;

	CrosshairSpreadMotion = FMath::GetMappedRangeValueClamped(WalkSpeedRange, SpeedMultiplierRange, Velocity.Size());

	CrosshairSpreadAir = (!GetCharacterMovement()->IsFalling())?
		FMath::FInterpTo(CrosshairSpreadAir, 0.f, DeltaTime, 30.f) :
		FMath::FInterpTo(CrosshairSpreadAir, 2.25f, DeltaTime, 2.25f);

	CrosshairSpreadAim = (IsAiming()) ?
		FMath::FInterpTo(CrosshairSpreadAim, 0.6f, DeltaTime, 30.f) :
		FMath::FInterpTo(CrosshairSpreadAim, 0.f, DeltaTime, 30.f);

	CrosshairSpreadShoot = (bShooting) ?
		FMath::FInterpTo(CrosshairSpreadShoot, .5f, DeltaTime, 60.f) :
		FMath::FInterpTo(CrosshairSpreadShoot, 0.f, DeltaTime, 45.f);

	CrosshairSpreadMultiplier = .5f + CrosshairSpreadMotion + CrosshairSpreadAir - CrosshairSpreadAim + CrosshairSpreadShoot;

}

void AShooter::StartCrosshairBulletFire()
{
	bShooting = true;

	GetWorldTimerManager().SetTimer(CrosshairShootTimer, this, &AShooter::FinishCrosshairBulletFire, ShootTimeDuration);
}

void AShooter::FinishCrosshairBulletFire()
{
	bShooting = false;
}

void AShooter::FireButtonPressed()
{
	bFireButtonPressed = true;
	StartAutoFire();
}

void AShooter::FireButtonReleased()
{
	bFireButtonPressed = false;
}

void AShooter::StartAutoFire()
{
	if (bShouldFire) {
		FireWeapon();
		bShouldFire = false;
		GetWorldTimerManager().SetTimer(AutoFireTimer, this, &AShooter::AutoFireReset, AutoFireRate);
	}
}

void AShooter::AutoFireReset()
{
	bShouldFire = true;
	if (bFireButtonPressed) {
		StartAutoFire();
	}
}

bool AShooter::TraceUnderCrosshair(FHitResult& OutHitResult)
{
	FVector2D ViewportSize;
	
	if (GEngine && GEngine->GameViewport) {
		GEngine->GameViewport->GetViewportSize(ViewportSize);
	}

	const FVector2D CrosshairPosition{ ViewportSize.X/2, ViewportSize.Y/2 };
	
	FVector CrosshairWorldPosition, CrosshairWorldDirection;
	bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(UGameplayStatics::GetPlayerController(GetWorld(), 0), CrosshairPosition, 
		CrosshairWorldPosition, CrosshairWorldDirection);

	if (bScreenToWorld) {
		const FVector Start{ CrosshairWorldPosition };
		const FVector End{ Start + CrosshairWorldDirection * 1'000.0f };

		GetWorld()->LineTraceSingleByChannel(OutHitResult, Start, End, ECollisionChannel::ECC_Visibility);

		if (OutHitResult.bBlockingHit) {
			return true;
		}
	}

	return false;
}

void AShooter::IncrementOverlappedItemCount(int8 Amount)
{
	OverlappedItemCount += Amount;
	if (OverlappedItemCount > 0) {
		bShouldTraceForItems = true;
	}
}

void AShooter::DecrementOverlappedItemCount(int8 Amount, AItem* ExitedItem)
{
	OverlappedItemCount -= Amount;
	if (OverlappedItemCount <= 0) {
		bShouldTraceForItems = false;
	}
	if (ExitedItem == CurrentLookItem) {
		CurrentLookItem->GetPickupWidget()->SetVisibility(false);
		CurrentLookItem = nullptr;
	}
}

void AShooter::TraceForItems()
{
	FHitResult ItemLook;

	if (TraceUnderCrosshair(ItemLook)) {
		AItem* HitItem = Cast<AItem>(ItemLook.GetActor());
		if (HitItem && HitItem->IsWithinShooterRange()) {
			if (CurrentLookItem != HitItem) {
				if (CurrentLookItem) {
					CurrentLookItem->GetPickupWidget()->SetVisibility(false);
				}
				if(HitItem->GetPickupWidget()){
					HitItem->GetPickupWidget()->SetVisibility(true);
				}
				CurrentLookItem = HitItem;
			}
		}
		else if (!HitItem && CurrentLookItem) {
			CurrentLookItem->GetPickupWidget()->SetVisibility(false);
			CurrentLookItem = nullptr;
		}
	}
}


void AShooter::UpdateAim(const float& DeltaTime) {

	FollowCameraCurrentFOV = (bIsAiming) ?
		FMath::FInterpTo(FollowCameraCurrentFOV, FollowCameraAimingFOV, DeltaTime, FollowCameraAimSpeed) :
		FMath::FInterpTo(FollowCameraCurrentFOV, FollowCameraDefaultFOV, DeltaTime, FollowCameraAimSpeed);
	GetFollowCamera()->SetFieldOfView(FollowCameraCurrentFOV);

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

void AShooter::AimButtonPressed() {

	bIsAiming = true;
}

void AShooter::AimButtonReleased() {

	bIsAiming = false;
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
		//CrosshairLocation.Y -= 50.f;

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

	StartCrosshairBulletFire();

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
	
	PlayerInputComponent->BindAction("FireButton", IE_Pressed, this, &AShooter::FireButtonPressed);
	PlayerInputComponent->BindAction("FireButton", IE_Released, this, &AShooter::FireButtonReleased);

	PlayerInputComponent->BindAction("AimButton", IE_Pressed, this, &AShooter::AimButtonPressed);
	PlayerInputComponent->BindAction("AimButton", IE_Released, this, &AShooter::AimButtonReleased);
}

float AShooter::GetCrosshairSpreadMultiplier() const
{
	return CrosshairSpreadMultiplier;
}


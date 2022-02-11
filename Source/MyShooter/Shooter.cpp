// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
// Sets default values
AShooter::AShooter() :
	BaseTurnRate(45.f),
	BaseLookUpRate(45.f),
	MouseVerticalSensitivity(1.f),
	MouseHorizontalSensitivity(1.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create a camera which has camera boom retract enabled
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.f;// Follow Distance
	CameraBoom->bUsePawnControlRotation = true;// Rotate arm based on controller

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void AShooter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay() has been called!!"));
	int myint{ 42 };
	UE_LOG(LogTemp, Warning, TEXT("int myint: %d"), myint);
	
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
}


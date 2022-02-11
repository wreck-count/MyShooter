// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAnimInstance.h"
#include "Shooter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UShooterAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (!ShooterCharacter) {
		ShooterCharacter = Cast<AShooter>(TryGetPawnOwner());
	}
	if (ShooterCharacter) {
		FVector Velocity{ ShooterCharacter->GetVelocity() };
		Velocity.Z = 0;
		Speed = Velocity.Size();

		bIsInAir= ShooterCharacter->GetCharacterMovement()->IsFalling();


		bIsAccelerating = (ShooterCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f);
	}

}

void UShooterAnimInstance::NativeInitializeAnimation()
{

	ShooterCharacter = Cast<AShooter>(TryGetPawnOwner());

}

// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAnimInstance.h"
#include "Shooter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

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

		FRotator AimRotation = ShooterCharacter->GetBaseAimRotation();
		FString RotationMessage = FString::Printf(TEXT("BaseAimRotation : %f"), AimRotation.Yaw);

		FRotator MovementRotation = UKismetMathLibrary::MakeRotFromX(ShooterCharacter->GetVelocity());
		FString MovementMessage = FString::Printf(TEXT("MovementRotation : %f"), MovementRotation.Yaw);

		FRotator MovementOffset = UKismetMathLibrary::NormalizedDeltaRotator(AimRotation, MovementRotation);
		MovementOffsetYaw = MovementOffset.Yaw;
		FString OffsetMessage = FString::Printf(TEXT("MovementOffsetYaw : %f"), MovementOffsetYaw);
		FString PrevOffsetMessage = FString::Printf(TEXT("PrevMovementOffsetYaw : %f"), PrevMovementOffsetYaw);
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(1, 0.f, FColor::White, OffsetMessage);
			GEngine->AddOnScreenDebugMessage(1, 0.f, FColor::Red, PrevOffsetMessage);
		}
	}

}

void UShooterAnimInstance::NativeInitializeAnimation()
{

	ShooterCharacter = Cast<AShooter>(TryGetPawnOwner());
}



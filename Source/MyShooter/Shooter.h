// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Shooter.generated.h"

UCLASS()
class MYSHOOTER_API AShooter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);

	void MoveRight(float Value);
	
	void TurnRight(float Rate);

	void LookUp(float Rate);

	void MouseTurnRight(float MouseX);

	void MouseLookUp(float MouseY);

	void FireWeapon();

	/* Handle when Aim button is pressed, set bIsAiming to true*/
	void AimButtonPressed();
	
	/*Handle when Aim button is released, set bIsAiming to false*/
	void AimButtonReleased();

	/* Handle field of view of Follow Camera for Aiming*/
	void UpdateAim(const float& DeltaTime);

	/* Handle mouse sensitivity for aiming*/
	void UpdateMouseSensitivity();

	void CalculateCrosshairSpreadMultiplier(const float& DeltaTime);

	/* initiates a Bullet fire timer and calls FinishCrosshairBulletFire on timer end*/
	void StartCrosshairBulletFire();

	UFUNCTION()
	void FinishCrosshairBulletFire();


	void FireButtonPressed();
	
	void FireButtonReleased();

	void StartAutoFire();

	UFUNCTION()
	void AutoFireReset();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;

	/*current vertical mouse sens*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float MouseVerticalSensitivity;

	/*current horizontal mouse sens*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float MouseHorizontalSensitivity;

	/* vertical mouse sens when hip firing*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float HipMouseVerticalSensitivity;

	/*horizontal mouse sens when hip firing*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float HipMouseHorizontalSensitivity;

	/*vertical mouse sens when aiming*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float AimMouseVerticalSensitivity;

	/*horizontal mouse sens when aiming*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float AimMouseHorizontalSensitivity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class USoundCue* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* HipFireMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* ImpactParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* BeamParticles;

	/* Stores the state of aiming*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	bool bIsAiming;

	/* Stores the follow camera's default field of view*/
	float FollowCameraDefaultFOV;

	/* Stores the follow camera's aiming field of view*/
	float FollowCameraAimingFOV;

	/* Tracks the current field of view for the follow camera*/
	float FollowCameraCurrentFOV;

	/* Follow Camera Aim zoom speed*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float FollowCameraAimSpeed;

	/* stores the value proportional to the total crosshair spread due to several factors*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Crosshair, meta = (AllowPrivateAccess = "true"))
	float CrosshairSpreadMultiplier;

	/*Stores the component of crosshair spread while in air*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Crosshair, meta = (AllowPrivateAccess = "true"))
	float CrosshairSpreadAir;

	/*Stores the component of crosshair spread while in motion*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Crosshair, meta = (AllowPrivateAccess = "true"))
	float CrosshairSpreadMotion;

	/*Stores the componenet of crosshair spread while aiming*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Crosshair, meta = (AllowPrivateAccess = "true"))
	float CrosshairSpreadAim;

	/*Stores the component of crosshair spread while hip aiming*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Crosshair, meta = (AllowPrivateAccess = "true"))
	float CrosshairSpreadHip;

	float CrosshairSpreadShoot;

	float ShootTimeDuration;
	bool bShooting;
	FTimerHandle CrosshairShootTimer;

	bool bFireButtonPressed;
	bool bShouldFire;
	float AutoFireRate;
	FTimerHandle AutoFireTimer;

public:
	/*Returns a CameraBoom object*/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/*Returns Follow Camera object*/
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	/* Returns the state of aiming*/
	FORCEINLINE bool IsAiming() const { return bIsAiming; }

	UFUNCTION(BlueprintCallable)
	float GetCrosshairSpreadMultiplier() const;
};

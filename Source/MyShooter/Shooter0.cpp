// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter0.h"

// Sets default values
AShooter0::AShooter0()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooter0::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShooter0::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooter0::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


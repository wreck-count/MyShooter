// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include <MyShooter/Shooter.h>

// Sets default values
AItem::AItem() :
	bWithinShooterRange(false),
	ItemName("Default"),
	ItemCount(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ItemMesh"));
	SetRootComponent(ItemMesh);

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(ItemMesh);
	BoxCollider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);

	PickupWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("PickupWidget"));
	PickupWidget->SetupAttachment(ItemMesh);
	
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->SetupAttachment(ItemMesh);
	SphereCollider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	PickupWidget->SetVisibility(false);
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &AItem::ShooterOnOverlap);
	SphereCollider->OnComponentEndOverlap.AddDynamic(this, &AItem::ShooterOffOverlap);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void AItem::ShooterOnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor) {
		AShooter* ShooterCharacter = Cast<AShooter>(OtherActor);
		if (ShooterCharacter) {
			ShooterCharacter->IncrementOverlappedItemCount(1);
			bWithinShooterRange = true;
		}
	}

}

void AItem::ShooterOffOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor) {
		AShooter* ShooterCharacter = Cast<AShooter>(OtherActor);
		if (ShooterCharacter) {
			ShooterCharacter->DecrementOverlappedItemCount(1, this);
			bWithinShooterRange = false;
		}
	}

}

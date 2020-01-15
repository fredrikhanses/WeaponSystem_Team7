// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Engine/Engine.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	USceneComponent* scene = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = scene;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	
}

void AWeapon::OnFire()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Fire");
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


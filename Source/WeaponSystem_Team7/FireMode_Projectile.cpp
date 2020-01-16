// Fill out your copyright notice in the Description page of Project Settings.


#include "FireMode_Projectile.h"
#include <Math/UnrealMathUtility.h>
#include "WeaponSystem_Team7Projectile.h"

// Sets default values for this component's properties
UFireMode_Projectile::UFireMode_Projectile()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	bCanFire = true;
}

// Called when the game starts
void UFireMode_Projectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UFireMode_Projectile::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UFireMode_Projectile::Fire(AWeapon* Weapon)
{
	if (bCanFire)
	{
		bCanFire = false;

		SpawnProjectile(Weapon);

		GetWorld()->GetTimerManager().SetTimer(FireDelayTimerHandle, this, &UFireMode_Projectile::ResetFire, FireRate, false);
	}
}

void UFireMode_Projectile::ResetFire()
{
	bCanFire = true;
	GetWorld()->GetTimerManager().ClearTimer(FireDelayTimerHandle);
}

void UFireMode_Projectile::SpawnProjectile(AWeapon* Weapon)
{

	const int32 RandomSeed = FMath::Rand();
	FRandomStream WeaponRandomStream(RandomSeed);
	const float CurrentSpread = Spread;
	const float SpreadCone = FMath::DegreesToRadians(Spread * 0.5f);
	const FVector StartLocation = Weapon->Mesh->GetSocketLocation("Muzzle");
	const FRotator StartRotation = Weapon->Mesh->GetSocketRotation("Muzzle");

	//Set Spawn Collision Handling Override
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	// spawn the projectile at the muzzle
	GetWorld()->SpawnActor<AWeaponSystem_Team7Projectile>(ProjectileClass, StartLocation, StartRotation, ActorSpawnParams);
}



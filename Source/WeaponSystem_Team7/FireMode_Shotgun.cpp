// Fill out your copyright notice in the Description page of Project Settings.


#include "FireMode_Shotgun.h"
#include <CollisionQueryParams.h>
#include <DrawDebugHelpers.h>
#include <Engine/Engine.h>
#include <Math/UnrealMathUtility.h>
#include <Math/RandomStream.h>
#include <TimerManager.h>

// Sets default values for this component's properties
UFireMode_Shotgun::UFireMode_Shotgun()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	bCanFire = true;
}

// Called when the game starts
void UFireMode_Shotgun::BeginPlay()
{
	Super::BeginPlay();
	InitRapidFireShots = RapidFireShots;

	Weapon = Cast<AWeapon>(GetOwner());
}

// Called every frame
void UFireMode_Shotgun::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UFireMode_Shotgun::RapidFire()
{
	if (bCanFire)
	{
		GetWorld()->GetTimerManager().SetTimer(RapidFireTimerHandle, this, &UFireMode_Shotgun::Fire, RapidFireDelay, true);
		bCanFire = false;
	}
}

void UFireMode_Shotgun::Fire()
{
	if (--RapidFireShots <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(RapidFireTimerHandle);
		RapidFireShots = InitRapidFireShots;
		GetWorld()->GetTimerManager().SetTimer(FireDelayTimerHandle, this, &UFireMode_Shotgun::ResetFire, FireRate, false);
	}

	for (int i = 0; i <= PebbleAmount; i++)
	{
		Instant_Fire();
	}
}

void UFireMode_Shotgun::ResetFire()
{
	bCanFire = true;
	GetWorld()->GetTimerManager().ClearTimer(FireDelayTimerHandle);
}

void UFireMode_Shotgun::Instant_Fire()
{
	const int32 RandomSeed = FMath::Rand();
	FRandomStream WeaponRandomStream(RandomSeed);
	const float CurrentSpread = Spread;
	const float SpreadCone = FMath::DegreesToRadians(Spread * 0.5f);
	const FVector StartTrace = Weapon->Mesh->GetSocketLocation("Muzzle");
	const FVector AimDir = Weapon->Mesh->GetSocketRotation("Muzzle").Vector();
	const FVector ShootDir = WeaponRandomStream.VRandCone(AimDir, SpreadCone);
	const FVector EndTrace = StartTrace + ShootDir * Range;
	const FHitResult Hit = LineTrace(StartTrace, EndTrace);

	ProcessInstantHit(Hit, StartTrace, ShootDir, RandomSeed, CurrentSpread);
}

FHitResult UFireMode_Shotgun::LineTrace(const FVector& TraceFrom, const FVector& TraceTo) const
{
	static FName WeaponFireTag = FName(TEXT("WeaponTrace"));

	FCollisionQueryParams TraceParams(WeaponFireTag, true, Weapon->GetInstigator());
	TraceParams.bReturnPhysicalMaterial = true;
	TraceParams.AddIgnoredActor(Weapon);
	FHitResult Hit(ForceInit);

	GetWorld()->LineTraceSingleByChannel(Hit, TraceFrom, TraceTo, ECC_WorldDynamic, TraceParams);

	return Hit;
}

void UFireMode_Shotgun::ProcessInstantHit(const FHitResult& Hit, const FVector& Origin, const FVector& ShootDir, int32 RandomSeed, float ReticleSpread)
{
	const FVector Endtrace = Origin + ShootDir * Range;
	const FVector EndPoint = Hit.GetActor() ? Hit.ImpactPoint : Endtrace;

	if (Hit.GetActor())
	{
		DrawDebugLine(Weapon->GetWorld(), Origin, Hit.TraceEnd, FColor::Yellow, false, 2.0f);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Magenta, Hit.GetActor()->GetFName().ToString());
	}
	else
	{
		DrawDebugLine(Weapon->GetWorld(), Origin, Hit.TraceEnd, FColor::Red, false, 2.0f);
	}
}



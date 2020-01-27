// Fill out your copyright notice in the Description page of Project Settings.


#include "FireMode.h"
#include <DrawDebugHelpers.h>
#include <Engine/Engine.h>
#include <Kismet/GameplayStatics.h>

UFireMode::UFireMode()
{
}

void UFireMode::BeginPlay()
{
	Super::BeginPlay();

	Weapon = Cast<AWeapon>(GetOwner());
}

void UFireMode::Execute()
{
	OnFire();
}

void UFireMode::OnFire()
{
	switch (weaponType)
	{

	case WeaponType::LineTrace:
		if (PebbleAmount < 1)
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "You need to set PebbleAmount to more than 0!");
		}
		else
		{
			for (int i = 0; i < PebbleAmount; i++)
			{
				Instant_Fire();
			}
		}
		break;

	case WeaponType::Projectile:

		if (ProjectileClass == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "You need to set a Projectile class!");
		}
		else
		{
			FireProjectile();
		}
		break;

	default:
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "You need to choose a Weapon Type!");
		break;
	}
}

void UFireMode::Instant_Fire()
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

FHitResult UFireMode::LineTrace(const FVector& TraceFrom, const FVector& TraceTo) const
{
	static FName WeaponFireTag = FName(TEXT("WeaponTrace"));

	FCollisionQueryParams TraceParams(WeaponFireTag, true, Weapon->GetInstigator());
	TraceParams.bReturnPhysicalMaterial = true;
	TraceParams.AddIgnoredActor(Weapon);
	FHitResult Hit(ForceInit);

	GetWorld()->LineTraceSingleByChannel(Hit, TraceFrom, TraceTo, ECC_WorldDynamic, TraceParams);

	return Hit;
}

void UFireMode::ProcessInstantHit(const FHitResult& Hit, const FVector& Origin, const FVector& ShootDir, int32 RandomSeed, float ReticleSpread)
{
	const FVector Endtrace = Origin + ShootDir * Range;
	const FVector EndPoint = Hit.GetActor() ? Hit.ImpactPoint : Endtrace;

	if (Hit.GetActor())
	{
		DrawDebugLine(Weapon->GetWorld(), Origin, Hit.TraceEnd, FColor::Red, false, 2.0f);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Magenta, Hit.GetActor()->GetFName().ToString());

		UGameplayStatics::ApplyDamage(Hit.GetActor(), Damage, nullptr, nullptr, nullptr);

		if (EmitterTemplate != nullptr)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), EmitterTemplate, Hit.ImpactPoint, Hit.Normal.Rotation(), FVector(EmitterScale, EmitterScale, EmitterScale));
		}
	}
	else
	{
		DrawDebugLine(Weapon->GetWorld(), Origin, Hit.TraceEnd, FColor::Yellow, false, 2.0f);
	}
}

void UFireMode::FireProjectile()
{
	const FVector StartLocation = Weapon->Mesh->GetSocketLocation("Muzzle");
	const FRotator StartRotation = Weapon->Mesh->GetSocketRotation("Muzzle");

	//Set Spawn Collision Handling Override
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	// spawn the projectile at the muzzle
	GetWorld()->SpawnActor<AWeaponSystem_Team7Projectile>(ProjectileClass, StartLocation, StartRotation, ActorSpawnParams);
}
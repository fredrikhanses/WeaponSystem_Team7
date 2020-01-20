// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include "Weapon.h"
#include "WeaponSystem_Team7Projectile.h"
#include "FireMode.generated.h"

UENUM()
enum class WeaponType
{
LineTrace		UMETA(DisplayName = "LineTrace"),
Projectile		UMETA(DisplayName = "Projectile")
};

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API UFireMode : public UModuleBase
{
	GENERATED_BODY()
	
private:

	AWeapon* Weapon;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		WeaponType weaponType = WeaponType::LineTrace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Spread = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Range = 750;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shotgun")
		int PebbleAmount = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
		TSubclassOf<AWeaponSystem_Team7Projectile> ProjectileClass;

private:
	UFireMode();

	virtual void BeginPlay() override;

	void FireProjectile();

	void Instant_Fire();
	FHitResult LineTrace(const FVector& TraceFrom, const FVector& TraceTo) const;
	void ProcessInstantHit(const FHitResult& Hit, const FVector& Origin, const FVector& ShootDir, int32 RandomSeed, float ReticleSpread);

public:

	UFUNCTION(BlueprintCallable)
		void OnFire();

		virtual void Execute() override;

};
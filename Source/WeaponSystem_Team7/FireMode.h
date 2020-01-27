#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include "Weapon.h"
#include "WeaponSystem_Team7Projectile.h"
#include <Particles/ParticleSystem.h>
#include "FireMode.generated.h"

UENUM()
enum class WeaponType
{
	LineTrace		UMETA(DisplayName = "LineTrace"),
	Projectile		UMETA(DisplayName = "Projectile")
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API UFireMode : public UModuleBase
{
	GENERATED_BODY()

private:

	AWeapon* Weapon;

public:

	/**
	* Determines if the weapon is line tracing or if it shoots projectiles.
	* If using projectile, You need to specify the blueprint of the projectile further down.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		WeaponType weaponType = WeaponType::LineTrace;

	/**
	* Randomize the spread of each bullet from the center.
	* This is not considered if using Projectile weapon type.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Spread = 10;

	/**
	* How far each bullet reaches.
	* This is not considered if using Projectile weapon type.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Range = 750;

	/**
	* How much damage each bullet does.
	* This is not considered if using Projectile weapon type.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Damage = 1.0f;

	/**
	* How many bullets each shot fires. This is used for Creating shotguns
	* or weapons that need to fire more than one bullet each time.
	* This is not considered if using Projectile weapon type.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shotgun")
		int PebbleAmount = 1;

	/**
	* The Projectile class or blueprint that is used when firing in Projectile mode.
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
		TSubclassOf<AWeaponSystem_Team7Projectile> ProjectileClass;

	/**
	* The particles system that is used when hitting an enemy.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
		UParticleSystem* EmitterTemplate;

	/**
	* The particles system that is used when hitting an enemy.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	float EmitterScale;

private:
	UFireMode();

	virtual void BeginPlay() override;

	void FireProjectile();

	void Instant_Fire();
	FHitResult LineTrace(const FVector& TraceFrom, const FVector& TraceTo) const;
	void ProcessInstantHit(const FHitResult& Hit, const FVector& Origin, const FVector& ShootDir, int32 RandomSeed, float ReticleSpread);

public:

	/**
	* Fires the bullets.
	* It is recommended to use the Fire Component and using the OnFire function on that instead.
	*/
	UFUNCTION(BlueprintCallable)
		void OnFire();

	virtual void Execute() override;
};
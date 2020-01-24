#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include "Weapon.h"
#include <Particles/ParticleSystem.h>
#include "VFX.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API UVFX : public UModuleBase
{
	GENERATED_BODY()

private:

	AWeapon* Weapon;

public:

	/**
	* The particles system that are used for the muzzle flash.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
		UParticleSystem* EmitterTemplate;


	/**
	* The scale of the particle system.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		FVector Scale=FVector(1.0f);

private:

	UVFX();

	virtual void BeginPlay() override;

	void CreateVFX();

public:

	virtual void Execute() override;

	/**
	* Spawns the particles system on the muzzle location.
	* It is recommended to use the Fire Component and using the OnFire function on that instead.
	*/
	UFUNCTION(BlueprintCallable)
		void OnFire();
};
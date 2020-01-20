// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include "Weapon.h"
#include <Particles/ParticleSystem.h>
#include "VFX.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API UVFX : public UModuleBase
{
	GENERATED_BODY()

private:

	AWeapon* Weapon;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
		UParticleSystem* EmitterTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		FVector Scale=FVector(1.0f);

private:

	UVFX();

	virtual void BeginPlay() override;

	void CreateVFX();

public:
	UFUNCTION(BlueprintCallable)
	virtual void Execute() override;

	UFUNCTION(BlueprintCallable)
		void OnFire();

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include <WeaponSystem_Team7\Weapon.h>
#include "SFX.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API USFX : public UModuleBase
{
	GENERATED_BODY()
	

private:

	AWeapon* Weapon;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
		class USoundBase* FireSound;

private:

	USFX();

	virtual void BeginPlay() override;

	void CreateSound();

public:

	virtual void Execute() override;

	UFUNCTION(BlueprintCallable)
		void OnFire();

};

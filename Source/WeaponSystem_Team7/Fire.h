// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include "Ammo.h"
#include "Fire.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API UFire : public UModuleBase
{
	GENERATED_BODY()
	
private:
	//Handle Delay between shots
	FTimerHandle FireDelayTimerHandle;

	FTimerHandle BurstTimerHandle;

	FTimerHandle AutofireTimerHandle;

	int InitialBurstCount;

	TArray<UModuleBase*> Array;

	bool bCanFire;

	UAmmo* Ammo;
	int CurrentAmmo=1;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int BurstCount = 3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float BurstDelay = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float FireRate = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bAutomaticWeapon;

	UPROPERTY(BlueprintReadWrite)
		bool bAutofire;

private:

	UFire();

	virtual void BeginPlay() override;

	void StartFire();
	void ResetFire();

	void Instant_Fire();

	void Autofire();

public:

	UFUNCTION(BlueprintCallable)
	void OnFire(TArray<UModuleBase*> ModuleArray);

	virtual void Execute() override;

};

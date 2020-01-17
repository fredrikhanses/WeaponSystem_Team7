// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include <Engine/EngineTypes.h>
#include "FireMode_Shotgun.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API UFireMode_Shotgun : public UActorComponent
{
	GENERATED_BODY()

private:

	int BurstCount = 0;
	int InitRapidFireShots;

	AWeapon* Weapon;

	//Handle Delay between shots
	FTimerHandle FireDelayTimerHandle;

	FTimerHandle RapidFireTimerHandle;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Spread = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Range = 750;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		int PebbleAmount = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float FireRate = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		int RapidFireShots = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float RapidFireDelay = 0.1f;

	UPROPERTY(BlueprintReadOnly)
	//True if the player can fire, false otherwise
	bool bCanFire;

private:
	void Instant_Fire();
	FHitResult LineTrace(const FVector& TraceFrom, const FVector& TraceTo) const;
	void ProcessInstantHit(const FHitResult& Hit, const FVector& Origin, const FVector& ShootDir, int32 RandomSeed, float ReticleSpread);

	//Resets the players ability to fire
	void ResetFire();

	void OnFire();

public:
	// Sets default values for this component's properties
	UFireMode_Shotgun();

	UFUNCTION(BlueprintCallable)
	void Fire();	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
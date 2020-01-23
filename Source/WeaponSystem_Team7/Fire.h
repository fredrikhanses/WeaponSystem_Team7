#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include "Ammo.h"
#include "Fire.generated.h"

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
	bool bFirstShot;

	UAmmo* Ammo;
	int CurrentAmmo=1;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burst Fire")
		int BurstCount = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Burst Fire")
		float BurstDelay = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float FireRate = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		bool bAutomaticWeapon;

	UPROPERTY(BlueprintReadWrite, Category = "Properties")
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

	UFUNCTION(BlueprintCallable)
	void ToggleAutofire(bool InAutofire);


	virtual void Execute() override;
};
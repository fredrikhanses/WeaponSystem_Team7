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

	/**
	* How many bullets are fired in burst.
	* This is not considered if Automatic Weapon option is used.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Burst Fire")
		int BurstCount = 3;

	/**
	* The time between the burst shots. Mind the fire rate when tweaking this.
	* This is not considered if Automatic Weapon option is used.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Burst Fire")
		float BurstDelay = 0.1f;

	/**
	* Determines how fast the weapon fires its bullets.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float FireRate = 1.0f;

	/**
	* Check this to convert weapon to an automatic fire weapon.
	* For this to work, you need to use the ToggleAutofire function and set
	* the check to true on the pressed output of a button event and false on released.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		bool bAutomaticWeapon;

		bool bAutofire;

private:

	UFire();

	virtual void BeginPlay() override;

	void StartFire();
	void ResetFire();

	void Instant_Fire();

	void Autofire();

public:

	/**
	* Fires the Weapon. Executes all components that are specified in the array.
	* Works only with components that has ModuleBase as Parent.
	*/
	UFUNCTION(BlueprintCallable)
	void OnFire(TArray<UModuleBase*> ModuleArray);

	/**
	* Toggles automatic fire mode. For this to work, you need to have another copy
	* of this function. One piped to the pressed output of a button event
	* and the other to the released. Check true on pressed and false on released.
	*/
	UFUNCTION(BlueprintCallable)
	void ToggleAutofire(bool InAutofire);
};
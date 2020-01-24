#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include <WeaponSystem_Team7\Weapon.h>
#include <Sound/SoundCue.h>
#include <Sound/SoundBase.h>
#include "SFX.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API USFX : public UModuleBase
{
	GENERATED_BODY()

private:

	AWeapon* Weapon;

public:
	/**
	 * Choose the SoundCue to play when firing your gun.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sound", meta = (AllowPrivateAccess = "true"))
		USoundCue* FireSoundCue;

	/**
	 * Volume
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Volume = 1.0f;

	/**
	 * Min value for randomizing volume
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomizeProperties")
		float VolumeRangeMin = 0.25f;

	/**
	 * Max value for randomizing volume
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomizeProperties")
		float VolumeRangeMax = 0.25f;

	/**
	 * Pitch
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Pitch = 1.0f;

	/**
	 * Min value for randomizing pitch
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomizeProperties")
		float PitchRangeMin = 0.25f;

	/**
	 * Max value for randomizing pitch
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomizeProperties")
		float PitchMRangeMax = 0.25f;

private:

	USFX();

	virtual void BeginPlay() override;

	void CreateSound();

public:

	virtual void Execute() override;

	/**
	 * Plays the soundcue with set parameters
	 */
	UFUNCTION(BlueprintCallable)
		void OnFire();
};
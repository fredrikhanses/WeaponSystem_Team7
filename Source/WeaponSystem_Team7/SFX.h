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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sound", meta = (AllowPrivateAccess = "true"))
		USoundCue* FireSoundCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Volume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomizeProperties")
		float VolumeRangeMin = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomizeProperties")
		float VolumeRangeMax = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Pitch = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomizeProperties")
		float PitchRangeMin = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomizeProperties")
		float PitchMRangeMax = 0.25f;

private:

	USFX();

	virtual void BeginPlay() override;

	void CreateSound();

public:

	virtual void Execute() override;

	UFUNCTION(BlueprintCallable)
		void OnFire();
};
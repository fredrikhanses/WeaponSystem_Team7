#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraShake.h"
#include "WeaponCameraShake.generated.h"

UCLASS()
class WEAPONSYSTEM_TEAM7_API UWeaponCameraShake : public UCameraShake
{
	GENERATED_BODY()

public:

	/**
	* Default constructor
	*/
	UWeaponCameraShake();

	/**
	* Minimum pitch amount
	*/
	UPROPERTY(EditAnywhere, Category = Pitch)
	float MinPitchAmplitude;

	/**
	* Maximum pitch amount
	*/
	UPROPERTY(EditAnywhere, Category = Pitch)
	float MaxPitchAmplitude;

	/**
	* Minimum pitch interval
	*/
	UPROPERTY(EditAnywhere, Category = Pitch)
	float MinPitchFrequency;

	/**
	* Maximum pitch interval
	*/
	UPROPERTY(EditAnywhere, Category = Pitch)
	float MaxPitchFrequency;

	/**
	* Minimum yaw interval
	*/
	UPROPERTY(EditAnywhere, Category = Yaw)
	float MinYawAmplitude;

	/**
	* Maximum yaw amount
	*/
	UPROPERTY(EditAnywhere, Category = Yaw)
	float MaxYawAmplitude;

	/**
	* Minimum yaw interval
	*/
	UPROPERTY(EditAnywhere, Category = Yaw)
	float MinYawFrequency;

	/**
	* Maximum yaw interval
	*/
	UPROPERTY(EditAnywhere, Category = Yaw)
	float MaxYawFrequency;

};

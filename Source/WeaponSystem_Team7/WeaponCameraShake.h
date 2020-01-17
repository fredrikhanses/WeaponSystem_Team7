// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraShake.h"
#include "WeaponCameraShake.generated.h"

UCLASS()
class WEAPONSYSTEM_TEAM7_API UWeaponCameraShake : public UCameraShake
{
	GENERATED_BODY()

public:

	UWeaponCameraShake();

	UPROPERTY(EditAnywhere, Category = "Pitch")
	float MinPitchAmplitude;

	UPROPERTY(EditAnywhere, Category = "Pitch")
	float MaxPitchAmplitude;

	UPROPERTY(EditAnywhere, Category = "Pitch")
	float MinPitchFrequency;

	UPROPERTY(EditAnywhere, Category = "Pitch")
	float MaxPitchFrequency;
	
	UPROPERTY(EditAnywhere, Category = "Yaw")
	float MinYawAmplitude;

	UPROPERTY(EditAnywhere, Category = "Yaw")
	float MaxYawAmplitude;

	UPROPERTY(EditAnywhere, Category = "Yaw")
	float MinYawFrequency;

	UPROPERTY(EditAnywhere, Category = "Yaw")
	float MaxYawFrequency;

};

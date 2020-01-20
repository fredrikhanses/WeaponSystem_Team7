// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine/EngineTypes.h"
#include "ModuleBase.h"
#include <Camera/CameraShake.h>
#include "Recoil.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API URecoil : public UModuleBase
{
	GENERATED_BODY()

private:

	FTimerHandle TimerHandle;

	int InitialRecoilSteps;

	int InitialRecoverSteps;

	float RandomRecoilYaw;

	void StartRecoilTimer();

	void GenerateYawAmount();

	UFUNCTION()
	void Recoil();

	void StopRecoilTimer();

	void StartRecoverTimer();

	UFUNCTION()
	void Recover();

	void StopRecoverTimer();

	void WeaponCameraShake();

public:

	URecoil();

	// Camera shake
	UPROPERTY(EditAnywhere, Category = "Camera Shake")
	TSubclassOf<UCameraShake> CameraShake;

	UPROPERTY(EditAnywhere, Category = "Recoil")
	APawn* Pawn;

	UPROPERTY(EditAnywhere)
	float RecoilStrength = 0.5f;

	UPROPERTY(EditAnywhere)
	int RecoilSteps = 10.0f;

	UPROPERTY(EditAnywhere)
	float RandomRecoilYawMin = -0.3f;

	UPROPERTY(EditAnywhere)
	float RandomRecoilYawMax = 0.3f;

	UPROPERTY(EditAnywhere, Category = "Recoil & Recover")
	float Smoothness = 0.01f;

	UPROPERTY(EditAnywhere, Category = "Recover")
	float RecoverStrength = 0.25f;

	UPROPERTY(EditAnywhere, Category = "Recover")
	int RecoverSteps = 10.0f;

	UFUNCTION(BlueprintCallable)
	void SetPawn(APawn* InPawn);

	UFUNCTION(BlueprintCallable)
	void SetCameraShake(TSubclassOf<UCameraShake> InCameraShake);

	UFUNCTION(BlueprintCallable)
	void Execute();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
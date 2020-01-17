// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine/EngineTypes.h"
#include "Recoil.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API URecoil : public UActorComponent
{
	GENERATED_BODY()

	DECLARE_DELEGATE_OneParam(TimerDelegate, APawn*)

private:

	FTimerHandle RecoilTimerHandle;
	FTimerHandle RecoverTimerHandle;

	int InitialRecoilSteps;
	int InitialRecoverSteps;

	float RandomRecoilYaw;

public:

	// Sets default values for this component's properties
	URecoil();

	UPROPERTY(EditAnywhere, Category = "Recoil")
	float RecoilStrength = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Recoil")
	int RecoilSteps = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Recoil & Recover")
	float Smoothness = 0.01f;

	UPROPERTY(EditAnywhere, Category = "Recover")
	float RecoverStrength = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Recover")
	int RecoverSteps = 10.0f;

	//Random Yaw
	UPROPERTY(EditAnywhere, Category = "Random Yaw")
	float RandomRecoilYawMin = -0.3f;
	
	UPROPERTY(EditAnywhere, Category = "Random Yaw")
	float RandomRecoilYawMax = 0.3f;

	// Recoil
	UFUNCTION(BlueprintCallable)
	void StartRecoilTimer(APawn* Actor);

	UFUNCTION()
	void Recoil(APawn* Actor);

	void StopRecoilTimer();

	// Recover
	void StartRecoverTimer(APawn* Actor);

	UFUNCTION()
	void Recover(APawn* Actor);

	void StopRecoverTimer();

protected:

	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
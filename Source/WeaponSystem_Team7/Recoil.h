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

	FTimerHandle TimerHandle;

public:	
	// Sets default values for this component's properties
	URecoil();

	UPROPERTY(EditAnywhere)
	float RecoilStrength = 0.5f;

	UPROPERTY(EditAnywhere)
	float RecoilRecovery = 0.1f;;

	UPROPERTY(EditAnywhere)
	float Smoothness = 0.01f;;

	UPROPERTY(EditAnywhere)
	int RecoilSteps = 10.0f;;

	int InitialRecoilSteps = RecoilSteps;

	UFUNCTION(BlueprintCallable)
	void StartRecoilTimer(APawn* Actor);

	UFUNCTION()
	void Recoil(APawn* Actor);

	void StopRecoilTimer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};

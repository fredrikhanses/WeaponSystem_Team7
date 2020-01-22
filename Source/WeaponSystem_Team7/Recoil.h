#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine/EngineTypes.h"
#include "ModuleBase.h"
#include <Camera/CameraShake.h>
#include <Engine/World.h>
#include <Templates/SubclassOf.h>
#include "Recoil.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API URecoil : public UModuleBase
{
	GENERATED_BODY()

private:

	UWorld* World;
	FTimerHandle TimerHandle;
	int InitialRecoilSteps;
	int InitialRecoverSteps;
	float RandomRecoilYaw;

public:
	
	UPROPERTY(EditAnywhere, Category = CameraShake)
	TSubclassOf<UCameraShake> CameraShake;

	UPROPERTY(EditAnywhere, Category = Recoil)
	APawn* Pawn;

	UPROPERTY(EditAnywhere, Category = Recoil)
	float RecoilStrength = 0.1f;

	UPROPERTY(EditAnywhere, Category = Recoil)
	int RecoilSteps = 10.0f;

	UPROPERTY(EditAnywhere, Category = Recoil)
	float RandomRecoilYawLeftMax = 0.1f;

	UPROPERTY(EditAnywhere, Category = Recoil)
	float RandomRecoilYawRightMax = 0.1f;

	UPROPERTY(EditAnywhere, Category = RecoilRecover)
	float Smoothness = 0.01f;

	UPROPERTY(EditAnywhere, Category = Recover)
	float RecoverStrength = 0.1f;

	UPROPERTY(EditAnywhere, Category = Recover)
	int RecoverSteps = 10.0f;

private:

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

protected:

	virtual void BeginPlay() override;

public:

	URecoil();

	UFUNCTION(BlueprintCallable)
	void SetPawn(APawn* InPawn);

	UFUNCTION(BlueprintCallable)
	void SetCameraShake(TSubclassOf<UCameraShake> InCameraShake);

	UFUNCTION(BlueprintCallable)
	void Execute();

};
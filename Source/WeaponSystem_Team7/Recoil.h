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

	/**
	* Stores a reference to the world
	*/
	UWorld* World;

	/**
	* Default Timer Handle
	*/
	FTimerHandle TimerHandle;

	/**
	* Stores the original recoil steps
	*/
	int InitialRecoilSteps;

	/**
	* Stores the original recover steps
	*/
	int InitialRecoverSteps;

	/**
	* Stores the random recoil yaw amount
	*/
	float RandomRecoilYaw;

public:
	
	/**
	* Stores the camera shake component
	*/
	UPROPERTY(EditAnywhere, Category = CameraShake)
	TSubclassOf<UCameraShake> CameraShake;

	/**
	* Stores the Pawn to apply recoil on
	*/
	UPROPERTY(EditAnywhere, Category = Recoil)
	APawn* Pawn;

	/**
	* How much to recoil each step
	*/
	UPROPERTY(EditAnywhere, Category = Recoil)
	float RecoilStrength = 0.1f;

	/**
	* How many times the recoil timer will play
	*/
	UPROPERTY(EditAnywhere, Category = Recoil)
	int RecoilSteps = 10.0f;

	/**
	* Maximum yaw amount to the left
	*/
	UPROPERTY(EditAnywhere, Category = Recoil)
	float RecoilYawLeftMax = 0.1f;

	/**
	* Maximum yaw amount to the right
	*/
	UPROPERTY(EditAnywhere, Category = Recoil)
	float RecoilYawRightMax = 0.1f;

	/**
	* Time interval between changes to recoil and recover
	*/
	UPROPERTY(EditAnywhere, Category = RecoilAndRecover)
	float Smoothness = 0.01f;

	/**
	* How much to recover each step
	*/
	UPROPERTY(EditAnywhere, Category = Recover)
	float RecoverStrength = 0.1f;

	/**
	* How many times the recover timer will play
	*/
	UPROPERTY(EditAnywhere, Category = Recover)
	int RecoverSteps = 10.0f;

private:

	/**
	* Starts the recoil timer
	*/
	void StartRecoilTimer();

	/**
	* Generates a random yaw amount
	*/
	void GenerateYawAmount();

	/**
	* Recoil upwards in several small steps
	*/
	UFUNCTION()
	void Recoil();

	/**
	* Stops the recoil timer
	*/
	void StopRecoilTimer();

	/**
	* Starts the recover timer
	*/
	void StartRecoverTimer();

	/**
	* Recover downwards from recoil in several small steps
	*/
	UFUNCTION()
	void Recover();

	/**
	* Stops the recover timer
	*/
	void StopRecoverTimer();

	/**
	* Play Camera Shake
	*/
	void WeaponCameraShake();

protected:

	virtual void BeginPlay() override;

public:

	/**
	* Default constructor
	*/
	URecoil();

	/**
	* Sets which Pawn to apply recoil on
	*/
	UFUNCTION(BlueprintCallable)
	void SetPawn(APawn* InPawn);

	/**
	* Sets which camera shake blueprint to use
	*/
	UFUNCTION(BlueprintCallable)
	void SetCameraShake(TSubclassOf<UCameraShake> InCameraShake);

	/**
	* Inherited function that executes the main function of the class
	*/
	UFUNCTION(BlueprintCallable)
	virtual void Execute() override;

};
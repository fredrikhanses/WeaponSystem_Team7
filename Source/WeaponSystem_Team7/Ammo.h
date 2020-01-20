// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ModuleBase.h"
#include "Ammo.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API UAmmo : public UModuleBase
{
	GENERATED_BODY()

private:
	
	float OriginalClipSize;

public:	

	UAmmo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int MaxAmmo = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int SurplusAmmo = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int CurrentAmmo = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int ClipSize = 10;

	UFUNCTION(BlueprintCallable)
	void Reload();

	UFUNCTION(BlueprintCallable)
	void UseAmmo();

	UFUNCTION(BlueprintCallable)
	bool CheckAmmo();

	UFUNCTION(BlueprintCallable)
	void Execute();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};

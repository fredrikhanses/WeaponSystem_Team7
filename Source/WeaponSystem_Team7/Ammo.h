// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Ammo.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API UAmmo : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAmmo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int maxAmmo = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int surplusAmmo = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int currentAmmo = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int clipSize = 10;

	UFUNCTION(BlueprintCallable)
	void Reload();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

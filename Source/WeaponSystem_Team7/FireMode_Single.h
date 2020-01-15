// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FireMode_Single.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API UFireMode_Single : public UActorComponent
{
	GENERATED_BODY()

private:

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties")
		float Spread;
public:	
	// Sets default values for this component's properties
	UFireMode_Single();

	void Fire();

	void LineTrace();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

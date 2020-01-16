// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Camera/CameraComponent.h>
#include "Zoom.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API UZoom : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UZoom();

	UFUNCTION(BlueprintCallable)
	void ZoomToggle(UCameraComponent* Camera,float DefaultFieldOfView, float ZoomAmount);

private:
	bool bZooming = false;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};

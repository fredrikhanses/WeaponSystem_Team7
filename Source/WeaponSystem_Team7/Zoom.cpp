// Fill out your copyright notice in the Description page of Project Settings.


#include "Zoom.h"
#include <Engine/Engine.h>
#include <Camera/CameraComponent.h>

// Sets default values for this component's properties
UZoom::UZoom()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UZoom::ZoomToggle(UCameraComponent* Camera, float ZoomAmount)
{
	bZooming ? bZooming = false : bZooming = true;

	if (bZooming)
	{
		GEngine->AddOnScreenDebugMessage(-2, 1.f, FColor::Orange, "Zooming");
		Camera->FieldOfView = ZoomAmount;

	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-2, 1.f, FColor::Orange, "UnZooming");

		
	}

}

// Called when the game starts
void UZoom::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UZoom::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}


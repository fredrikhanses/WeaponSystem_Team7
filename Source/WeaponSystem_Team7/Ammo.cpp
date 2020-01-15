// Fill out your copyright notice in the Description page of Project Settings.


#include "Ammo.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UAmmo::UAmmo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UAmmo::Reload()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Ammo Surplus");
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::FromInt((int32)maxAmmo));
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Current Ammo");
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::FromInt((int32)currentAmmo));

	maxAmmo -= clipSize;
	maxAmmo += currentAmmo;
	currentAmmo = clipSize;

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Ammo Surplus");
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, FString::FromInt((int32)maxAmmo));
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Current Ammo");
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, FString::FromInt((int32)currentAmmo));
}

// Called when the game starts
void UAmmo::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAmmo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


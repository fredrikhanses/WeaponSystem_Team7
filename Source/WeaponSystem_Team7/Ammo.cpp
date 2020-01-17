// Fill out your copyright notice in the Description page of Project Settings.


#include "Ammo.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UAmmo::UAmmo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	OriginalClipSize = ClipSize;
}

void UAmmo::Reload()
{
	if (SurplusAmmo > 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Ammo Surplus");
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::FromInt((int32)SurplusAmmo));
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Current Ammo");
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::FromInt((int32)CurrentAmmo));

		SurplusAmmo -= ClipSize;
		if (SurplusAmmo < 0)
		{
			SurplusAmmo = 0;
		}
		SurplusAmmo += CurrentAmmo;
		CurrentAmmo = ClipSize;

		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Ammo Surplus");
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, FString::FromInt((int32)SurplusAmmo));
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Current Ammo");
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, FString::FromInt((int32)CurrentAmmo));
	}
}

void UAmmo::UseAmmo()
{
	if (CurrentAmmo > 0)
	{
		CurrentAmmo--;
	}
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


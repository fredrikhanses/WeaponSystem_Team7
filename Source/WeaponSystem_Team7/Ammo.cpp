// Fill out your copyright notice in the Description page of Project Settings.


#include "Ammo.h"
#include "Engine/Engine.h"

UAmmo::UAmmo()
{
	PrimaryComponentTick.bCanEverTick = true;
	OriginalClipSize = ClipSize;
}

void UAmmo::Reload()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Ammo Surplus");
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::FromInt((int32)SurplusAmmo));
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Current Ammo");
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::FromInt((int32)CurrentAmmo));

	if (SurplusAmmo > 0)
	{
		SurplusAmmo -= ClipSize;

		if (SurplusAmmo < 0)
		{
			ClipSize =- SurplusAmmo;
			SurplusAmmo = 0;
		}

		SurplusAmmo += CurrentAmmo;
		CurrentAmmo = ClipSize;
		ClipSize = OriginalClipSize;
	}

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Ammo Surplus");
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, FString::FromInt((int32)SurplusAmmo));
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Current Ammo");
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, FString::FromInt((int32)CurrentAmmo));
}

void UAmmo::UseAmmo()
{
	if (CurrentAmmo > 0)
	{
		CurrentAmmo--;
	}
}

bool UAmmo::CheckAmmo()
{
	if (CurrentAmmo > 0)
	{
		return true;
	}
	return false;
}

void UAmmo::Execute()
{
	if (CheckAmmo())
	{
		UseAmmo();
	}
}

void UAmmo::BeginPlay()
{
	Super::BeginPlay();	
}

void UAmmo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
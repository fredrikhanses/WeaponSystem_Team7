#include "Ammo.h"
#include "Engine/Engine.h"

UAmmo::UAmmo()
{
}

void UAmmo::BeginPlay()
{
	Super::BeginPlay();
	OriginalClipSize = ClipSize;
}

void UAmmo::Execute()
{
	if (CheckAmmo())
	{
		UseAmmo();
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

void UAmmo::UseAmmo()
{
	if (CurrentAmmo > 0)
	{
		CurrentAmmo--;
	}
}

void UAmmo::Reload()
{
	/*GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Ammo Surplus");
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::FromInt((int32)SurplusAmmo));
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Current Ammo");
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::FromInt((int32)CurrentAmmo));*/

	if (SurplusAmmo > 0)
	{
		ClipSize -= CurrentAmmo;
		SurplusAmmo -= ClipSize;
		if (SurplusAmmo < 0)
		{
			ClipSize =- SurplusAmmo;
			SurplusAmmo = 0;
		}
		CurrentAmmo += ClipSize;
		ClipSize = OriginalClipSize;
	}

	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Ammo Surplus");
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, FString::FromInt((int32)SurplusAmmo));
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, "Current Ammo");
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, FString::FromInt((int32)CurrentAmmo));
}

int UAmmo::GetCurrentAmmo()
{
	return CurrentAmmo;
}

int UAmmo::GetSurplusAmmo()
{
	return SurplusAmmo;
}
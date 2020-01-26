#include "Ammo.h"

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
	UseAmmo();
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
	if (CheckAmmo())
	{
		CurrentAmmo--;
	}
}

void UAmmo::Reload()
{
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
}

int UAmmo::GetCurrentAmmo()
{
	return CurrentAmmo;
}

int UAmmo::GetSurplusAmmo()
{
	return SurplusAmmo;
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "Fire.h"
#include <Engine/Engine.h>

UFire::UFire()
{

}

void UFire::BeginPlay()
{
	Super::BeginPlay();

	InitialBurstCount = BurstCount;
	bCanFire = true;



	//Prevents parameters from being 0
	if (BurstCount < 1)
	{
		BurstCount = 1;
	}

	if (BurstDelay < 0.01f)
	{
		BurstDelay = 0.01f;
	}

	if (FireRate < 0.01f)
	{
		FireRate = 0.01f;
	}
}

void UFire::Execute()
{

}

void UFire::OnFire(TArray<UModuleBase*> ModuleArray)
{
	if (Array.Num() == 0)
	{
		Array = ModuleArray;
	}

	for (auto modules : Array)
	{
		if (UAmmo* TempAmmo = Cast<UAmmo>(modules))
		{
			Ammo = TempAmmo;
			CurrentAmmo = Ammo->CurrentAmmo;
		}
	}

	if (bAutomaticWeapon)
	{
		GetWorld()->GetTimerManager().SetTimer(AutofireTimerHandle, this, &UFire::Autofire, FireRate, bAutofire);
	}
	else
	{
		Instant_Fire();
	}
}

void UFire::StartFire()
{
	if (BurstCount > 0)
	{
		for (auto modules : Array)
		{
			modules->Execute();
		}
	}

	if (--BurstCount < 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(BurstTimerHandle);
		BurstCount = InitialBurstCount;
		GetWorld()->GetTimerManager().SetTimer(FireDelayTimerHandle, this, &UFire::ResetFire, FireRate, false);
	}
}

void UFire::ResetFire()
{
	bCanFire = true;
	GetWorld()->GetTimerManager().ClearTimer(FireDelayTimerHandle);
}

void UFire::Instant_Fire()
{
	if (bCanFire)
	{
		for (auto modules : Array)
		{
			modules->Execute();
		}

		--BurstCount;

		GetWorld()->GetTimerManager().SetTimer(BurstTimerHandle, this, &UFire::StartFire, BurstDelay, true);

		bCanFire = false;
	}
}

void UFire::Autofire()
{
	for (auto modules : Array)
	{
		modules->Execute();
	}

	if (Ammo)
	{
		CurrentAmmo--;
	}

	if (CurrentAmmo<=0)
	{
		bAutofire = false;
	}

	if (bAutofire == false)
	{
		GetWorld()->GetTimerManager().ClearTimer(AutofireTimerHandle);
	}
}


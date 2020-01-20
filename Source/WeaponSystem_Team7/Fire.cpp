// Fill out your copyright notice in the Description page of Project Settings.


#include "Fire.h"

UFire::UFire()
{

}

void UFire::BeginPlay()
{
	Super::BeginPlay();

	InitialBurstCount = BurstCount;
	bCanFire = true;
}

void UFire::OnFire(TArray<UModuleBase*> ModuleArray)
{
	Array = ModuleArray;

	if (bCanFire)
	{
		GetWorld()->GetTimerManager().SetTimer(BurstTimerHandle, this, &UFire::StartFire, BurstDelay, true);

		bCanFire = false;
	}
}

void UFire::Execute()
{
}


void UFire::StartFire()
{
	if (--BurstCount <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(BurstTimerHandle);
		BurstCount = InitialBurstCount;
		GetWorld()->GetTimerManager().SetTimer(FireDelayTimerHandle, this, &UFire::ResetFire, FireRate, false);
	}

	for (auto modules : Array)
	{
		modules->Execute();
	}
}

void UFire::ResetFire()
{
	bCanFire = true;
	GetWorld()->GetTimerManager().ClearTimer(FireDelayTimerHandle);
}


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


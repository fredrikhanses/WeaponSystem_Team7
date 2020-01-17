// Fill out your copyright notice in the Description page of Project Settings.

#include "Recoil.h"
#include "Engine/World.h"

// Sets default values for this component's properties
URecoil::URecoil()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	InitialRecoilSteps = RecoilSteps;
	InitialRecoverSteps = RecoverSteps;
}

void URecoil::StartRecoilTimer(APawn* Actor)
{
	RandomRecoilYaw = FMath::RandRange(RandomRecoilYawMin, RandomRecoilYawMax);

	FTimerDelegate RecoilDelegate;

	RecoilDelegate.BindUFunction(this, FName("Recoil"), Actor);

	GetWorld()->GetTimerManager().SetTimer(RecoilTimerHandle, RecoilDelegate, Smoothness, true);
}

void URecoil::Recoil(APawn* Actor)
{
	if (--RecoilSteps <= 0)
	{
		StopRecoilTimer();

		StartRecoverTimer(Actor);
	}

	Actor->AddControllerPitchInput(-1 * RecoilStrength);
	Actor->AddControllerYawInput(-1 * RandomRecoilYaw);
}

void URecoil::StopRecoilTimer()
{
	RecoilSteps = InitialRecoilSteps;
	GetWorld()->GetTimerManager().ClearTimer(RecoilTimerHandle);
}

void URecoil::StartRecoverTimer(APawn* Actor)
{
	FTimerDelegate RecoverDelegate;

	RecoverDelegate.BindUFunction(this, FName("Recover"), Actor);

	GetWorld()->GetTimerManager().SetTimer(RecoverTimerHandle, RecoverDelegate, Smoothness, true);
}

void URecoil::Recover(APawn* Actor)
{
	if (--RecoverSteps <= 0)
	{
		StopRecoverTimer();
	}

	Actor->AddControllerPitchInput(RecoverStrength);
}

void URecoil::StopRecoverTimer()
{
	RecoverSteps = InitialRecoverSteps;
	GetWorld()->GetTimerManager().ClearTimer(RecoverTimerHandle);
}

// Called when the game starts
void URecoil::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void URecoil::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "Recoil.h"
#include "Engine/World.h"

URecoil::URecoil()
{
	PrimaryComponentTick.bCanEverTick = true;

	InitialRecoilSteps = RecoilSteps;
	InitialRecoverSteps = RecoverSteps;
}

void URecoil::StartRecoilTimer()
{
	if (Pawn)
	{
		GenerateYawAmount();

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &URecoil::Recoil, Smoothness, true);
	}
}

void URecoil::GenerateYawAmount()
{
	RandomRecoilYaw = FMath::RandRange(RandomRecoilYawMin, RandomRecoilYawMax);
}

void URecoil::SetPawn(APawn* InPawn)
{
	Pawn = InPawn;
}

void URecoil::Recoil()
{
	if (--RecoilSteps <= 0)
	{
		StopRecoilTimer();
		StartRecoverTimer();
	}
	Pawn->AddControllerPitchInput(-1 * RecoilStrength);
	Pawn->AddControllerYawInput(-1 * RandomRecoilYaw);
}

void URecoil::StopRecoilTimer()
{
	RecoilSteps = InitialRecoilSteps;
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void URecoil::StartRecoverTimer()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &URecoil::Recover, Smoothness, true);
}

void URecoil::Recover()
{
	if (--RecoverSteps <= 0)
	{
		StopRecoverTimer();
	}
	Pawn->AddControllerPitchInput(RecoverStrength);
}

void URecoil::StopRecoverTimer()
{
	RecoverSteps = InitialRecoverSteps;
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void URecoil::Execute()
{
	StartRecoilTimer();
}

void URecoil::BeginPlay()
{
	Super::BeginPlay();
}

void URecoil::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
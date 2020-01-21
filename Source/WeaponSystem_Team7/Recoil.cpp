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
	if (Pawn != nullptr)
	{
		GenerateYawAmount();
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &URecoil::Recoil, Smoothness, true);
	}
}

void URecoil::GenerateYawAmount()
{
	RandomRecoilYaw = FMath::RandRange(-1 * RandomRecoilYawLeftMax, RandomRecoilYawRightMax);
}

void URecoil::SetPawn(APawn* InPawn)
{
	Pawn = InPawn;
}

void URecoil::SetCameraShake(TSubclassOf<UCameraShake> InCameraShake)
{
	CameraShake = InCameraShake;
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

void URecoil::WeaponCameraShake()
{
	if (CameraShake != nullptr)
	{
		GetWorld()->GetFirstPlayerController()->PlayerCameraManager->PlayCameraShake(CameraShake, 1.0f);
	}
}

void URecoil::Execute()
{
	StartRecoilTimer();
	WeaponCameraShake();
}

void URecoil::BeginPlay()
{
	Super::BeginPlay();
}

void URecoil::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
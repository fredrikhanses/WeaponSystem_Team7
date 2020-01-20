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

void URecoil::StartRecoilTimer(APawn* Pawn)
{
	RandomRecoilYaw = FMath::RandRange(RandomRecoilYawMin, RandomRecoilYawMax);

	FTimerDelegate RecoilDelegate;

	RecoilDelegate.BindUFunction(this, FName("Recoil"), Pawn);

	GetWorld()->GetTimerManager().SetTimer(RecoilTimerHandle, RecoilDelegate, Smoothness, true);
}

void URecoil::Recoil(APawn* Pawn)
{
	if (--RecoilSteps <= 0)
	{
		StopRecoilTimer();

		StartRecoverTimer(Pawn);
	}

	Pawn->AddControllerPitchInput(-1 * RecoilStrength);
	Pawn->AddControllerYawInput(-1 * RandomRecoilYaw);
}

void URecoil::StopRecoilTimer()
{
	RecoilSteps = InitialRecoilSteps;
	GetWorld()->GetTimerManager().ClearTimer(RecoilTimerHandle);
}

void URecoil::StartRecoverTimer(APawn* Pawn)
{
	FTimerDelegate RecoverDelegate;

	RecoverDelegate.BindUFunction(this, FName("Recover"), Pawn);

	GetWorld()->GetTimerManager().SetTimer(RecoverTimerHandle, RecoverDelegate, Smoothness, true);
}

void URecoil::Recover(APawn* Pawn)
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
	GetWorld()->GetTimerManager().ClearTimer(RecoverTimerHandle);
}

void URecoil::Execute(APawn* Pawn)
{
	StartRecoilTimer(Pawn);
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
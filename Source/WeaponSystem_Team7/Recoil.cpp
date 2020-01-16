// Fill out your copyright notice in the Description page of Project Settings.


#include "Recoil.h"
#include "Engine/World.h"

// Sets default values for this component's properties
URecoil::URecoil()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void URecoil::StartRecoilTimer(APawn* Actor)
{
	FTimerDelegate TimerDelegate;

	TimerDelegate.BindUFunction(this, FName("Recoil"), Actor);

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, Smoothness, true);
}

void URecoil::Recoil(APawn* Actor)
{
	if (--RecoilSteps <= 0)
	{
		StopRecoilTimer();
	}

	Actor->AddControllerPitchInput(-1 * RecoilStrength);
}

void URecoil::StopRecoilTimer()
{
	RecoilSteps = InitialRecoilSteps;
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
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


// Fill out your copyright notice in the Description page of Project Settings.


#include "FireMode_Single.h"

// Sets default values for this component's properties
UFireMode_Single::UFireMode_Single()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UFireMode_Single::Fire()
{
}

void UFireMode_Single::LineTrace()
{


}


// Called when the game starts
void UFireMode_Single::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFireMode_Single::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "SFX.h"
#include <Kismet/GameplayStatics.h>
#include <Engine/Engine.h>

USFX::USFX()
{

}

void USFX::BeginPlay()
{
	Super::BeginPlay();

	Weapon = Cast<AWeapon>(GetOwner());
}

void USFX::Execute()
{
	OnFire();
}

void USFX::OnFire()
{
	if (FireSound == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "You need to set a Sound!");
	}
	else
	{
		CreateSound();
	}
}

void USFX::CreateSound()
{
	// try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, Weapon->Mesh->GetSocketLocation("Muzzle"));
	}
}
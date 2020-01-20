// Fill out your copyright notice in the Description page of Project Settings.


#include "VFX.h"
#include <Kismet/GameplayStatics.h>

UVFX::UVFX()
{
}

void UVFX::BeginPlay()
{
	Super::BeginPlay();

	Weapon = Cast<AWeapon>(GetOwner());
}

void UVFX::Execute()
{
	OnFire();
}

void UVFX::OnFire()
{
	CreateVFX();
}

void UVFX::CreateVFX()
{
	FVector SpawnLocation = Weapon->Mesh->GetSocketLocation("Muzzle");
	FRotator SpawnRotation = Weapon->Mesh->GetSocketRotation("Muzzle");

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), EmitterTemplate, SpawnLocation, SpawnRotation, Scale);
}
#include "VFX.h"
#include <Kismet/GameplayStatics.h>
#include <Engine/Engine.h>

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
	if (EmitterTemplate==nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "You need to set a VFX!");
	}
	else
	{
		CreateVFX();
	}
}

void UVFX::CreateVFX()
{
	FVector SpawnLocation = Weapon->Mesh->GetSocketLocation("Muzzle");
	FRotator SpawnRotation = Weapon->Mesh->GetSocketRotation("Muzzle");

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), EmitterTemplate, SpawnLocation, SpawnRotation, Scale);
}
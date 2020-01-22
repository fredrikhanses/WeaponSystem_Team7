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
	if (FireSoundCue == nullptr)
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
	FireSoundCue->VolumeMultiplier = FMath::FRandRange(Volume-VolumeRangeMin, Volume + VolumeRangeMax);
	FireSoundCue->PitchMultiplier = FMath::FRandRange(Pitch - PitchRangeMin, Pitch + PitchMRangeMax);

	// try and play the sound if specified
	if (FireSoundCue != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSoundCue, Weapon->Mesh->GetSocketLocation("Muzzle"));
	}
}
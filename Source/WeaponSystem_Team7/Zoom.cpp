#include "Zoom.h"
#include <Engine/Engine.h>
#include "Components/SkeletalMeshComponent.h"
#include <Kismet/GameplayStatics.h>


UZoom::UZoom()
{
}

void UZoom::ZoomToggle(UCameraComponent* Camera, float ScopeZoomMultiplyer, bool bWeaponHasScope)
{
	InitCamera = Camera;
	ZoomMultiplyer = ScopeZoomMultiplyer;

	if (bWeaponHasScope) { bUsingZooming = true; }

	Weapon = Cast<AWeapon>(GetOwner());
	Controller = UGameplayStatics::GetPlayerController(this, 0);

	bZooming ? bZooming = false : bZooming = true;

	if (bZooming)
	{
		GetWorld()->GetTimerManager().SetTimer(ZoomBreakTimerHandle, this, &UZoom::ZoomBreak, 0.05f, true);

		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Scoping");
		if (bUsingZooming)
		{
			// Show HUD graphic (like a scope) For example.

			Weapon->ADSCam->FieldOfView /= ScopeZoomMultiplyer;
		}
		Controller->SetViewTargetWithBlend(Weapon->ADSCam->GetOwner(), 0.1f);
	}
	else if (!bZooming)
	{
		GetWorld()->GetTimerManager().ClearTimer(ZoomBreakTimerHandle);

		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Not Scoping");
		if (bUsingZooming)
		{
			Weapon->ADSCam->FieldOfView *= ScopeZoomMultiplyer;
		}
		Controller->SetViewTargetWithBlend(Camera->GetOwner(), 0.1f);
	}
}

void UZoom::ZoomBreak()
{
	if (!Weapon->bIsEquipped)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Not Scoping");

		bZooming ? bZooming = false : bZooming = true;

		if (bUsingZooming)
		{
			Weapon->ADSCam->FieldOfView *= ZoomMultiplyer;
		}

		Controller->SetViewTargetWithBlend(InitCamera->GetOwner(), 0.1f);
		GetWorld()->GetTimerManager().ClearTimer(ZoomBreakTimerHandle);
	}
}
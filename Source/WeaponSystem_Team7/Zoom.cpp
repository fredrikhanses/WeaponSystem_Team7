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
	else if (!bWeaponHasScope) { bUsingAimDownSight = true; }
	
	Weapon = Cast<AWeapon>(GetOwner());
	Controller = UGameplayStatics::GetPlayerController(this, 0);



	// Separated Zooming/ADS so that we could build upon this to use different scopes maybe etc.
	if (bUsingZooming)
	{
		bZooming ? bZooming = false : bZooming = true;

		if (bZooming)
		{
			GetWorld()->GetTimerManager().SetTimer(ZoomBreakTimerHandle, this, &UZoom::ZoomBreak, 0.05f, true);

			// Show HUD graphic (like a scope) For example.

			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Scoping");
			Weapon->ADSCam->FieldOfView /= ScopeZoomMultiplyer;
			Controller->SetViewTargetWithBlend(Weapon->ADSCam->GetOwner(), 0.1f);

		}
		else if (!bZooming)
		{
			GetWorld()->GetTimerManager().ClearTimer(ZoomBreakTimerHandle);

			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Not Scoping");
			Weapon->ADSCam->FieldOfView *= ScopeZoomMultiplyer;
			Controller->SetViewTargetWithBlend(Camera->GetOwner(), 0.1f);
		}		
	}

	// ADS
	if (bUsingAimDownSight)
	{
		bAimDownSight ? bAimDownSight = false : bAimDownSight = true;		

		if (bAimDownSight)
		{
			GetWorld()->GetTimerManager().SetTimer(ZoomBreakTimerHandle, this, &UZoom::ZoomBreak, 0.05f, true);

			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "ADSing");
			Controller->SetViewTargetWithBlend(Weapon->ADSCam->GetOwner(), 0.1f);
		}
		else if (!bAimDownSight)
		{
			GetWorld()->GetTimerManager().ClearTimer(ZoomBreakTimerHandle);

			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Not ADSing");
			Controller->SetViewTargetWithBlend(Camera->GetOwner(), 0.1f);
		}
	}
}

void UZoom::ZoomBreak()
{
	if (!Weapon->bIsEquipped)
	{

		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Not Scoping");
		if (bUsingZooming)
		{
			bZooming ? bZooming = false : bZooming = true;
			Weapon->ADSCam->FieldOfView *= ZoomMultiplyer;
		}

		if (bUsingAimDownSight)
		{
			bAimDownSight ? bAimDownSight = false : bAimDownSight = true;
		}
		Controller->SetViewTargetWithBlend(InitCamera->GetOwner(), 0.1f);

		GetWorld()->GetTimerManager().ClearTimer(ZoomBreakTimerHandle);
	}
}
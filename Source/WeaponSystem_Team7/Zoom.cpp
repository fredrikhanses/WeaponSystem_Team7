#include "Zoom.h"
#include <Engine/Engine.h>
#include "Components/SkeletalMeshComponent.h"
#include "Weapon.h"
#include <Camera/CameraComponent.h>
#include <Kismet/GameplayStatics.h>
#include <GameFramework/PlayerController.h>

UZoom::UZoom()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UZoom::ZoomToggle(UCameraComponent* Camera, float ScopeZoomMultiplyer, bool bWeaponHasScope)
{
	if (bWeaponHasScope) { bUsingZooming = true; }
	else if (!bWeaponHasScope) { bUsingAimDownSight = true; }
	
	AWeapon* Weapon = Cast<AWeapon>(GetOwner());		
	APlayerController* Controller = UGameplayStatics::GetPlayerController(this, 0);

	// Separated Zooming/ADS so that we could build upon this to use different scopes maybe etc.
	if (bUsingZooming)
	{
		bZooming ? bZooming = false : bZooming = true;

		if (bZooming)
		{
			// Show HUD graphic (like a scope) For example.

			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Scoping");
			Weapon->ADSCam->FieldOfView /= ScopeZoomMultiplyer;
			Controller->SetViewTargetWithBlend(Weapon->ADSCam->GetOwner(), 0.1f);
			
		}
		else if (!bZooming)
		{
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
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "ADSing");
			Controller->SetViewTargetWithBlend(Weapon->ADSCam->GetOwner(), 0.1f);
		}
		else if (!bAimDownSight)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Not ADSing");
			Controller->SetViewTargetWithBlend(Camera->GetOwner(), 0.1f);
		}
	}
}
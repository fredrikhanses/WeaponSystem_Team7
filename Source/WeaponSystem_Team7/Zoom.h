#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraComponent.h"
#include "Weapon.h"
#include <GameFramework/PlayerController.h>
#include "Zoom.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API UZoom : public UActorComponent
{
	GENERATED_BODY()

private:

	bool bZooming = false;

	bool bIsZoomed = false;
	
	bool bUsingZooming = false;

	FTimerHandle ZoomBreakTimerHandle;
	UCameraComponent* InitCamera;
	float ZoomMultiplyer;
	AWeapon* Weapon;
	APlayerController* Controller;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* ADSCam;

private:
	
	void ZoomBreak();

public:

	UZoom();

	/**
	 * Toggles ADS/Zoom. Check "Weapon has scope" to use the ScopeZoomMultiplyer (2.0 zooms the view x2 for example).
	 */
	UFUNCTION(BlueprintCallable)
	void ZoomToggle(UCameraComponent* Camera, float ScopeZoomMultiplyer, bool bWeaponHasScope);		
};
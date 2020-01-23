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
	bool bAimDownSight = false;

	bool bIsZoomed = false;
	
	bool bUsingZooming = false;
	bool bUsingAimDownSight = false;

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

	UFUNCTION(BlueprintCallable)
	void ZoomToggle(UCameraComponent* Camera, float ScopeZoomMultiplyer, bool bWeaponHasScope);		
};
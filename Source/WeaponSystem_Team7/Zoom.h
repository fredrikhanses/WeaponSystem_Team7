#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraComponent.h"
#include "Zoom.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API UZoom : public UActorComponent
{
	GENERATED_BODY()

public:
	UZoom();

	UFUNCTION(BlueprintCallable)
	void ZoomToggle(UCameraComponent* Camera, float ScopeZoomMultiplyer, bool bWeaponHasScope);		

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* ADSCam;

private:

	bool bZooming = false;
	bool bAimDownSight = false;	
	
	bool bUsingZooming = false;
	bool bUsingAimDownSight = false;

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;		
};

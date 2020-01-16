// Fill out your copyright notice in the Description page of Project Settings.


#include "Zoom.h"
#include <Engine/Engine.h>
#include "Components/SkeletalMeshComponent.h"
#include "Weapon.h"
#include <Camera/CameraComponent.h>
#include <Kismet/GameplayStatics.h>
#include <GameFramework/PlayerController.h>

// Sets default values for this component's properties
UZoom::UZoom()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	

	// ...
}


void UZoom::ZoomToggle(UCameraComponent* Camera, float ScopeZoomMultiplyer, float ZoomAmountADS, bool bWeaponHasScope)
{
	if (bWeaponHasScope) { bUsingZooming = true; }
	else if (!bWeaponHasScope) { bUsingAimDownSight = true; }
		
	if (bUsingZooming)
	{
		bZooming ? bZooming = false : bZooming = true;

		if (bZooming)
		{
			// Add scope widget to view port

			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Scoping");
			Camera->FieldOfView /= ScopeZoomMultiplyer;
		}
		else if (!bZooming)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Not Scoping");
			Camera->FieldOfView *= ScopeZoomMultiplyer;
		}
	}

	if (bUsingAimDownSight)
	{
		bAimDownSight ? bAimDownSight = false : bAimDownSight = true;

		AWeapon* Weapon = Cast<AWeapon>(GetOwner());
		
		APlayerController* Controller = UGameplayStatics::GetPlayerController(this, 0);

		if (bAimDownSight)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "ADSing");

			Controller->SetViewTargetWithBlend(Weapon->ADSCam->GetOwner(), 0.1f);
			Camera->FieldOfView -= ZoomAmountADS;
		}
		else if (!bAimDownSight)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Not ADSing");
			
			Controller->SetViewTargetWithBlend(Camera->GetOwner(), 0.1f);
			Camera->FieldOfView += ZoomAmountADS;
		}
	}
}

// Called when the game starts
void UZoom::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	
}


// Called every frame
void UZoom::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}


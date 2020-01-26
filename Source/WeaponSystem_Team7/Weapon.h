#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include <Components/SphereComponent.h>
#include <Components/PrimitiveComponent.h>
#include <Engine/EngineTypes.h>
#include "Ammo.h"
#include "UIColor.h"
#include "Weapon.generated.h"

class UCameraComponent;

UCLASS()
class WEAPONSYSTEM_TEAM7_API AWeapon : public AActor
{
	GENERATED_BODY()

private:

	/**
	* Used to store a ammo component
	* which can be used by the UI widget 
	*/
	UAmmo* Ammo;

	/**
	* Used to store a UI color component 
	* which can be used by the UI widget
	*/
	UUIColor* UIColor;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collider")
		USphereComponent* Collider;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
		USkeletalMeshComponent* Mesh;

	/**
	* Aim Down Sight Camera (for when using Zoom component)
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UCameraComponent* ADSCam;

	//Checks to see if Weapon is equipped.
	bool bIsEquipped = false;

public:

	// Sets default values for this actor's properties
	AWeapon();

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	/**
	* Creates a reference to a Ammo component if used. this is needed to show the ammo count in the HUD.
	*/
	UFUNCTION(BlueprintCallable)
		void SetAmmoComponent(UAmmo* InAmmo);

	/**
	* Creates a reference to a UI Color component if used. This is needed to show the color of the weapon in the HUD.
	*/
	UFUNCTION(BlueprintCallable)
		void SetUIColorComponent(UUIColor* InUIColor);

	/**
	* Gets the Ammo component. This only works if you have already set one with SetAmmoComponent.
	*/
	UFUNCTION(BlueprintCallable)
		UAmmo* GetAmmoComponent();

	/**
	* Gets the UI Color component. This only works if you have already set one with SetUIColorComponent.
	*/
	UFUNCTION(BlueprintCallable)
		UUIColor* GetUIColorComponent();
};

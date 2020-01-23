#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include <Components/SphereComponent.h>
#include <Components/PrimitiveComponent.h>
#include <Engine/EngineTypes.h>
#include "Weapon.generated.h"

class UCameraComponent;

UCLASS()
class WEAPONSYSTEM_TEAM7_API AWeapon : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collider")
		USphereComponent* Collider;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
		USkeletalMeshComponent* Mesh;

	// ADS Camera (for when using Zoom component)
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UCameraComponent* ADSCam;

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
};

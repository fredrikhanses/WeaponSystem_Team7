
// Fill out your copyright notice in the Description page of Project Settings.

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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Mesh")
		USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UCameraComponent* ADSCam;

	// Camera shake
	UPROPERTY(EditAnywhere)
		TSubclassOf<UCameraShake> CameraShake;

public:

	// Sets default values for this actor's properties
	AWeapon();

	UFUNCTION(BlueprintCallable)
		void WeaponCameraShake();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

};

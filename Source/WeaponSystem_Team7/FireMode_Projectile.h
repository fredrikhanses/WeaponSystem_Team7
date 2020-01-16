// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Weapon.h"
#include "WeaponSystem_Team7Projectile.h"
#include "FireMode_Projectile.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API UFireMode_Projectile : public UActorComponent
{
	GENERATED_BODY()

private:



public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Properties")
		float Spread;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Properties")
		TSubclassOf<AWeaponSystem_Team7Projectile> ProjectileClass;

private:

	void SpawnProjectile(AWeapon* Weapon);

public:	
	// Sets default values for this component's properties
	UFireMode_Projectile();

	UFUNCTION(BlueprintCallable)
	void Fire(AWeapon* Weapon);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

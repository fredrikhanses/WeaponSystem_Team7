// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Weapon.h"
#include <Engine/EngineTypes.h>
#include "FireMode_Single.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API UFireMode_Single : public UActorComponent
{
	GENERATED_BODY()

private:

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Spread;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float Range;

private:
	void Instant_Fire(AWeapon* Weapon);
	FHitResult LineTrace(AWeapon* Weapon,const FVector& TraceFrom, const FVector& TraceTo) const;
	void ProcessInstantHit(const FHitResult& Hit, const FVector& Origin, const FVector& ShootDir, int32 RandomSeed, float ReticleSpread, AWeapon* Weapon);

public:	
	// Sets default values for this component's properties
	UFireMode_Single();

	UFUNCTION(BlueprintCallable)
	void Fire(AWeapon* Weapon);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};

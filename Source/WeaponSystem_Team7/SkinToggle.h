// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include <Materials/Material.h>
#include <Components/SkeletalMeshComponent.h>
#include "SkinToggle.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API USkinToggle : public UModuleBase
{
	GENERATED_BODY()
	
private:

	USkeletalMeshComponent* Mesh;

public:

	UPROPERTY(EditAnywhere, Category = Material)
	UMaterial* Material;

	UPROPERTY(EditAnywhere, Category = Mesh)
	USkeletalMesh* SkeletalMesh;

protected:

	virtual void BeginPlay() override;

public:

	USkinToggle();

	virtual void Execute() override;

	UFUNCTION(BlueprintCallable)
	void SetMaterial(UMaterial* InMaterial);

	UFUNCTION(BlueprintCallable)
	void SetMesh(USkeletalMesh* InMesh);

	UFUNCTION(BlueprintCallable)
	void Toggle();

};

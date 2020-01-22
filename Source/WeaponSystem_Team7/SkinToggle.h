#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include "Weapon.h"
#include <Components/SkeletalMeshComponent.h>
#include <Engine/SkeletalMesh.h>
#include <Materials/Material.h>
#include "SkinToggle.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API USkinToggle : public UModuleBase
{
	GENERATED_BODY()
	
private:

	USkeletalMeshComponent* Mesh;
	AWeapon* WeaponMesh;

public:

	UPROPERTY(EditAnywhere, Category = Mesh)
	USkeletalMesh* SkeletalMesh;

	UPROPERTY(EditAnywhere, Category = Material)
	UMaterial* Material;

protected:

	virtual void BeginPlay() override;

public:

	USkinToggle();

	UFUNCTION(BlueprintCallable)
	void SetMaterial(UMaterial* InMaterial);

	UFUNCTION(BlueprintCallable)
	void SetMesh(USkeletalMesh* InMesh);

	virtual void Execute() override;

	UFUNCTION(BlueprintCallable)
	void Toggle();

};
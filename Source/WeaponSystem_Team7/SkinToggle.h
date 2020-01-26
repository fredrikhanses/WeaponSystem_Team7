#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include <Components/SkeletalMeshComponent.h>
#include <Engine/SkeletalMesh.h>
#include <Materials/Material.h>
#include "Weapon.h"
#include "SkinToggle.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API USkinToggle : public UModuleBase
{
	GENERATED_BODY()
	
private:

	/**
	* Used to store a reference to the weapon mesh
	*/
	USkeletalMeshComponent* Mesh;

	/**
	* Used to store a reference to the Weapon class
	*/
	AWeapon* Weapon;

public:

	/**
	* Used to store a reference to the skeletal mesh to change to
	*/
	UPROPERTY(EditAnywhere, Category = Mesh)
	USkeletalMesh* SkeletalMesh;

	/**
	* Used to store a reference to the material to change to
	*/
	UPROPERTY(EditAnywhere, Category = Material)
	UMaterial* Material;

protected:

	virtual void BeginPlay() override;

public:

	/**
	* Default constructor
	*/
	USkinToggle();

	/**
	* Sets the new mesh
	*/
	UFUNCTION(BlueprintCallable)
	void SetMesh(USkeletalMesh* InMesh);

	/**
	* Sets the new material
	*/
	UFUNCTION(BlueprintCallable)
	void SetMaterial(UMaterial* InMaterial);

	/**
	* Inherited function that executes the main function of the class
	*/
	UFUNCTION(BlueprintCallable)
	virtual void Execute() override;

	/**
	* Attaches the new material and new mesh
	*/
	UFUNCTION(BlueprintCallable)
	void Toggle();

};
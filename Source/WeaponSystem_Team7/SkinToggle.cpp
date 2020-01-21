// Fill out your copyright notice in the Description page of Project Settings.

#include "SkinToggle.h"
#include "Weapon.h"

USkinToggle::USkinToggle()
{
}

void USkinToggle::BeginPlay()
{
	Super::BeginPlay();
	AWeapon* Weapon = Cast<AWeapon>(GetOwner());
	Mesh = Weapon->Mesh;
}

void USkinToggle::Execute()
{
	Toggle();
}

void USkinToggle::SetMaterial(UMaterial* InMaterial)
{
	Material = InMaterial;
}

void USkinToggle::SetMesh(USkeletalMesh* InMesh)
{
	SkeletalMesh = InMesh;
}

void USkinToggle::Toggle()
{
	if (Mesh != nullptr && Material != nullptr)
	{
		Mesh->SetMaterial(0, Material);
	}

	if (Mesh != nullptr && SkeletalMesh != nullptr)
	{
		Mesh->SetSkeletalMesh(SkeletalMesh);
	}
}


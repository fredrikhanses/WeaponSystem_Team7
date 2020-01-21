// Fill out your copyright notice in the Description page of Project Settings.

#include "SkinToggle.h"

USkinToggle::USkinToggle()
{
}

void USkinToggle::Execute()
{
	Toggle();
}

void USkinToggle::SetMaterial(UMaterial* InMaterial)
{
	Material = InMaterial;
}

void USkinToggle::SetMesh(USkeletalMeshComponent* InMesh)
{
	Mesh = InMesh;
}

void USkinToggle::Toggle()
{
	if (Mesh != nullptr && Material != nullptr)
	{
		Mesh->SetMaterial(0, Material);
	}
}

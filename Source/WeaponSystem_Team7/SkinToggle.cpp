#include "SkinToggle.h"

USkinToggle::USkinToggle()
{
}

void USkinToggle::BeginPlay()
{
	Super::BeginPlay();
	WeaponMesh = Cast<AWeapon>(GetOwner());
	Mesh = WeaponMesh->Mesh;
}

void USkinToggle::SetMesh(USkeletalMesh* InMesh)
{
	SkeletalMesh = InMesh;
}

void USkinToggle::SetMaterial(UMaterial* InMaterial)
{
	Material = InMaterial;
}

void USkinToggle::Execute()
{
	Toggle();
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
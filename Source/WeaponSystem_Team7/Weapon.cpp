#include "Weapon.h"
#include "WeaponSystem_Team7Character.h"
#include "Engine/Engine.h"
#include <Camera/CameraComponent.h>

// Sets default values
AWeapon::AWeapon()
{
	ADSCam = CreateDefaultSubobject<UCameraComponent>(TEXT("ADSCamera"));
	ADSCam->SetRelativeLocationAndRotation(FVector(0.0f, 10.0f, 24.0f), FRotator(0.0f, 89.5f, 0.0f)); // Setting default location/rotation

	USceneComponent* Scene = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Scene;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Collider = CreateDefaultSubobject<USphereComponent>("Collider");
	Collider->SetupAttachment(Mesh);

	ADSCam->SetupAttachment(RootComponent);

	Collider->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::BeginOverlap);
}

void AWeapon::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Magenta, "Collided with Weapon");

	AWeaponSystem_Team7Character* character = Cast<AWeaponSystem_Team7Character>(OtherActor);

	AttachToComponent(character->GetMesh1P(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "GripPoint");
	Collider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetActorHiddenInGame(true);
	character->Weapon.Add(this);
	if (character->CurrentWeapon == nullptr)
	{
		bIsEquipped = true;
		character->CurrentWeapon = character->Weapon[0];
		character->CurrentWeapon->SetActorHiddenInGame(false);
	}
}

UAmmo* AWeapon::GetAmmoComponent()
{
	if (Ammo!=nullptr)
	{
		return Ammo;
	}

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, "You have no Ammo Component set! Use SetAmmoComonent function!");
	return nullptr;
}

UUIColor* AWeapon::GetUIColorComponent()
{
	if (UIColor != nullptr)
	{
		return UIColor;
	}

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, "You have no UIColor Component set! Use SetUIColorComponent function!");
	return nullptr;
}

void AWeapon::SetAmmoComponent(UAmmo* InAmmo)
{
	Ammo = InAmmo;
}

void AWeapon::SetUIColorComponent(UUIColor* InUIColor)
{
	UIColor = InUIColor;
}

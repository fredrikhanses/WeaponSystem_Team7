// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "WeaponSystem_Team7Character.h"
#include "Engine/Engine.h"
#include <Camera/CameraComponent.h>

// Sets default values
AWeapon::AWeapon()
{

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
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

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeapon::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Magenta, "Collided with Weapon");

	AWeaponSystem_Team7Character* character = Cast<AWeaponSystem_Team7Character>(OtherActor);

	if (character->Weapon.Num() > 0)
	{
		SetActorHiddenInGame(true);
	}

	AttachToComponent(character->GetMesh1P(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "GripPoint");
	character->Weapon.Add(this);
	character->CurrentWeapon = character->Weapon[character->Weapon.Num()-1];
	Collider->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}
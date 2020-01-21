// Fill out your copyright notice in the Description page of Project Settings.

#include "KickBack.h"
#include <Engine/Engine.h>

UKickBack::UKickBack()
{

}

void UKickBack::SetMesh(USkeletalMeshComponent* InMesh)
{
	Mesh = InMesh;
}

void UKickBack::SetAnimation(UAnimMontage* InAnimation)
{
	FireAnimation = InAnimation;
}

void UKickBack::Execute()
{
	AnimateKickBack();
}

void UKickBack::AnimateKickBack()
{
	if (FireAnimation != nullptr && FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		AnimInstance = Mesh->GetAnimInstance();
		if (AnimInstance != nullptr && AnimInstance != NULL)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Play kickback");
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

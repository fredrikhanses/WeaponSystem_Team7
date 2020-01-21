// Fill out your copyright notice in the Description page of Project Settings.

#include "KickBack.h"

UKickBack::UKickBack()
{

}

void UKickBack::SetMesh(USkeletalMeshComponent* InMesh)
{
	WeaponMesh = InMesh;
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
	if (FireAnimation != nullptr)
	{
		// Get the animation object for the arms mesh
		AnimInstance = WeaponMesh->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

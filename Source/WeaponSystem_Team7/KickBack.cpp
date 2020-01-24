#include "KickBack.h"

UKickBack::UKickBack()
{
}

void UKickBack::SetCharacter(ACharacter* InCharacter)
{
	Player = Cast<AWeaponSystem_Team7Character>(InCharacter);
}

void UKickBack::SetPlayRate(float InPlayRate)
{
	PlayRate = InPlayRate;
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
	if (Player != nullptr)
	{
		// Get the animation object for the arms mesh
		AnimInstance = Player->GetMesh1P()->GetAnimInstance();
		if (AnimInstance != nullptr && FireAnimation != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, PlayRate);
		}
	}
}
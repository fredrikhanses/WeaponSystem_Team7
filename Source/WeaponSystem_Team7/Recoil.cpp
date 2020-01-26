#include "Recoil.h"

URecoil::URecoil()
{
}

void URecoil::SetPawn(APawn* InPawn)
{
	Pawn = InPawn;
}

void URecoil::SetCameraShake(TSubclassOf<UCameraShake> InCameraShake)
{
	CameraShake = InCameraShake;
}

void URecoil::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
	InitialRecoilSteps = RecoilSteps;
	InitialRecoverSteps = RecoverSteps;
}

void URecoil::Execute()
{
	StartRecoilTimer();
	WeaponCameraShake();
}

void URecoil::StartRecoilTimer()
{
	if (Pawn != nullptr && RecoverStrength > 0 && RecoverSteps > 0)
	{
		GenerateYawAmount();
		World->GetTimerManager().SetTimer(TimerHandle, this, &URecoil::Recoil, Smoothness, true);
	}
}

void URecoil::GenerateYawAmount()
{
	RandomRecoilYaw = FMath::RandRange(-1 * RecoilYawLeftMax, RecoilYawRightMax);
}

void URecoil::Recoil()
{
	if (--RecoilSteps <= 0)
	{
		StopRecoilTimer();
		if (RecoverStrength > 0 && RecoverSteps > 0)
		{
			StartRecoverTimer();
		}
	}
	else
	{
		Pawn->AddControllerPitchInput(-1 * RecoilStrength);
		Pawn->AddControllerYawInput(-1 * RandomRecoilYaw);
	}
}

void URecoil::StopRecoilTimer()
{
	RecoilSteps = InitialRecoilSteps;
	World->GetTimerManager().ClearTimer(TimerHandle);
}

void URecoil::StartRecoverTimer()
{
	World->GetTimerManager().SetTimer(TimerHandle, this, &URecoil::Recover, Smoothness, true);
}

void URecoil::Recover()
{
	if (--RecoverSteps <= 0)
	{
		StopRecoverTimer();
	}
	else
	{
		Pawn->AddControllerPitchInput(RecoverStrength);
	}
}

void URecoil::StopRecoverTimer()
{
	RecoverSteps = InitialRecoverSteps;
	World->GetTimerManager().ClearTimer(TimerHandle);
}

void URecoil::WeaponCameraShake()
{
	if (CameraShake != nullptr)
	{
		World->GetFirstPlayerController()->PlayerCameraManager->PlayCameraShake(CameraShake, 1.0f);
	}
}
// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WeaponSystem_Team7HUD.generated.h"

UCLASS()
class AWeaponSystem_Team7HUD : public AHUD
{
	GENERATED_BODY()

public:
	AWeaponSystem_Team7HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};


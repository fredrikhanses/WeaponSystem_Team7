// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "WeaponSystem_Team7GameMode.h"
#include "WeaponSystem_Team7HUD.h"
#include "WeaponSystem_Team7Character.h"
#include "UObject/ConstructorHelpers.h"

AWeaponSystem_Team7GameMode::AWeaponSystem_Team7GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AWeaponSystem_Team7HUD::StaticClass();
}

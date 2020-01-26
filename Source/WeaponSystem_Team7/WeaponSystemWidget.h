#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include "Ammo.h"
#include "WeaponSystem_Team7Character.h"
#include "WeaponSystemWidget.generated.h"

UCLASS(Abstract)
class WEAPONSYSTEM_TEAM7_API UWeaponSystemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	/**
	* Ammo UTextBlock which are placed in the widget. Stores current ammo
	*/
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CurrentAmmoText;

	/**
	* Ammo UTextBlock which are placed in the widget. Stores surplus ammo
	*/
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* SurplusAmmoText;

	/**
	* 1st weapon name UTextBlock which are placed in the widget
	*/
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* FirstSlotName;

	/**
	* 2nd weapon name UTextBlock which are placed in the widget
	*/
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* SecondSlotName;

	/**
	* 3rd weapon name UTextBlock which are placed in the widget
	*/
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ThirdSlotName;

	/**
	* 4th weapon name UTextBlock which are placed in the widget
	*/
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* FourthSlotName;

	/**
	* Stores a reference to an ammo component
	*/
	UPROPERTY(BlueprintReadWrite, Category = Data)
	UAmmo* Ammo;

	/**
	* Stores a reference to the player
	*/
	UPROPERTY(BlueprintReadWrite, Category = Data)
	AWeaponSystem_Team7Character* Player;

	/**
	* An array to store the name of the weapons
	*/
	TArray<UTextBlock*> WeaponSlotArray;

	/**
	* An array that stores the picked up weapons
	*/
	TArray<AWeapon*> WeaponArray;

public:
	
	/**
	* Constructor
	*/
	UWeaponSystemWidget(const FObjectInitializer& ObjectInitializer);

	/**
	* Function that is used similar to BeginPlay
	*/
	virtual void NativeConstruct() override;

	/**
	* Updates ammo on screen
	*/
	UFUNCTION(BlueprintCallable)
	void DisplayAmmoInfo();

	/**
	* Updates weapon names and their color on screen
	*/
	UFUNCTION(BlueprintCallable)
	void UpdateWeaponName();

	/**
	* Fills the array with the UTextBlocks
	*/
	void CreateWeaponSlotArray();

};

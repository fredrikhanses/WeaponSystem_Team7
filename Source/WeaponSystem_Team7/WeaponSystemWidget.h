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
	
private:	

	/**
	* Disclaimer: Not in use at the moment.
	* Standard timer handle used for updating widget.
	*/
	//FTimerHandle TimerHandle;
	int CurrentAmmo;
	int SurplusAmmo;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
	TSubclassOf<UUserWidget> Widget;

	/**
	* Disclaimer: Not in use at the moment.
	* Used for creating the widget.
	*/
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
	//UUserWidget* WidgetHolder;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CurrentAmmoText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* SurplusAmmoText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* FirstSlotName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* SecondSlotName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ThirdSlotName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* FourthSlotName;

	UPROPERTY(BlueprintReadWrite, Category = Data)
	UAmmo* Ammo;

	UPROPERTY(BlueprintReadWrite, Category = Data)
	AWeaponSystem_Team7Character* Player;

	TArray<UTextBlock*> WeaponSlotArray;

	TArray<const FText> WeaponNameArray;

	int ArrayIndex;

	/**
	* Disclaimer: Not in use at the moment.
	* The interval in which the widget updates.
	*/
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	//float UpdateInterval = 0.1f;

public:
	
	UWeaponSystemWidget(const FObjectInitializer& ObjectInitializer);

	/**
	* Disclaimer: Not in use at the moment.
	* 
	*/
	virtual void NativeConstruct() override;

	/**
	* Disclaimer: Not in use at the moment.
	* Creates a timer which updates the widget.
	*/
	//UFUNCTION(BlueprintCallable)
	//void StartTimer();

	UFUNCTION(BlueprintCallable)
	void DisplayAmmoInfo();

	UFUNCTION(BlueprintCallable)
	void UpdateWeaponName();

	void CreateWeaponSlotArray();
};

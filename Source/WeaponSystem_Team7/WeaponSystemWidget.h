#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include "Ammo.h"
#include "WeaponSystemWidget.generated.h"

UCLASS(Abstract)
class WEAPONSYSTEM_TEAM7_API UWeaponSystemWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:	

	FTimerHandle TimerHandle;
	int CurrentAmmo;
	int SurplusAmmo;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
	TSubclassOf<UUserWidget> Widget;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
	//UUserWidget* WidgetHolder;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CurrentAmmoText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* SurplusAmmoText;

	UPROPERTY(BlueprintReadWrite, Category = Data)
	UAmmo* Ammo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	float UpdateInterval = 0.1f;

public:
	
	UWeaponSystemWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void StartTimer();

	UFUNCTION(BlueprintCallable)
	void DisplayAmmoInfo();
};

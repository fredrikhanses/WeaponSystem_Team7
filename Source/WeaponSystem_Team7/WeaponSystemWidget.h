#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include "WeaponSystemWidget.generated.h"

UCLASS(Abstract)
class WEAPONSYSTEM_TEAM7_API UWeaponSystemWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
	TSubclassOf<UUserWidget> Widget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Widgets)
	UUserWidget* WidgetHolder;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* DisplayAmmo;
	
protected:
	
	virtual void NativeConstruct() override;

public:
	
	UWeaponSystemWidget(const FObjectInitializer& ObjectInitializer);

};

#include "WeaponSystemWidget.h"
#include <Engine/Engine.h>

UWeaponSystemWidget::UWeaponSystemWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UWeaponSystemWidget::NativeConstruct()
{
	DisplayAmmo->SetText(FText::FromString("99"));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, DisplayAmmo->GetText().ToString());
}

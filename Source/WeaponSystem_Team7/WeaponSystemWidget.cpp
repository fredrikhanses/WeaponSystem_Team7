#include "WeaponSystemWidget.h"

UWeaponSystemWidget::UWeaponSystemWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UWeaponSystemWidget::DisplayAmmoInfo()
{
	if (Ammo != nullptr)
	{
		CurrentAmmoText->SetText(FText::FromString(FString::FromInt(Ammo->GetCurrentAmmo())));
		SurplusAmmoText->SetText(FText::FromString(FString::FromInt(Ammo->GetSurplusAmmo())));
	}
}

void UWeaponSystemWidget::UpdateWeaponName()
{
	if (Player != nullptr)
	{
		WeaponArray = Player->Weapon;
		if (WeaponArray.Num() > 0 && WeaponArray.Num() <= WeaponSlotArray.Num())
		{
			for (int i = 0; i < WeaponArray.Num(); i++)
			{
				WeaponSlotArray[i]->SetText(FText::FromString(WeaponArray[i]->GetFName().ToString()));
				if (WeaponArray[i]->GetUIColorComponent() != nullptr)
				{
					WeaponSlotArray[i]->SetColorAndOpacity(WeaponArray[i]->GetUIColorComponent()->GetTextColor());
				}
			}
		}
	}
}

void UWeaponSystemWidget::CreateWeaponSlotArray()
{
	WeaponSlotArray.Emplace(FirstSlotName);
	WeaponSlotArray.Emplace(SecondSlotName);
	WeaponSlotArray.Emplace(ThirdSlotName);
	WeaponSlotArray.Emplace(FourthSlotName);
}

void UWeaponSystemWidget::NativeConstruct()
{
	CreateWeaponSlotArray();
}
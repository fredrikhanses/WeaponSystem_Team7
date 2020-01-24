#include "WeaponSystemWidget.h"
#include "WeaponSystem_Team7Character.h"

UWeaponSystemWidget::UWeaponSystemWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

//void UWeaponSystemWidget::StartTimer()
//{
//	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UWeaponSystemWidget::DisplayAmmoInfo, UpdateInterval, true);
//}

void UWeaponSystemWidget::DisplayAmmoInfo()
{
	if (Ammo != nullptr)
	{
		CurrentAmmo = Ammo->GetCurrentAmmo();
		SurplusAmmo = Ammo->GetSurplusAmmo();	
		CurrentAmmoText->SetText(FText::FromString(FString::FromInt(CurrentAmmo)));
		SurplusAmmoText->SetText(FText::FromString(FString::FromInt(SurplusAmmo)));
	}
}

void UWeaponSystemWidget::UpdateWeaponName()
{
	if (Player != nullptr)
	{
		if (WeaponSlotArray.Num() > ArrayIndex)
		{
			//FText Temp = FText::FromString(Player->CurrentWeapon->GetFName().ToString());
			//if(!WeaponNameArray.Contains(Temp))
			//{
				WeaponSlotArray[ArrayIndex]->SetText(FText::FromString(Player->CurrentWeapon->GetFName().ToString()));
				ArrayIndex++;
			//}
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
	//AWeaponSystem_Team7Character* Player = Cast<AWeaponSystem_Team7Character>(GetWorld()->GetFirstPlayerController()->GetPawn());

	//if (Player != nullptr)
	//{
	//	Ammo = Player->CurrentWeapon->GetAmmoComponent();
	//}
	//WidgetHolder = CreateWidget<UUserWidget>(GetWorld()->)
	//	TRY TO DO IN CHARACTER
}
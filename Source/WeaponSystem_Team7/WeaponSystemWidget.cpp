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
	if (Character != nullptr)
	{
		Player = Cast<AWeaponSystem_Team7Character>(Character);
		if (WeaponArray.Num() > ArrayIndex)
		{
			WeaponArray[ArrayIndex]->SetText(FText::FromString(Player->CurrentWeapon->GetFName().ToString()));
			ArrayIndex++;
		}
	}
}

void UWeaponSystemWidget::FillArray()
{
	WeaponArray.Emplace(FirstSlotName);
	WeaponArray.Emplace(SecondSlotName);
	WeaponArray.Emplace(ThirdSlotName);
	WeaponArray.Emplace(FourthSlotName);
}

void UWeaponSystemWidget::NativeConstruct()
{
	FillArray();
	//AWeaponSystem_Team7Character* Player = Cast<AWeaponSystem_Team7Character>(GetWorld()->GetFirstPlayerController()->GetPawn());

	//if (Player != nullptr)
	//{
	//	Ammo = Player->CurrentWeapon->GetAmmoComponent();
	//}
	//WidgetHolder = CreateWidget<UUserWidget>(GetWorld()->)
	//	TRY TO DO IN CHARACTER
}
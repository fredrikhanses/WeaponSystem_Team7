#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Styling/SlateColor.h>
#include "UIColor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API UUIColor : public UActorComponent
{
	GENERATED_BODY()

public:

	/**
	* Stores the weapon text color
	*/
	UPROPERTY(EditAnywhere, Category = WeaponTextColor)
	FSlateColor TextColor;

public:	

	/**
	* Default constructor
	*/
	UUIColor();

	/**
	* Sets the weapon text color
	*/
	UFUNCTION(BlueprintCallable)
	void SetTextColor(FSlateColor InTextColor);

	/**
	* Gets the weapon text color
	*/
	UFUNCTION(BlueprintCallable)
	FSlateColor GetTextColor();
		
};

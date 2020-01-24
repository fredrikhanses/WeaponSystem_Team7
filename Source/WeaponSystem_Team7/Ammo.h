#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include "Ammo.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API UAmmo : public UModuleBase
{
	GENERATED_BODY()

private:

	float OriginalClipSize;

public:	

	UPROPERTY(EditAnywhere, Category = Ammo)
	int MaxAmmo = 100;

	UPROPERTY(EditAnywhere, Category = Ammo)
	int SurplusAmmo = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Ammo)
	int CurrentAmmo = 10;

	UPROPERTY(EditAnywhere, Category = Ammo)
	int ClipSize = 10;

protected:

	virtual void BeginPlay() override;

public:

	UAmmo();

	/**
	* Inherited function that is used in conjunction with 
	*/
	UFUNCTION(BlueprintCallable)
	virtual void Execute() override;

	/**
	* Checks if there are any current ammo
	*/
	UFUNCTION(BlueprintCallable)
	bool CheckAmmo();	
	
	/**
	* Decrements current ammo by one
	*/
	UFUNCTION(BlueprintCallable)
	void UseAmmo();	
	
	/**
	* Sets current ammo to the size of the clip and 
	* removes an appropriate amount from surplus ammo
	*/
	UFUNCTION(BlueprintCallable)
	void Reload();

	UFUNCTION(BlueprintCallable)
	int GetCurrentAmmo();

	UFUNCTION(BlueprintCallable)
	int GetSurplusAmmo();

};
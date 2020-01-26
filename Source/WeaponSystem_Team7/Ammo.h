#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include "Ammo.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API UAmmo : public UModuleBase
{
	GENERATED_BODY()

private:

	/**
	* Stores the original clip size
	*/
	float OriginalClipSize;

public:	

	/**
	* Stores surplus ammo
	*/
	UPROPERTY(EditAnywhere, Category = Ammo)
	int SurplusAmmo = 100;

	/**
	* Stores current ammo
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Ammo)
	int CurrentAmmo = 10;

	/**
	* Stores the clip size. Used to calculate how much to reload
	*/
	UPROPERTY(EditAnywhere, Category = Ammo)
	int ClipSize = 10;

protected:

	virtual void BeginPlay() override;

public:
	
	/**
	* Default constructor
	*/
	UAmmo();

	/**
	* Inherited function that executes the main function of the class
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

	/**
	* Gets current ammo
	*/
	UFUNCTION(BlueprintCallable)
	int GetCurrentAmmo();

	/**
	* Sets surplus ammo
	*/
	UFUNCTION(BlueprintCallable)
	int GetSurplusAmmo();

};
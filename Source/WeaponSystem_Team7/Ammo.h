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

	UFUNCTION(BlueprintCallable)
	void Execute();

	UFUNCTION(BlueprintCallable)
	bool CheckAmmo();	
	
	UFUNCTION(BlueprintCallable)
	void UseAmmo();	
		
	UFUNCTION(BlueprintCallable)
	void Reload();

	UFUNCTION(BlueprintCallable)
	int GetCurrentAmmo();

	UFUNCTION(BlueprintCallable)
	int GetSurplusAmmo();

};
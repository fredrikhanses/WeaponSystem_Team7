#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include <Animation/AnimMontage.h>
#include <Animation/AnimInstance.h>
#include <GameFramework/Character.h>
#include "WeaponSystem_Team7Character.h"
#include "KickBack.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API UKickBack : public UModuleBase
{
	GENERATED_BODY()
	
private:

	UAnimInstance* AnimInstance;

	AWeaponSystem_Team7Character* Player;

public:

	UPROPERTY(EditAnywhere, Category = Animation)
	UAnimMontage* FireAnimation;

public:

	UKickBack();

	UFUNCTION(BlueprintCallable)
		void SetCharacter(ACharacter* InCharacter);

	UFUNCTION(BlueprintCallable)
	void SetAnimation(UAnimMontage* InAnimation);

	UFUNCTION(BlueprintCallable)
	virtual void Execute() override;

	UFUNCTION(BlueprintCallable)
	void AnimateKickBack();
};

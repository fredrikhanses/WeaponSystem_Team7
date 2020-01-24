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

	/**
	 * Animation to use for the kickback.
	 * To run kickback, you need to use the SetCharacter function in BeginPlay(Recommended)
	 */
	UPROPERTY(EditAnywhere, Category = Animation)
		UAnimMontage* FireAnimation;

	/**
	 * Speed of animation montage.
	 * Lower numbers for slower animations.
	 */
	UPROPERTY(EditAnywhere, Category = Animation)
		float PlayRate = 1.0f;

public:

	UKickBack();

	/**
	 * Set Character that uses the animation.
	 * For example, The player.
	 */
	UFUNCTION(BlueprintCallable)
		void SetCharacter(ACharacter* InCharacter);

	/**
	* Sets speed of animation.
	* Lower numbers for slower animations
	*/
	UFUNCTION(BlueprintCallable)
		void SetPlayRate(float InPlayRate);

	/**
	 * Function to set the Animation Montage Property
	 */
	UFUNCTION(BlueprintCallable)
		void SetAnimation(UAnimMontage* InAnimation);

	virtual void Execute() override;

	/**
	 * Runs the kickback animation
	 */
	UFUNCTION(BlueprintCallable)
		void AnimateKickBack();
};

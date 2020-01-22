#pragma once

#include "CoreMinimal.h"
#include "ModuleBase.h"
#include <Animation/AnimMontage.h>
#include <Animation/AnimInstance.h>
#include <Components/SkeletalMeshComponent.h>
#include "KickBack.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_TEAM7_API UKickBack : public UModuleBase
{
	GENERATED_BODY()
	
private:

	UAnimInstance* AnimInstance;

public:

	UPROPERTY(EditAnywhere, Category = Animation)
	UAnimMontage* FireAnimation;

	UPROPERTY(EditAnywhere, Category = Mesh)
	USkeletalMeshComponent* Mesh;

public:

	UKickBack();

	UFUNCTION(BlueprintCallable)
	void SetMesh(USkeletalMeshComponent* InMesh);

	UFUNCTION(BlueprintCallable)
	void SetAnimation(UAnimMontage* InAnimation);

	UFUNCTION(BlueprintCallable)
	virtual void Execute() override;

	UFUNCTION(BlueprintCallable)
	void AnimateKickBack();

};

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ModuleBase.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSYSTEM_TEAM7_API UModuleBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	UModuleBase();

	virtual void Execute() {};

protected:
	virtual void BeginPlay() override;
};
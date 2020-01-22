#include "ModuleBase.h"

UModuleBase::UModuleBase()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UModuleBase::BeginPlay()
{
	Super::BeginPlay();	
}


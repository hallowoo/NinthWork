#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IdentifyingCommands.generated.h"

UCLASS()
class NINTHWORK_API UIdentifyingCommands : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	static bool IsCommand(FString Massage);
};

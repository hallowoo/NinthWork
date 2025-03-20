#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Make3RandNum.generated.h"

UCLASS()
class NINTHWORK_API UMake3RandNum : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	static FString Make3RandNum();
};

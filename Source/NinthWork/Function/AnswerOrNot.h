#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AnswerOrNot.generated.h"

UCLASS()
class NINTHWORK_API UAnswerOrNot : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	static bool AnswerOrNot(FString Massage);	
};

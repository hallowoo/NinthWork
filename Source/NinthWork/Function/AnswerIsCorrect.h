#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AnswerIsCorrect.generated.h"

UCLASS()
class NINTHWORK_API UAnswerIsCorrect : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	static bool AnswerIsCorrect(int32 StrCount);
};

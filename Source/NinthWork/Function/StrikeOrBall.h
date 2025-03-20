#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StrikeOrBall.generated.h"

UCLASS()
class NINTHWORK_API UStrikeOrBall : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	static FIntPoint StrikeOrBall(FString answer, FString GoalNumber);

};

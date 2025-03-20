#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WinnerProcess.generated.h"

class AWNController;

UCLASS()
class NINTHWORK_API UWinnerProcess : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	static void WinnerProcess(AWNController* Winner);
};

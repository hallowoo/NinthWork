#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "WNGameStateBase.generated.h"

UCLASS()
class NINTHWORK_API AWNGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	AWNGameStateBase();

	UFUNCTION(BlueprintCallable, Category = "GameState")
	void SetGoalNumber(FString RandGoalNumber);
	UFUNCTION(BlueprintCallable, Category = "GameState")
	FString GetGoalNumber() const;

private:
	FString GoalNumber;
};

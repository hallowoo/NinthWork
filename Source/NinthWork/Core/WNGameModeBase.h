#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WNGameModeBase.generated.h"

UCLASS()
class NINTHWORK_API AWNGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AWNGameModeBase();

	virtual void BeginPlay() override;
	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;


	void SetPlayerID(const FString& PlayerName, const FString& RequestedID);

private:
	bool IsIDInUse(const FString& ID);
};

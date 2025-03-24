
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WNController.generated.h"

UCLASS()
class NINTHWORK_API AWNController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AWNController();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void SendIDForSetToState(const FString& ID);

};

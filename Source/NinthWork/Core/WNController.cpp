#include "WNController.h"
#include "WNPlayerState.h"

AWNController::AWNController()
{

}

void AWNController::SendIDForSetToState_Implementation(const FString& ID)
{
	if (APlayerState* Ps = GetPlayerState<APlayerState>())
	{
		if (AWNPlayerState* WNPlayerState = Cast<AWNPlayerState>(Ps))
		{
			WNPlayerState->SetUserID(ID);
		}
	}
}
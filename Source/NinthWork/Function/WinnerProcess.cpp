#include "WinnerProcess.h"
#include "..\Source\NinthWork\Core\WNController.h"
#include "..\Source\NinthWork\Core\WNPlayerState.h"

void UWinnerProcess::WinnerProcess(AWNController* Winner)
{
	if (Winner)
	{
		if (AWNPlayerState* Pstate = Cast<AWNPlayerState>(Winner->PlayerState))
		{
			Pstate->PlayerGetScore();
		}
	}
}



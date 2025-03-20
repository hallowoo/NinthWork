// Fill out your copyright notice in the Description page of Project Settings.


#include "WNGameModeBase.h"
#include "WNPlayerState.h"
#include "WNGameStateBase.h"

AWNGameModeBase::AWNGameModeBase()
{
	GameStateClass = AWNGameStateBase::StaticClass();
}

void AWNGameModeBase::BeginPlay()
{
	Super::BeginPlay();

}

void AWNGameModeBase::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
	Super::HandleStartingNewPlayer_Implementation(NewPlayer);

	if (AWNPlayerState* PState = Cast<AWNPlayerState>(NewPlayer->PlayerState))
	{
		if (PState->UserID.IsEmpty())
		{
			PState->SetUserID(FGuid::NewGuid().ToString().Left(8));
		}
	}
}

void AWNGameModeBase::SetPlayerID(const FString& PlayerName, const FString& RequestedID)
{
	if (GameState)
	{
		FString UniqueID = RequestedID;
		int32 Suffix = 1;

		while (IsIDInUse(UniqueID))
		{
			UniqueID = FString::Printf(TEXT("%s_%d"), *RequestedID, Suffix++);
		}

		for (APlayerState* Pstate : GameState->PlayerArray)
		{
			if (AWNPlayerState* WNPlayerState = Cast<AWNPlayerState>(Pstate))
			{
				if (WNPlayerState->GetPlayerName() == PlayerName)
				{
					WNPlayerState->SetUserID(UniqueID);
					return;
				}
			}
		}
	}
}

bool AWNGameModeBase::IsIDInUse(const FString& ID)
{
	if (GameState)
	{
		for (APlayerState* Pstate : GameState->PlayerArray)
		{
			if (AWNPlayerState* WNPlayerState = Cast<AWNPlayerState>(Pstate))
			{
				if (WNPlayerState->UserID == ID && WNPlayerState->UserID != "")
				{
					return true;
				}
			}
		}
	}

	return false;
}
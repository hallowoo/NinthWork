// Fill out your copyright notice in the Description page of Project Settings.


#include "WNPlayerState.h"
#include "Net/UnrealNetwork.h"

AWNPlayerState::AWNPlayerState()
{
	PlayerScore = 0;
	RemainingTurn = 3;
	bIsOut = false;
	bReplicates = true;

	if (HasAuthority())
	{
		UserID = FGuid::NewGuid().ToString().Left(8);
	}
}

void AWNPlayerState::PlayerGetScore_Implementation()
{
	if (HasAuthority())
	{
		PlayerScore++;
	}
}

int32 AWNPlayerState::GetPlayerScore() const
{
	return PlayerScore;
}

void AWNPlayerState::PlayerUseTurn_Implementation()
{
	RemainingTurn--;
}

int32 AWNPlayerState::GetRemainingTurn() const
{
	return RemainingTurn;
}

void AWNPlayerState::PlayerOut()
{
	bIsOut = true;
}

void AWNPlayerState::InitializeState()
{
	RemainingTurn = 3;
	bIsOut = false;
}

void AWNPlayerState::SetUserID_Implementation(const FString& ID)
{
	if (HasAuthority())
	{
		if (UserID != ID)
		{
			UserID = ID;
		}
	}
}

void AWNPlayerState::OnRep_UserID()
{
}

FString AWNPlayerState::GetUserID() const
{
	return UserID;
}

void AWNPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWNPlayerState, UserID);
	DOREPLIFETIME(AWNPlayerState, PlayerScore);
}
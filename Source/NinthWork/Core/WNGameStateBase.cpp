#include "WNGameStateBase.h"

AWNGameStateBase::AWNGameStateBase()
{
	GoalNumber = "";
}

void AWNGameStateBase::SetGoalNumber(FString RandGoalNumber)
{
	GoalNumber = RandGoalNumber;
}

FString AWNGameStateBase::GetGoalNumber() const
{
	return GoalNumber;
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "StrikeOrBall.h"

FIntPoint UStrikeOrBall::StrikeOrBall(FString answer,FString GoalNumber)
{
	int32 StrCount = 0;
	int32 BallCount = 0;

	if (GoalNumber.IsEmpty())
	{
		return FIntPoint(99,99);
	}

	for (int i = 1; i < 4; i++)
	{
		if (answer[i] == GoalNumber[i])
		{
			StrCount++;
		}

		for (int j = 1; j < 4; j++)
		{
			if (i != j)
			{
				if (answer[i] == GoalNumber[j])
				{
					BallCount++;
				}
			}
		}
	}

	return FIntPoint(StrCount, BallCount);

}
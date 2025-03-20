// Fill out your copyright notice in the Description page of Project Settings.


#include "Make3RandNum.h"
#include <random>

FString UMake3RandNum::Make3RandNum()
{
	FString GoalNumber = "";
	std::random_device randDevice;
	FMath::RandInit(randDevice());

	while (GoalNumber.IsEmpty())
	{
		int32 RandomNumber = FMath::RandRange(0, 9);
		if (RandomNumber != 0)
		{
			GoalNumber.AppendInt(RandomNumber);
		}
	}

	while (GoalNumber.Len() <= 2)
	{
		bool bIsUnique = true;
		int32 RandomNumber = FMath::RandRange(0, 9);

		for (int i = 0; i < GoalNumber.Len(); i++)
		{
			if (GoalNumber[i] == TCHAR('0' + RandomNumber))
			{
				bIsUnique = false;
				break;
			}
		}

		if (bIsUnique)
		{
			GoalNumber.AppendInt(RandomNumber);
		}
	}

	GoalNumber.InsertAt(0, TEXT("/"));

	if (GoalNumber.Len() != 4)
	{
		Make3RandNum();
	}

	return GoalNumber;
}
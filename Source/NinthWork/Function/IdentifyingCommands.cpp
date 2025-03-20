// Fill out your copyright notice in the Description page of Project Settings.


#include "IdentifyingCommands.h"

bool UIdentifyingCommands::IsCommand(FString Massage)
{
	if (!Massage.IsEmpty())
	{
		if (Massage[0] == '!')
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	return false;
}
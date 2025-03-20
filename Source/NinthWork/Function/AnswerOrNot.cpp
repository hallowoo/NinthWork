// Fill out your copyright notice in the Description page of Project Settings.


#include "AnswerOrNot.h"

bool UAnswerOrNot::AnswerOrNot(FString Massage)
{
	if (Massage.IsEmpty())
	{
		return false;
	}

	if (Massage[0] == '/' && Massage.Len() == 4)
	{
		for (int i = 1; i < 4; i++)
		{
			if (!FChar::IsDigit(Massage[i]))
			{
				return false;
			}
		}
		return true;
	}

	return false;
}
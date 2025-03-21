// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "WNPlayerState.generated.h"

UCLASS()
class NINTHWORK_API AWNPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	AWNPlayerState();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "State")
	void PlayerGetScore();
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "State")
	void PlayerUseTurn();
	UFUNCTION(BlueprintCallable, Category = "State")
	void PlayerOut();
	UFUNCTION(BlueprintCallable, Category = "State")
	void InitializeState();
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "State")
	void SetUserID(const FString& ID);
	UFUNCTION(BlueprintCallable, Category = "State")
	int32 GetPlayerScore() const;
	UFUNCTION(BlueprintCallable, Category = "State")
	int32 GetRemainingTurn() const;
	UFUNCTION(BlueprintCallable, Category = "State")
	FString GetUserID() const;
	UFUNCTION(BlueprintCallable, Category = "State")
	void GiveTicketToUser();
	UFUNCTION()
	void OnRep_UserID();

	
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "State")
	int32 PlayerScore;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
	int32 RemainingTurn;
	UPROPERTY(ReplicatedUsing=OnRep_UserID, BlueprintReadOnly, Category = "State")
	FString UserID;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
	bool bIsOut;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
	bool bHasTicket;


protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};

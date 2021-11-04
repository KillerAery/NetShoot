// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "RankListSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class NETSHOOT_API URankListSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, Replicated, Category = Basic)
	TArray<int32> RankListScore;

	UPROPERTY(VisibleAnywhere, Replicated , Category = Basic)
	TArray<FString> RankListName;

	URankListSaveGame();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const override;

	UFUNCTION(BlueprintCallable)
	void UpdateDataByRankMap(const TMap<FString, int32>& RankMap);

	UFUNCTION(BlueprintCallable)
	const TArray<int32>& GetRankListScore()const;

	UFUNCTION(BlueprintCallable)
	const TArray<FString>& GetRankListName()const;
};

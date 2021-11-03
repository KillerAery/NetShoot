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
	TMap<FString, int32> RankMap;

	TArray<int32> RankListScore;

	TArray<FString> RankListName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	bool NeedSort;
public:
	URankListSaveGame();

	void SortRankList();

	UFUNCTION(BlueprintCallable)
	TArray<int32>& GetRankListScore();

	UFUNCTION(BlueprintCallable)
	TArray<FString>& GetRankListName();

	UFUNCTION(BlueprintCallable)
	void ChangePlayerName(const FString& PreName,const FString& NowName);

	UFUNCTION(BlueprintCallable)
	void ChangePlayerScore(const FString& PlayerName,int32 DeltaScore);
};

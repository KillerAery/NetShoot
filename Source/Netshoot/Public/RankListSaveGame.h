// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "RankListSaveGame.generated.h"

/**
 * SHIT CODING
 */
UCLASS(Blueprintable,BlueprintType)
class NETSHOOT_API URankListSaveGame : public USaveGame
{
	GENERATED_BODY()
public:

	UPROPERTY(VisibleAnywhere)
	TArray<int32> RankListScore;

	UPROPERTY(VisibleAnywhere)
	TArray<FString> RankListName;

	URankListSaveGame();

	UFUNCTION(BlueprintCallable)
	static void UpdateDataByRankMap(const TMap<FString, int32>& RankMap,
									TArray<int32>& RankScore,
									TArray<FString>& RankName);

	UFUNCTION(BlueprintCallable)
	const TArray<int32>& GetRankListScore()const;

	UFUNCTION(BlueprintCallable)
	const TArray<FString>& GetRankListName()const;

	UFUNCTION(BlueprintCallable)
	void SetRankListScore(const TArray<int32>& RankScore);

	UFUNCTION(BlueprintCallable)
	void SetRankListName(const TArray<FString>& RankName);
};

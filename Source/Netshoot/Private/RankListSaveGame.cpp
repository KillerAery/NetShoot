// Fill out your copyright notice in the Description page of Project Settings.


#include <Net/UnrealNetwork.h>
#include "RankListSaveGame.h"

URankListSaveGame::URankListSaveGame() {
}

void URankListSaveGame::UpdateDataByRankMap(const TMap<FString, int32>& RankMap, TArray<int32>& RankScore, TArray<FString>& RankName)
{
	RankScore.Empty();
	RankName.Empty();

	for (auto& element : RankMap) {
		RankScore.Add(0);
		RankName.Add(element.Key);
	}

	RankName.Sort(
		[&RankMap](const FString& a, const FString& b) {
			return RankMap[a] > RankMap[b];
		}
	);

	for (int32 i = 0; i < RankScore.Num(); ++i) {
		RankScore[i] = RankMap[RankName[i]];
	}
}

const TArray<int32>& URankListSaveGame::GetRankListScore() const
{
	return RankListScore;
}

const TArray<FString>& URankListSaveGame::GetRankListName() const
{
	return RankListName;
}

void URankListSaveGame::SetRankListScore(const TArray<int32>& RankScore)
{
	RankListScore = RankScore;
}

void URankListSaveGame::SetRankListName(const TArray<FString>& RankName)
{
	RankListName = RankName;
}

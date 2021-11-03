// Fill out your copyright notice in the Description page of Project Settings.


#include "RankListSaveGame.h"

URankListSaveGame::URankListSaveGame() {
	NeedSort = false;
}

void URankListSaveGame::SortRankList()
{
	if (!NeedSort)return;

	RankListScore.Empty();
	RankListName.Empty();

	int32 index = 0;
	for (auto& element : RankMap) {
		RankListScore.Add(index);
		RankListName.Add(element.Key);
		++index;
	}

	RankListScore.Sort(
		[this](int32 a,int32 b){
			if (RankMap[RankListName[a]] < RankMap[RankListName[b]]) {
				Swap(RankListName[a], RankListName[b]);
				return true;
			}
			return false;
		}
	);

	for (int32 i = 0; i < RankListScore.Num(); ++i) {
		RankListScore[i] = RankMap[RankListName[i]];
	}
	NeedSort = false;
}

TArray<int32>& URankListSaveGame::GetRankListScore()
{
	SortRankList();
	return RankListScore;
}

TArray<FString>& URankListSaveGame::GetRankListName()
{
	SortRankList();
	return RankListName;
}

void URankListSaveGame::ChangePlayerName(const FString& PreName,const FString& NewName)
{
	int32* result = RankMap.Find(PreName);
	if (!result)return;
	RankMap.Emplace(NewName, *result);
	RankMap.Remove(PreName);
	NeedSort = true;
}

void URankListSaveGame::ChangePlayerScore(const FString& PlayerName, int32 score)
{
	int32* result = RankMap.Find(PlayerName);
	if (!result) {
		RankMap.Emplace(PlayerName, score);
	}
	else {
		*result += score;
	}
	NeedSort = true;
}

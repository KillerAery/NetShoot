// Fill out your copyright notice in the Description page of Project Settings.


#include "RankListSaveGame.h"

URankListSaveGame::URankListSaveGame() {

}

void URankListSaveGame::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}

void URankListSaveGame::UpdateDataByRankMap(const TMap<FString, int32>& RankMap)
{

	RankListScore.Empty();
	RankListName.Empty();

	int32 index = 0;
	for (auto& element : RankMap) {
		RankListScore.Add(index);
		RankListName.Add(element.Key);
		++index;
	}

	RankListScore.Sort(
		[this,&RankMap](int32 a, int32 b) {
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
}

const TArray<int32>& URankListSaveGame::GetRankListScore() const
{
	return RankListScore;
}

const TArray<FString>& URankListSaveGame::GetRankListName() const
{
	return RankListName;
}

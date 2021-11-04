// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingSaveGame.h"

USettingSaveGame::USettingSaveGame()
{
	LocalPlayerName = TEXT("DefaultPlayerName");
}

void USettingSaveGame::SetLocalPlayerName(const FString& name)
{
	LocalPlayerName = name;
}

FString USettingSaveGame::GetLocalPlayerName() const
{
	return LocalPlayerName;
}

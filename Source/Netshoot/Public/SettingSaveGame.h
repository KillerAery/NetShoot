// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SettingSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class NETSHOOT_API USettingSaveGame : public USaveGame
{
	GENERATED_BODY()
public:

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString LocalPlayerName;

	USettingSaveGame();

	UFUNCTION(BlueprintCallable)
	void SetLocalPlayerName(const FString& name);

	UFUNCTION(BlueprintCallable)
	FString GetLocalPlayerName()const;
};

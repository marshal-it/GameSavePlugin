// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "SaveDataManager.h"
#include "GameSaveBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GAMESAVEPLUGIN_API UGameSaveBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintPure, Category ="GameSaveLibrary")
	static USaveDataManager* GetSaveDataManager() 
	{
		return USaveDataManager::GetInstance();
	}
	
};

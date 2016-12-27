// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include <string>
#include "SaveDataStruct.h"
#include "SaveDataManager.generated.h"

/**
 *  数据管理入口
 */
UCLASS()
class GAMESAVEPLUGIN_API USaveDataManager : public UObject
{
	GENERATED_BODY()
	
public:
	static USaveDataManager* GetInstance() 
	{
		if (Instance == nullptr)
		{
			Instance = NewObject<USaveDataManager>();
		}
		return Instance;
	}

public:

private:

	//内存对象数据
	TMap<int32, FObjectData> ObjectsDataMap;

	//关卡实例对象数据
	TMap<int32, FActorData> ActorsDataMap;

	//主角数据
	TMap<int32, FCharacterData> CharacterDataMap;

	//关卡数据
	TMap<int32, FLevelData> LevelDataMap;

	//游戏实例数据
	TMap<int32, FGameInstanceData> GameInstanceDataMap;

	//游戏模式数据
	TMap<int32, FGameModeData> GameModeDataMap;

	//游戏状态数据
	TMap<int32, FGameStateData> GameStateDataMap;

private:
	USaveDataManager();
	~USaveDataManager()
	{
		Instance = nullptr;
	}
	static USaveDataManager* Instance;
};

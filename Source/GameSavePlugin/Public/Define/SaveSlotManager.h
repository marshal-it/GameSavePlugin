// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "GameSaveInfo.h"
#include "SaveSlotManager.generated.h"

/**
 *  Slot存档管理类
 */
UCLASS()
class GAMESAVEPLUGIN_API USaveSlotManager : public UObject
{
	GENERATED_BODY()
	
public:

	/*
		保存数据对象，更新数据对象
	*/
	virtual bool AddObjectsData(FObjectData objectData);

	virtual bool AddActorData(FActorData actorData);

	virtual bool AddCharacterData(FCharacterData characterData);

	virtual bool AddLevelData(FLevelData LevelData);

	virtual bool AddGameInstanceData(FGameInstanceData gameinstanceData);

	virtual bool AddGameModeData(FGameModeData gamemodeData);

	virtual bool AddGameStateData(FGameStateData gamestateData);

	/*
		更新存档数值
		提高更新保存数据的效率，指定具体数据进行更新
	*/
	void UpdateSaveData(FBaseData& Data, SAVESLOT_TYPE_DEFINE DataType);

	/*
		获取数据对象序列
	*/
	TMap<int32, FObjectData> GetObjectDataMap() { return ObjectsDataMap; }
	TMap<int32, FActorData> GetActorDataMap() { return ActorsDataMap; }
	TMap<int32, FCharacterData> GetCharacterDataMap() { return CharacterDataMap; }
	TMap<int32, FLevelData> GetLevelDataMap() { return LevelDataMap; }
	TMap<int32, FGameInstanceData> GetGameInstanceDataMap() { return GameInstanceDataMap; }
	TMap<int32, FGameModeData> GetGameModeDataMap() { return GameModeDataMap; }
	TMap<int32, FGameStateData> GetGameStateDataMap() { return GameStateDataMap; }

	/*
		保存数据到当前sav内存
	*/
	UGameSaveInfo* GetGameSaveInfoInstance();

	bool SaveGameDataToCurrentSlot();
	
private:

	TSubclassOf<UGameSaveInfo> GameSaveInfoClass = UGameSaveInfo::StaticClass();

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
	
	//Slot保存对象
	UGameSaveInfo* GameSaveInfoRef = nullptr;

	//SlotName
	FString SlotName = "SaveSlotTest";
	int32 UserIndex = 0;
};

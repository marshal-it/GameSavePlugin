// Fill out your copyright notice in the Description page of Project Settings.
#include "GameSavePluginPrivatePCH.h"
#include "GameSavePlugin.h"
#include "GameSaveInfo.h"

TArray<FObjectData> UGameSaveInfo::GetSaveDataObjectArray()
{
	TArray<FObjectData> ObjectArray;
	ObjectsDataMap.GenerateValueArray(ObjectArray);
	return ObjectArray;
}

TArray<FActorData> UGameSaveInfo::GetSaveDataActorArray()
{
	TArray<FActorData> ActorArray;
	ActorsDataMap.GenerateValueArray(ActorArray);
	return ActorArray;
}

TArray<FCharacterData> UGameSaveInfo::GetSaveDataCharacterArray()
{
	TArray<FCharacterData> CharacterArray;
	CharacterDataMap.GenerateValueArray(CharacterArray);
	return CharacterArray;
}

TArray<FLevelData> UGameSaveInfo::GetSaveDataLevelArray()
{
	TArray<FLevelData> LevelArray;
	LevelDataMap.GenerateValueArray(LevelArray);
	return LevelArray;
}

TArray<FGameInstanceData> UGameSaveInfo::GetSaveDataInstanceArray()
{
	TArray<FGameInstanceData> GameInstanceArray;
	GameInstanceDataMap.GenerateValueArray(GameInstanceArray);
	return GameInstanceArray;
}

TArray<FGameModeData> UGameSaveInfo::GetSaveDataModeArray()
{
	TArray<FGameModeData> GameModeArray;
	GameModeDataMap.GenerateValueArray(GameModeArray);
	return GameModeArray;
}

TArray<FGameStateData> UGameSaveInfo::GetSaveDataStateArray()
{
	TArray<FGameStateData> GameStateArray;
	GameStateDataMap.GenerateValueArray(GameStateArray);
	return GameStateArray;
}

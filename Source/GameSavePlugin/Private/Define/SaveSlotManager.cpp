// Fill out your copyright notice in the Description page of Project Settings.

#include "GameSavePluginPrivatePCH.h"
#include "SaveSlotManager.h"

bool USaveSlotManager::AddObjectsData(FObjectData objectData)
{
	TArray<int32> Keys;
	ObjectsDataMap.GenerateKeyArray(Keys);
	if (Keys.Contains(objectData.UniqueId))
	{
		ObjectsDataMap[objectData.UniqueId] = objectData;
		return true;
	}
	ObjectsDataMap.Add(objectData.UniqueId, objectData);
	return true;
}

bool USaveSlotManager::AddActorData(FActorData actorData)
{
	TArray<int32> Keys;
	ActorsDataMap.GenerateKeyArray(Keys);
	if (Keys.Contains(actorData.UniqueId))
	{
		ActorsDataMap[actorData.UniqueId] = actorData;
		return true;
	}
	ActorsDataMap.Add(actorData.UniqueId, actorData);
	return true;
}

bool USaveSlotManager::AddCharacterData(FCharacterData characterData)
{
	TArray<int32> Keys;
	CharacterDataMap.GenerateKeyArray(Keys);
	if (Keys.Contains(characterData.UniqueId))
	{
		CharacterDataMap[characterData.UniqueId] = characterData;
		return true;
	}
	CharacterDataMap.Add(characterData.UniqueId, characterData);
	return true;
}

bool USaveSlotManager::AddLevelData(FLevelData LevelData)
{
	TArray<int32> Keys;
	LevelDataMap.GenerateKeyArray(Keys);
	if (Keys.Contains(LevelData.UniqueId))
	{
		LevelDataMap[LevelData.UniqueId] = LevelData;
		return true;
	}
	LevelDataMap.Add(LevelData.UniqueId, LevelData);
	return true;
}

bool USaveSlotManager::AddGameInstanceData(FGameInstanceData gameinstanceData)
{
	TArray<int32> Keys;
	GameInstanceDataMap.GenerateKeyArray(Keys);
	if (Keys.Contains(gameinstanceData.UniqueId))
	{
		GameInstanceDataMap[gameinstanceData.UniqueId] = gameinstanceData;
		return true;
	}
	GameInstanceDataMap.Add(gameinstanceData.UniqueId, gameinstanceData);
	return true;
}

bool USaveSlotManager::AddGameModeData(FGameModeData gamemodeData)
{
	TArray<int32> Keys;
	GameModeDataMap.GenerateKeyArray(Keys);
	if (Keys.Contains(gamemodeData.UniqueId))
	{
		GameModeDataMap[gamemodeData.UniqueId] = gamemodeData;
		return true;
	}
	GameModeDataMap.Add(gamemodeData.UniqueId, gamemodeData);
	return true;
}

bool USaveSlotManager::AddGameStateData(FGameStateData gamestateData)
{
	TArray<int32> Keys;
	GameStateDataMap.GenerateKeyArray(Keys);
	if (Keys.Contains(gamestateData.UniqueId))
	{
		GameStateDataMap[gamestateData.UniqueId] = gamestateData;
		return true;
	}
	GameStateDataMap.Add(gamestateData.UniqueId, gamestateData);
	return true;
}

void USaveSlotManager::UpdateSaveData(FBaseData& Data, SAVESLOT_TYPE_DEFINE DataType)
{
	switch (DataType)
	{
	case  SAVESLOT_TYPE_DEFINE::OBJECT:
	{
		FObjectData* TempData = static_cast<FObjectData*>(&Data);
		AddObjectsData(*TempData);
		break;
	}
	case  SAVESLOT_TYPE_DEFINE::ACTOR:
	{
		FActorData* TempData1 = static_cast<FActorData*>(&Data);
		AddActorData(*TempData1);
		break;
	}
	case  SAVESLOT_TYPE_DEFINE::CHARACTER:
	{
		FCharacterData* TempData2 = static_cast<FCharacterData*>(&Data);
		AddCharacterData(*TempData2);
		break;
	}

	case  SAVESLOT_TYPE_DEFINE::LEVEL:
	{
		FLevelData* TempData3 = static_cast<FLevelData*>(&Data);
		AddLevelData(*TempData3);
		break;
	}
	case  SAVESLOT_TYPE_DEFINE::GAMEINSTANCE:
	{
		FGameInstanceData* TempData4 = static_cast<FGameInstanceData*>(&Data);
		AddGameInstanceData(*TempData4);
		break;
	}
	case  SAVESLOT_TYPE_DEFINE::GAMEMODE:
	{
		FGameModeData* TempData5 = static_cast<FGameModeData*>(&Data);
		AddGameModeData(*TempData5);
		break;
	}

	case  SAVESLOT_TYPE_DEFINE::GAMESTATE:
	{
		FGameStateData* TempData6 = static_cast<FGameStateData*>(&Data);
		AddGameStateData(*TempData6);
		break;
	}
	}
}

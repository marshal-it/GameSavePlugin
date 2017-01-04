// Fill out your copyright notice in the Description page of Project Settings.

#include "GameSavePluginPrivatePCH.h"
#include "SaveDataManager.h"

#if CODE_DEBUG == 1
#pragma optimize("",off) 
#endif // CODE_DEBUG

using namespace std;

USaveDataManager* USaveDataManager::Instance = nullptr;

void USaveDataManager::ExecuteGetSaveDataAsSlot(int32 Slot, int32 DataId, SAVESLOT_TYPE_DEFINE DataType)
{
	if (!SaveSlotManagerMap.Contains(Slot))
	{
		UE_LOG(SaveGame, Log, TEXT("Save Slot Index = %s not contained in map."), *FString::FormatAsNumber(Slot));
		return;
	}
	
	switch (DataType)
	{
	case SAVESLOT_TYPE_DEFINE::OBJECT:
	{
		if (SaveSlotManagerMap[Slot]->GetObjectDataMap().Contains(DataId))
		{
			FObjectData test = SaveSlotManagerMap[Slot]->GetObjectDataMap()[DataId];
			GetSaveDataAsSlot(Slot, SaveSlotManagerMap[Slot]->GetObjectDataMap()[DataId], DataType);
		}
		else
		{
			UE_LOG(SaveGame, Log, TEXT("Save Slot Index = %s . but DataId = %s is empty"), *FString::FormatAsNumber(Slot), *FString::FormatAsNumber(DataId));
		}
		break;
	}
	case SAVESLOT_TYPE_DEFINE::ACTOR:
	{
		if (SaveSlotManagerMap[Slot]->GetActorDataMap().Contains(DataId))
		{
			GetSaveDataAsSlot(Slot, SaveSlotManagerMap[Slot]->GetActorDataMap()[DataId], DataType);
		}
		else
		{
			UE_LOG(SaveGame, Log, TEXT("Save Slot Index = %s . but DataId = %s is empty"), *FString::FormatAsNumber(Slot), *FString::FormatAsNumber(DataId));
		}
		break;
	}
	case SAVESLOT_TYPE_DEFINE::CHARACTER:
	{
		if (SaveSlotManagerMap[Slot]->GetCharacterDataMap().Contains(DataId))
		{
			GetSaveDataAsSlot(Slot, SaveSlotManagerMap[Slot]->GetCharacterDataMap()[DataId], DataType);
		}
		else
		{
			UE_LOG(SaveGame, Log, TEXT("Save Slot Index = %s . but DataId = %s is empty"), *FString::FormatAsNumber(Slot), *FString::FormatAsNumber(DataId));
		}
		break;
	}
	case SAVESLOT_TYPE_DEFINE::LEVEL:
	{
		if (SaveSlotManagerMap[Slot]->GetLevelDataMap().Contains(DataId))
		{
			GetSaveDataAsSlot(Slot, SaveSlotManagerMap[Slot]->GetLevelDataMap()[DataId], DataType);
		}
		else
		{
			UE_LOG(SaveGame, Log, TEXT("Save Slot Index = %s . but DataId = %s is empty"), *FString::FormatAsNumber(Slot), *FString::FormatAsNumber(DataId));
		}
		break;
	}
	case SAVESLOT_TYPE_DEFINE::GAMEINSTANCE:
	{
		if (SaveSlotManagerMap[Slot]->GetGameInstanceDataMap().Contains(DataId))
		{
			GetSaveDataAsSlot(Slot, SaveSlotManagerMap[Slot]->GetGameInstanceDataMap()[DataId], DataType);
		}
		else
		{
			UE_LOG(SaveGame, Log, TEXT("Save Slot Index = %s . but DataId = %s is empty"), *FString::FormatAsNumber(Slot), *FString::FormatAsNumber(DataId));
		}
		break;
	}
	case SAVESLOT_TYPE_DEFINE::GAMEMODE:
	{
		if (SaveSlotManagerMap[Slot]->GetGameModeDataMap().Contains(DataId))
		{
			GetSaveDataAsSlot(Slot, SaveSlotManagerMap[Slot]->GetGameModeDataMap()[DataId], DataType);
		}
		else
		{
			UE_LOG(SaveGame, Log, TEXT("Save Slot Index = %s . but DataId = %s is empty"), *FString::FormatAsNumber(Slot), *FString::FormatAsNumber(DataId));
		}
		break;
	}
	case SAVESLOT_TYPE_DEFINE::GAMESTATE:
	{
		if (SaveSlotManagerMap[Slot]->GetGameStateDataMap().Contains(DataId))
		{
			GetSaveDataAsSlot(Slot, SaveSlotManagerMap[Slot]->GetGameStateDataMap()[DataId], DataType);
		}
		else
		{
			UE_LOG(SaveGame, Log, TEXT("Save Slot Index = %s . but DataId = %s is empty"), *FString::FormatAsNumber(Slot), *FString::FormatAsNumber(DataId));
		}
		break;
	}
	default:
		UE_LOG(SaveGame, Log, TEXT("Save Slot Index = %s . but DataType = %s is Invalid"), *FString::FormatAsNumber(Slot), *FString::FormatAsNumber(DataId));
		break;
	}
	
}

bool USaveDataManager::SaveGameSlot(int32 SlotIndex /*= 0*/)
{
	return SaveSlotManagerMap[SlotIndex]->SaveGameDataToCurrentSlot();
}

bool USaveDataManager::CheckSaveGameSlotExist(FString SlotName)
{
	return UGameplayStatics::DoesSaveGameExist(SlotName, 0);
}

UGameSaveInfo* USaveDataManager::LoadGameDateFromSlot(FString SlotName)
{
	USaveGame* SaveGameRef = UGameplayStatics::LoadGameFromSlot(SlotName, 0);

	if ( SaveGameRef != nullptr)
	{
		return Cast<UGameSaveInfo>(SaveGameRef);
	}
	return nullptr;
}

void USaveDataManager::UpdataSaveAsSlot(int32 Slot, FBaseData DataStruct, SAVESLOT_TYPE_DEFINE DataType)
{
	if (SaveSlotManagerMap.Contains(Slot))
	{
		SaveSlotManagerMap[Slot]->UpdateSaveData(DataStruct, DataType);
	}
	else
	{
		USaveSlotManager* SaveData = NewObject<USaveSlotManager>();
		SaveSlotManagerMap.Add(Slot, SaveData);
		SaveData->UpdateSaveData(DataStruct, DataType);
	}
}

USaveDataManager::USaveDataManager()
{

}

#if CODE_DEBUG == 1
#pragma optimize("",on)
#endif // CODE_DEBUG

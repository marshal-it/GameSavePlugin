// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include <string>
#include "SaveSlotType.h"
#include "SaveDataStruct.h"
#include "SaveSlotManager.h"
#include "SaveDataManager.generated.h"

/**
 *  数据管理入口
 */

//代理多播事件更新数据
/*
	Slot : 槽
	FBaseData : 更新的具体数据
	FString : 更新的数据类型
*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FUpdateSaveDataHandle, int32, Slot, FBaseData, DataStruct, SAVESLOT_TYPE_DEFINE, DataType);

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
			Instance->UpdateSaveDataHandle.AddDynamic(Instance, &USaveDataManager::UpdataSaveAsSlot);
		}
		return Instance;
	}

public:

	//更新数据
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "SaveData")
		FUpdateSaveDataHandle UpdateSaveDataHandle;

	template<typename T>
	UFUNCTION(BlueprintImplementableEvent, Category = "SaveData")
		void GetSaveDataAsSlot(int32& Slot, T& DataStruct, SAVESLOT_TYPE_DEFINE& DataType) {};

	//************************************
	// Method:    ExecuteGetSaveDataAsSlot
	// Parameter: FString Slot                                         确定是哪个存档
	// Parameter: int32 DataId                                        确定是存档里的数据类型中的具体数据
	// Parameter: SAVESLOT_TYPE_DEFINE DataType 确定存档中的数据类型
	//************************************
	UFUNCTION(BlueprintCallable, Category = "SaveData")
	void ExecuteGetSaveDataAsSlot(int32 Slot, int32 DataId, SAVESLOT_TYPE_DEFINE DataType);

	UFUNCTION(BlueprintCallable, Category = "SaveData")
	bool SaveGameSlot(int32 SlotIndex = 0);

	UFUNCTION(BlueprintCallable, Category = "SaveData")
	bool CheckSaveGameSlotExist(FString SlotName);

	UFUNCTION(BlueprintCallable, Category = "SaveData")
	UGameSaveInfo* LoadGameDateFromSlot(FString SlotName);


private:
	UFUNCTION()
	void UpdataSaveAsSlot(int32 Slot, FBaseData DataStruct, SAVESLOT_TYPE_DEFINE DataType);

private:
	USaveDataManager();
	~USaveDataManager()
	{
		Instance = nullptr;
		SaveSlotManagerMap.Empty();
	}
	static USaveDataManager* Instance;
	TMap<int32, USaveSlotManager*> SaveSlotManagerMap;
};

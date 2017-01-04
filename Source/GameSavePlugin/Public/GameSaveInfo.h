// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "SaveDataStruct.h"
#include "GameSaveInfo.generated.h"

/**
 * 保存数据对象类， 目前所有操作接口都已经默认在UGameplayStatics
 * 数据类型定义：关卡数据，角色数据，怪物数据，装备数据，天气数据
 * 数据关联对象（游戏结束之后，所有内存释放，需要根据保存的数据去初始化各个模块）
 * 每个保存新进度都对应必须数据文件，重置关卡除外！（1.save | 2.sav | 3.sav | .....）
 * 例如：
			 1.关卡数据：当前关卡，关卡进度，关卡配置
			 2.角色数据：角色等级，角色血量
			 3.怪物数据：当前怪物级别，怪物血量，怪物进度
			 4.装备数据：角色装备，装备掉落进度
			 5.环境天气：环境布局，环境进度
 */
//SlotName不允许重名，唯一存在，要不然会直接重置对象数据，但可以创建过个Slot对应在本地/Saved/SaveGames/SlotNameXX.sav

UCLASS()
class GAMESAVEPLUGIN_API UGameSaveInfo : public USaveGame
{
	GENERATED_BODY()
	
	/**
	*	@see UGameplayStatics::CreateSaveGameObject
	*	@see UGameplayStatics::SaveGameToSlot
	*	@see UGameplayStatics::DoesSaveGameExist
	*	@see UGameplayStatics::LoadGameFromSlot
	*	@see UGameplayStatics::DeleteGameInSlot
	*/

public:

	UFUNCTION(BlueprintCallable, Category = "SaveInfo")
	TArray<FObjectData> GetSaveDataObjectArray();

	UFUNCTION(BlueprintCallable, Category = "SaveInfo")
	TArray<FActorData> GetSaveDataActorArray();

	UFUNCTION(BlueprintCallable, Category = "SaveInfo")
	TArray<FCharacterData> GetSaveDataCharacterArray();

	UFUNCTION(BlueprintCallable, Category = "SaveInfo")
	TArray<FLevelData> GetSaveDataLevelArray();

	UFUNCTION(BlueprintCallable, Category = "SaveInfo")
	TArray<FGameInstanceData> GetSaveDataInstanceArray();

	UFUNCTION(BlueprintCallable, Category = "SaveInfo")
	TArray<FGameModeData> GetSaveDataModeArray();

	UFUNCTION(BlueprintCallable, Category = "SaveInfo")
	TArray<FGameStateData> GetSaveDataStateArray();

public:

	//内存对象数据
	UPROPERTY(BlueprintReadWrite)
	TMap<int32, FObjectData> ObjectsDataMap;

	//关卡实例对象数据
	UPROPERTY(BlueprintReadWrite)
	TMap<int32, FActorData> ActorsDataMap;

	//主角数据
	UPROPERTY(BlueprintReadWrite)
	TMap<int32, FCharacterData> CharacterDataMap;

	//关卡数据
	UPROPERTY(BlueprintReadWrite)
	TMap<int32, FLevelData> LevelDataMap;

	//游戏实例数据
	UPROPERTY(BlueprintReadWrite)
	TMap<int32, FGameInstanceData> GameInstanceDataMap;

	//游戏模式数据
	UPROPERTY(BlueprintReadWrite)
	TMap<int32, FGameModeData> GameModeDataMap;

	//游戏状态数据
	UPROPERTY(BlueprintReadWrite)
	TMap<int32, FGameStateData> GameStateDataMap;
};

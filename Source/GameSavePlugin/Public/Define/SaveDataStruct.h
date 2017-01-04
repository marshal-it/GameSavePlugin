// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SaveSlotType.h"
#include "SaveDataStruct.generated.h"

 /**
 * 保存数据的基本对象类型
 * UObject 、Actor
 * 对象属性：Transform、StaticMeshPath、SkeletaMeshPath、其他属性
 */

//基本的数据结构
USTRUCT()
struct FBaseData
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	int32 UniqueId; //独一ID
	UPROPERTY(BlueprintReadWrite)
	FString Name;   //名字
	UPROPERTY(BlueprintReadWrite)
	DataState Sate; //数据状态
	FBaseData()
		: UniqueId(0)
		, Name("") 
	    , Sate(DataState::Last){}
	void Reset() 
	{
		Name = "";
	}
};

//内存对象数据结构
/*
	主要是处理游戏过程保存一些在内存的游戏数据
*/
USTRUCT()
struct FObjectData : public FBaseData
{
	GENERATED_USTRUCT_BODY()
public:
	FObjectData()
		:Super() {}
};

//关卡实例对象数据模型
/*
	保存通过游戏中的Actor数据
*/
USTRUCT()
struct FActorData : public FObjectData
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	FTransform WorldTransform; //方位
	UPROPERTY(BlueprintReadWrite)
	bool bHideInGame; //是否显示
	UPROPERTY(BlueprintReadWrite)
	FString AssetPath; //资源路径
	FActorData()
		:Super()
	{
		WorldTransform = FTransform(FRotator::ZeroRotator, FVector::ZeroVector, FVector(1.0f));
		bHideInGame = true;
		AssetPath = "";
	}
};

//主角对象数据结构
/*
	保存主角产生的相关自身数据，属性变化等等
*/
USTRUCT()
struct  FCharacterData : public FActorData
{
	GENERATED_USTRUCT_BODY()
public:
	FCharacterData()
		:Super(){} 
};

//关卡数据结构
/*
	关卡中包含的所有动态的对象数据（模型数据，场景数据）
*/
USTRUCT()
struct FLevelData : public FObjectData
{
	GENERATED_USTRUCT_BODY()
public:
	FLevelData() {}
};

//游戏实例数据结构
/*
	游戏的实例，主要是持久化的数据
*/
USTRUCT()
struct FGameInstanceData : public FObjectData
{
	GENERATED_USTRUCT_BODY()
public:
	FGameInstanceData() {}
};

//游戏模式数据结构
/*
	游戏模式的数据，控制游戏的模式信息
*/
USTRUCT()
struct FGameModeData : public FActorData
{
	GENERATED_USTRUCT_BODY()
public:
	FGameModeData() {}
};

//游戏状态数据结构
/*
	保存游戏当前状态变化产生的数据
*/
USTRUCT()
struct FGameStateData : public FActorData
{
	GENERATED_USTRUCT_BODY()
public:
	FGameStateData() {}
};

 
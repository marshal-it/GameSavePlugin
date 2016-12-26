#pragma once
#include "EventDefineType.h"

EVENT_TYPE_STR_DECL(PLAYER);
EVENT_TYPE_STR_DECL(LEVEL);

//UENUM（对应事件枚举定义）
UENUM()
enum class SAVESLOT_TYPE_DEFINE : uint8
{
	PLAYER,
	LEVEL
};
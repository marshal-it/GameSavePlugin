﻿#pragma once
#include "EventDefineType.h"

EVENT_TYPE_STR_DECL(OBJECT);
EVENT_TYPE_STR_DECL(ACTOR);
EVENT_TYPE_STR_DECL(CHARACTER);
EVENT_TYPE_STR_DECL(LEVEL);
EVENT_TYPE_STR_DECL(GAMEINSTANCE);
EVENT_TYPE_STR_DECL(GAMEMODE);
EVENT_TYPE_STR_DECL(GAMESTATE);

//UENUM（对应事件枚举定义）
UENUM()
enum class SAVESLOT_TYPE_DEFINE : uint8
{
	OBJECT,
	ACTOR,
	CHARACTER,
	LEVEL,
	GAMEINSTANCE,
	GAMEMODE,
	GAMESTATE
};
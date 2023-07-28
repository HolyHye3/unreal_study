#pragma once

#include "info.h"

// 게임종류
enum class EMainMenu
{
	None,
	Battle,
	Stroe,
	Inventory,
	Exit
};

// 
bool GameInit(Store* store, Item* inventory);
void Run();

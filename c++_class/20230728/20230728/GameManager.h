#pragma once

#include "info.h"

// ��������
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

#pragma once

#include "Info.h"
#include "BattleManager.h"

enum class EMainMenu
{
	None,
	Battle,
	Store,
	Inventory,
	Exit
};

class CGameManger
{
public:
	CGameManger();
	~CGameManger();

private:
	CBattleManager* mBattleMgr;

private:
	EMainMenu Menu();

public:
	bool Init();
	void Run();
};


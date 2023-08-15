#pragma once

#include "info.h"

enum EBattleLevelMenu
{
	None,
	Easy,
	Nomal,
	Hard,
	Back
};

class CBattleManager
{
private:
	CBattleManager();
	~CBattleManager();

private:
	static CBattleManager* mInst;

public:
	static CBattleManager* GetInst()
	{
		if (mInst == nullptr)
			mInst = new CBattleManager;

		return mInst;
	}

	static CBattleManager* DestoryInst()
	{
		if (mInst != nullptr)
		{
			delete mInst;

			mInst = nullptr;
		}
	}

private:

private:
	EBattleLevelMenu Menu();

public:
	bool init();
	void Run();
	
};


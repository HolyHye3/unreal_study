#pragma once

#include "Info.h"

enum class EBattleMenu
{
	None,
	Attack,
	Back
};

enum class EBattleResult
{
	None,
	PlayerDeath,
	MonsterDeath
};

class CBattle
{
public:
	CBattle();
	~CBattle();

private:
	EBattleType mBattleType;

public:
	bool Init(EBattleType Type);
	void Run();
};


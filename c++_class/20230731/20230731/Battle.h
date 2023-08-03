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

private:
	EBattleMenu Menu();
	// 클래스 전방선언
	EBattleResult Attack(class CPlayer* Player, class CMonster* Monster);

public:
	bool Init(EBattleType Type);
	void Run();
};


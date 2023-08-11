#pragma once

#include "Singleton.h"

class CMonster:
	public CSingleton
{
public:
	CMonster();
	~CMonster();

public:
	int HP;
	int maxHp;
	int power;
	int defance;
	int exp;
	int money;

public:
	void Attack();
	int setExp();
	int setMoney();
};


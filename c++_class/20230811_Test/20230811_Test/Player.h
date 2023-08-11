#pragma once

#include "Singleton.h"

class Player:
	public CSingleton
{
public:
	int hp;
	int maxHp;
	int power;
	int defance;
	int exp;
	int money;

public:
	void Attack();
	int getExp();
	int getMoney();
};


#pragma once

#include <iostream>

enum class EItemType
{
	Weapon,
	Armor
};

struct Item
{
	char	Name[32];
	EItemType	Type;
	int		Price;
	int		Sell;
};

#define ITEMARRYA_MAXCOUNT	10

struct Store
{
	Item	ItemList[ITEMARRYA_MAXCOUNT];
	int		Count;
};
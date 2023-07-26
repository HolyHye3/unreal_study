#pragma once

#include <iostream>
#include <time.h>

enum class EMainMenu
{
	None,
	Bingo,
	Puzzle,
	Pair,
	Lotto,
	Exit
};

void Shuffle(int* Number, int Count);

EMainMenu MainMenu();
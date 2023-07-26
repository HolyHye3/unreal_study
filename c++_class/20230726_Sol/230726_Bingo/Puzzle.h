#pragma once

#include "Info.h"

void OutputPuzzleBoard(int* Number);
void Move(int* Number, int* StarIndex, int ChangeIndex);
bool IsComplete(int* Number);
void PuzzleMain();

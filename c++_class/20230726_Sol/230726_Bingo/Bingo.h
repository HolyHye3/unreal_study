#pragma once

#include "Info.h"

void OutputBingoBoard(int* Number);
bool ChangeNumber(int* Number, int Input);
int CheckLineHV(int* Number);
int CheckLineDiagonal(int* Number);
int CheckLine(int* Number);
void BingoMain();
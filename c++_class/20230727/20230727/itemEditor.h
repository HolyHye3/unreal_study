#pragma once

#include "info.h"

void CreateItem(Item* Array, int& Count);
void OutputItemList(Item* Array, int Count);
void SaveItemList(Item* Array, int Count);
void LoadItemList(Item* Array, int& Count);
void DeleteItemList(Item* Array, int& Count);
void ModifyItemList();
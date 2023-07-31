#pragma once

#include "info.h"

// 배열의 이름 자체는 주소이므로 포인터(주소를 담을 수 있는 변수)를 이용하여 전달.
// Count 값(레퍼런스) 자체를 바꾸어야하므로 주소값 자체를 전달
void CreateItem(Item* Array, int& Count);
void DeleteItem(Item* Array, int& Index);
void ModifyItem();
void OutputItem(Item* Array, int Index);
void SaveItem(Item* Array, int Index);
void LoadItem();

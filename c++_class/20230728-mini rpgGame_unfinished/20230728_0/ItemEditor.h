#pragma once

#include "info.h"

// �迭�� �̸� ��ü�� �ּ��̹Ƿ� ������(�ּҸ� ���� �� �ִ� ����)�� �̿��Ͽ� ����.
// Count ��(���۷���) ��ü�� �ٲپ���ϹǷ� �ּҰ� ��ü�� ����
void CreateItem(Item* Array, int& Count);
void DeleteItem(Item* Array, int& Index);
void ModifyItem();
void OutputItem(Item* Array, int Index);
void SaveItem(Item* Array, int Index);
void LoadItem();

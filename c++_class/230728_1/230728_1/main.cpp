
#include "GameManager.h"

int main()
{
	// ���������� ����Ǿ��ֱ� ������ �޸��ּҸ� ������ ���� ����.
	ItemArray	store = {};
	ItemArray	Inventory = {};
	Player	player = {};

	if (!GameInit(&store, &Inventory, &player))
		return 0;

	Run(&store, &Inventory, &player);

	Destroy(&store, &Inventory, &player);

	return 0;
}
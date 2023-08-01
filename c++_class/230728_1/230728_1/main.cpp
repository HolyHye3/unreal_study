
#include "GameManager.h"

int main()
{
	// 지역변수로 선언되어있기 때문에 메모리주소를 유지할 수가 없다.
	ItemArray	store = {};
	ItemArray	Inventory = {};
	Player	player = {};

	if (!GameInit(&store, &Inventory, &player))
		return 0;

	Run(&store, &Inventory, &player);

	Destroy(&store, &Inventory, &player);

	return 0;
}

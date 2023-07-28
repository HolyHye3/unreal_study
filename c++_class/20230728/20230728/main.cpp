#include "GameManager.h"

int main()
{
	Store store = {};
	Store Inventory = {};
	if (!GameInit(&store, &Inventory))
		return 0;

	Run();
	return 0;
}
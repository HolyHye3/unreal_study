#include "Store.h"

bool StoreInit(ItemArray* store)
{
	FILE* FileStream = nullptr;

	fopen_s(&FileStream, "ItemList.itl", "rb");

	if (!FileStream)
		return false;

	// (*store).
	// store->
	// 위의 2개의 접근방법은 같은 접근방법이다.
	fread(&store->Count, sizeof(int), 1, FileStream);

	for (int i = 0; i < store->Count; ++i)
	{
		Item	item = {};
		fread(&item, sizeof(Item), 1, FileStream);

		// 실제 사용할 아이템을 동적할당으로 생성한다.
		Item* StoreItem = new Item;

		// 위에서 파일로부터 읽어온 정보를 실제 사용할 아이템의 메모리에 복사해준다.
		memcpy(StoreItem, &item, sizeof(Item));

		store->ItemList[i] = StoreItem;
	}
	//fread(store->ItemList, sizeof(Item), store->Count, FileStream);

	fclose(FileStream);

    return true;
}

void StoreRun(ItemArray* store, ItemArray* Inventory, Player* player)
{
	while (true)
	{
		// 상점에서 사용할 수 있는 항목 목록을 표시하고 사용자 선택을 가져옴
		int Input = OutputItemList(store);

		if (Input == -1)
			continue;

		else if (Input == store->Count + 1)
			break;

		int	ItemIndex = Input - 1;

		// 인벤토리에 칸이 부족할 경우 추가할 수 없다.
		if (Inventory->Count == ITEMARRAY_MAXCOUNT)
		{
			std::cout << "가방의 공간이 부족합니다." << std::endl;
			system("pause");
			continue;
		}

		// 가지고 있는 돈보다 작은지 판단한다.
		else if (player->Money < store->ItemList[ItemIndex]->Price)
		{
			std::cout << "소지금이 부족합니다." << std::endl;
			system("pause");
			continue;
		}

		// 인벤토리에 아이템을 추가해준다.
		// 동적할당으로 Item크기 만큼 힙 영역에 공간을 만든다.
		Item* InvenItem = new Item;

		int Size = sizeof(Item);

		// InvenItem 변수에 ItemList 배열의 해당하는 인덱스 할당
		memcpy(InvenItem, store->ItemList[ItemIndex], sizeof(Item));

		// 새 아이템이 플레이어의 인벤토리에 추가되고 인벤토리의 아이템 수가 증가
		Inventory->ItemList[Inventory->Count] = InvenItem;
		++Inventory->Count;

		player->Money -= InvenItem->Price;
	}
}

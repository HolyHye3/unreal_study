#include "ItemEditor.h"

void CreateItem(Item* Array, int Index)
{
	system("cls");

	std::cout << "=========== 아이템 생성 ===========" << std::endl;

	std::cout << "이름: ";
	
	// 구조체 포인터는 -> 이용해서 참조하는 대상의 멤버에 접근할 수 있다.
	std::cin >> Array[Index].Name;

	std::cout << "1. 무기" << std::endl;
	std::cout << "2. 방어구" << std::endl;
	std::cout << "아이템 종류를 선택하세요: ";
	int ItemType = 0;

	std::cin >> ItemType;

	Array[Index].Type = EItemType(ItemType - 1);

	std::cout << "Price: ";
	std::cin >> Array[Index].Price;

	std::cout << "Sell: ";
	std::cin >> Array[Index].Sell;

}

void DeleteItem()
{
}

void ModifyItem()
{
}

void OutputItem()
{
}

void SaveItem()
{
}

void LoadItem()
{
}

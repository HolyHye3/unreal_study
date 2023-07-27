#include "itemEditor.h"

void CreateItem(Item* Array, int& Count)
{
	// Item* item = new Item;

	system("cls");
	std::cout << "============= 아이템 생성 =============" << std::endl;
	std::cout << "이름 : ";

	// 구조체 포인터는 -> 이용해서 참조하는 대상의 멤버에 접근할 수 있다.
	// std::cin >> item->Name;
	std::cin >> Array[Count].Name;

	system("cls");
	std::cout << "1. 무기" << std::endl;
	std::cout << "2. 방어구" << std::endl;
	std::cout << "아이템 종류를 선택하세요.: " << std::endl;

	int ItemType = 0;

	// 아이템 타입 설정
	std::cin >> ItemType;
	// item->Type = (EItemType)ItemType;
	Array[Count].Type = (EItemType)(ItemType-1);

	// 아이템 가격 설정
	std::cout << "Price : ";
	//std::cin >> item->Price;
	std::cin >> Array[Count].Price;
	
	// 아이템 판매 가격 설정
	std::cout << "Sell : ";
	//std::cin >> item->Sell;
	std::cin >> Array[Count].Sell;

	++Count;

}


void OutputItemList(Item* Array, int Count)
{
	for (int i = 0; i < Count; ++i)
	{
		std::cout << "이름: " << Array[i].Name << "\t종류: ";

		switch (Array[i].Type)
		{
		case EItemType::Weapon:
			std::cout << "무기\n";
			break;
		case EItemType::Armor:
			std::cout << "방어구\n";
			break;
		}

		std::cout << "Price : " << Array[i].Price << "\tSell: "
			<< Array[i].Sell << std::endl;

	}

	// 출력됨과 동시에 main으로 넘어가므로 잠시 멈춰준다.
	system("pause");
}

void SaveItemList(Item* Array, int Count)
{
	FILE* FileStream = nullptr;

	fopen_s(&FileStream, "ItemList.itl", "wb");

	if (FileStream)
	{
		fwrite(&Count, sizeof(Count), 1, FileStream);
		fwrite(Array, sizeof(Item), Count, FileStream);

		fclose(FileStream);
	}
}

void LoadItemList(Item* Array, int& Count)
{
	FILE* FileStream = nullptr;

	fopen_s(&FileStream, "ItemList.itl", "rb");

	if (FileStream)
	{
		fread(&Count, sizeof(Count), 1, FileStream);
		fread(Array, sizeof(Item), Count, FileStream);

		fclose(FileStream);
	}
}
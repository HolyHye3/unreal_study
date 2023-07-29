#include "ItemEditor.h"

void CreateItem(Item* Array, int& Count)
{
	system("cls");

	std::cout << "=========== 아이템 생성 ===========" << std::endl;

	std::cout << "이름: ";
	
	// 구조체 포인터는 -> 이용해서 참조하는 대상의 멤버에 접근할 수 있다.
	//std::cin >> item->Name;
	std::cin >> Array[Count].Name;

	std::cout << "1. 무기" << std::endl;
	std::cout << "2. 방어구" << std::endl;
	std::cout << "아이템 종류를 선택하세요: ";
	int ItemType = 0;

	std::cin >> ItemType;

	Array[Count].Type = EItemType(ItemType - 1);

	std::cout << "Price: ";
	std::cin >> Array[Count].Price;

	std::cout << "Sell: ";
	std::cin >> Array[Count].Sell;

	++Count;

}

void DeleteItem()
{
}

void ModifyItem()
{
}

void OutputItem(Item* Array, int Count)
{
	system("cls");
	for (int i = 0; i < Count; i++)
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

		std::cout << "Price: " << Array[i].Price << "\tSell: "
			<< Array[i].Sell << std::endl;
	}

	system("pause");
}

void SaveItem(Item* Array, int Count)
{
	FILE* FileStream = nullptr;

	// 파일 연결하기
	// 객체주소, 파일이름, 모드명 
	fopen_s(&FileStream, "ItemList.itl", "wb");


	if (FileStream)
	{
		// 카운트주소, 사이즈
		std::cout << "fwrite: \n";
		std::cout << &Count << sizeof(Count) << 1 << FileStream << std::endl;

		fwrite(&Count, sizeof(Count), 1, FileStream);
		fwrite(&Count, sizeof(Item), Count, FileStream);

		// 파일 연결해제해주기
		fclose(FileStream);
	}

	system("pause");
}

void LoadItem()
{
}

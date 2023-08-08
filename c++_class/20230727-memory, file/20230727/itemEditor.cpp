#include "itemEditor.h"

enum class ESearchType
{
	None,
	Name,
	Number,
	End
};

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
	// 0으로 초기화
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

void DeleteItemList(Item* Array, int& Count)
{
	ESearchType SearchType = ESearchType::None;
	
	// 탐색 종류 선택
	while (true)
	{
		system("cls");
		std::cout << "========== 아이템 제거 ==========" << std::endl;
		std::cout << "1. 이름 탐색" << std::endl;
		std::cout << "2. 번호 선택" << std::endl;
		std::cout << "메뉴를 선택하세요: " << std::endl;

		int Input = 0;
		std::cin >> Input;
		// 탐색 종류 안에서 선택했는지 체크
		if (Input > (int)ESearchType::None && Input < (int)ESearchType::End)
		{
			SearchType = (ESearchType)Input;
			break;
		}

	}

	// 제거할 아이템 선택
	system("cls");
	std::cout << "========== 아이템 제거 ==========" << std::endl;
	// 아이템 종류 출력
	for (int i = 0; i < Count; ++i)
	{
		std::cout << i + 1 << ". 이름: " << Array[i].Name << "\t종류: ";

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

	

	// 선택한 탐색 종류에 맞게 출력하고 입력받도록
	int DeleteIndex = -1;

	switch (SearchType)
	{
	case ESearchType::Name:
		std::cout << "이름을 입력하세요: ";
		char Name[32];
		std::cin >> Name;

		for (int i = 0; i < Count; i++)
		{
			// strcmp의 결과가 0일 경우 두 문자열은 같다.
			if (strcmp(Array[i].Name, Name) == 0)
			{
				DeleteIndex = i; // 삭제할 인덱스 번호 지정
				break;
			}
		}
		break;
	case ESearchType::Number:
		std::cout << "지울 번호를 선택하세요: ";
		std::cin >> DeleteIndex;

		// 1번부터 번호가 시작하고 있다. 이를 인덱스로 만들기 위해 1을 빼주어서 0부터 시작되는 인덱스로 만들어준다.
		--DeleteIndex;
		break;
	}

	// DeleteIndex가 -1이라면 잘못된 인덱스이다.
	if (DeleteIndex != -1)
	{
		memmove(&Array[DeleteIndex], &Array[DeleteIndex + 1],
			sizeof(Item) * (Count - DeleteIndex  1)
			)
		memset();
		memcpy();
		// for문 사용가능하지만 데이터 많아질 시 미친듯이 느려짐 가능성..
		for (int i = DeleteIndex; i < Count - 1; i++) {
			Array[i] = Array[i + 1];
		}

		--Count;
	}
	system("pause");
}
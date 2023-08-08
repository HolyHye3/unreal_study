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
	std::cout << "============= ������ ���� =============" << std::endl;
	std::cout << "�̸� : ";

	// ����ü �����ʹ� -> �̿��ؼ� �����ϴ� ����� ����� ������ �� �ִ�.
	// std::cin >> item->Name;
	std::cin >> Array[Count].Name;

	system("cls");
	std::cout << "1. ����" << std::endl;
	std::cout << "2. ��" << std::endl;
	std::cout << "������ ������ �����ϼ���.: " << std::endl;

	int ItemType = 0;

	// ������ Ÿ�� ����
	std::cin >> ItemType;
	// item->Type = (EItemType)ItemType;
	Array[Count].Type = (EItemType)(ItemType-1);

	// ������ ���� ����
	std::cout << "Price : ";
	//std::cin >> item->Price;
	std::cin >> Array[Count].Price;
	
	// ������ �Ǹ� ���� ����
	std::cout << "Sell : ";
	//std::cin >> item->Sell;
	std::cin >> Array[Count].Sell;

	++Count;

}


void OutputItemList(Item* Array, int Count)
{
	for (int i = 0; i < Count; ++i)
	{
		std::cout << "�̸�: " << Array[i].Name << "\t����: ";

		switch (Array[i].Type)
		{
		case EItemType::Weapon:
			std::cout << "����\n";
			break;
		case EItemType::Armor:
			std::cout << "��\n";
			break;
		}

		std::cout << "Price : " << Array[i].Price << "\tSell: "
			<< Array[i].Sell << std::endl;

	}

	// ��µʰ� ���ÿ� main���� �Ѿ�Ƿ� ��� �����ش�.
	system("pause");
}

void SaveItemList(Item* Array, int Count)
{
	// 0���� �ʱ�ȭ
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
	
	// Ž�� ���� ����
	while (true)
	{
		system("cls");
		std::cout << "========== ������ ���� ==========" << std::endl;
		std::cout << "1. �̸� Ž��" << std::endl;
		std::cout << "2. ��ȣ ����" << std::endl;
		std::cout << "�޴��� �����ϼ���: " << std::endl;

		int Input = 0;
		std::cin >> Input;
		// Ž�� ���� �ȿ��� �����ߴ��� üũ
		if (Input > (int)ESearchType::None && Input < (int)ESearchType::End)
		{
			SearchType = (ESearchType)Input;
			break;
		}

	}

	// ������ ������ ����
	system("cls");
	std::cout << "========== ������ ���� ==========" << std::endl;
	// ������ ���� ���
	for (int i = 0; i < Count; ++i)
	{
		std::cout << i + 1 << ". �̸�: " << Array[i].Name << "\t����: ";

		switch (Array[i].Type)
		{
		case EItemType::Weapon:
			std::cout << "����\n";
			break;
		case EItemType::Armor:
			std::cout << "��\n";
			break;
		}

		std::cout << "Price: " << Array[i].Price << "\tSell: "
			<< Array[i].Sell << std::endl;
	}

	

	// ������ Ž�� ������ �°� ����ϰ� �Է¹޵���
	int DeleteIndex = -1;

	switch (SearchType)
	{
	case ESearchType::Name:
		std::cout << "�̸��� �Է��ϼ���: ";
		char Name[32];
		std::cin >> Name;

		for (int i = 0; i < Count; i++)
		{
			// strcmp�� ����� 0�� ��� �� ���ڿ��� ����.
			if (strcmp(Array[i].Name, Name) == 0)
			{
				DeleteIndex = i; // ������ �ε��� ��ȣ ����
				break;
			}
		}
		break;
	case ESearchType::Number:
		std::cout << "���� ��ȣ�� �����ϼ���: ";
		std::cin >> DeleteIndex;

		// 1������ ��ȣ�� �����ϰ� �ִ�. �̸� �ε����� ����� ���� 1�� ���־ 0���� ���۵Ǵ� �ε����� ������ش�.
		--DeleteIndex;
		break;
	}

	// DeleteIndex�� -1�̶�� �߸��� �ε����̴�.
	if (DeleteIndex != -1)
	{
		memmove(&Array[DeleteIndex], &Array[DeleteIndex + 1],
			sizeof(Item) * (Count - DeleteIndex  1)
			)
		memset();
		memcpy();
		// for�� ��밡�������� ������ ������ �� ��ģ���� ������ ���ɼ�..
		for (int i = DeleteIndex; i < Count - 1; i++) {
			Array[i] = Array[i + 1];
		}

		--Count;
	}
	system("pause");
}
#include "ItemEditor.h"

void CreateItem(Item* Array, int& Count)
{
	system("cls");

	std::cout << "=========== ������ ���� ===========" << std::endl;

	std::cout << "�̸�: ";
	
	// ����ü �����ʹ� -> �̿��ؼ� �����ϴ� ����� ����� ������ �� �ִ�.
	//std::cin >> item->Name;
	std::cin >> Array[Count].Name;

	std::cout << "1. ����" << std::endl;
	std::cout << "2. ��" << std::endl;
	std::cout << "������ ������ �����ϼ���: ";
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

		std::cout << "Price: " << Array[i].Price << "\tSell: "
			<< Array[i].Sell << std::endl;
	}

	system("pause");
}

void SaveItem(Item* Array, int Count)
{
	FILE* FileStream = nullptr;

	// ���� �����ϱ�
	// ��ü�ּ�, �����̸�, ���� 
	fopen_s(&FileStream, "ItemList.itl", "wb");


	if (FileStream)
	{
		// ī��Ʈ�ּ�, ������
		std::cout << "fwrite: \n";
		std::cout << &Count << sizeof(Count) << 1 << FileStream << std::endl;

		fwrite(&Count, sizeof(Count), 1, FileStream);
		fwrite(&Count, sizeof(Item), Count, FileStream);

		// ���� �����������ֱ�
		fclose(FileStream);
	}

	system("pause");
}

void LoadItem()
{
}

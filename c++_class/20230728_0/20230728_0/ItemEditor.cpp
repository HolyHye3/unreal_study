#include "ItemEditor.h"

void CreateItem(Item* Array, int Index)
{
	system("cls");

	std::cout << "=========== ������ ���� ===========" << std::endl;

	std::cout << "�̸�: ";
	
	// ����ü �����ʹ� -> �̿��ؼ� �����ϴ� ����� ����� ������ �� �ִ�.
	std::cin >> Array[Index].Name;

	std::cout << "1. ����" << std::endl;
	std::cout << "2. ��" << std::endl;
	std::cout << "������ ������ �����ϼ���: ";
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

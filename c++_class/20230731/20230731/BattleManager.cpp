#include "BattleManager.h"

// ���� �Ŵ��� ������
CBattleManager::CBattleManager()
{
	

}

// ���� �Ŵ��� �Ҹ���
CBattleManager::~CBattleManager()
{
}

// ���� �Ŵ��� �޴� ȣ���ϱ��Լ�
EBattleMenu CBattleManager::Menu()
{
	system("cls");
	std::cout << "1. ���� " << std::endl;
	std::cout << "2. ���� " << std::endl;
	std::cout << "3. ����� " << std::endl;
	std::cout << "4. �ڷΰ���" << std::endl;
	std::cout << "�޴��� �����ϼ��� : " << std::endl;

	int Input;

	std::cin >> Input;

	if (Input <= (int)EBattleMenu::None ||
		Input > (int)EBattleMenu::Back)
		return EBattleMenu::None;

	return (EBattleMenu)Input;
}

bool CBattleManager::Init()
{
	return false;
}

void CBattleManager::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EBattleMenu::None:
			break;
		case EBattleMenu::Easy:
			break;
		case EBattleMenu::Normal:
			break;
		case EBattleMenu::Hard:
			break;
		case EBattleMenu::Back:
			break;
		}
	}
}

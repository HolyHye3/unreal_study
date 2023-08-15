#include "GameManager.h"
#include "BattleManager.h"

// �ν��Ͻ� �޸��ּ� null�� �ʱ�ȭ
CGameManager* CGameManager::mInst = nullptr;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
}

EMainMenu CGameManager::Menu()
{
	system("cls");
	std::cout << "1. ����" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. ����" << std::endl;
	std::cout << "4. ����" << std::endl;
	std::cout << "�޴��� �����ϼ���";

	int Input;

	std::cin >> Input;

	if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
		return EMainMenu::None;
	

	return (EMainMenu)Input;
}

bool CGameManager::Init()
{
	// ���� ������ �ν��Ͻ� ������ �ʱ�ȭ
	//CBattleManager::GetInst();

	return true;
	
}

void CGameManager::Run()
{
	switch (Menu())
	{
	case EMainMenu::Battle:
		// ���������� �ν��Ͻ� ������ ����
		CBattleManager::GetInst()->Run();
		break;
	case EMainMenu::Store:
		break;
	case EMainMenu::Inventory:
		break;
	case EMainMenu::Exit:
		return;
	}

}
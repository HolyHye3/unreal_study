#include "GameManger.h"

// ���� �Ŵ��� ������
CGameManger::CGameManger():
	mBattleMgr(nullptr) //0
{
}

// ���� �Ŵ��� �Ҹ���
// �޸𸮰� ���Ű� �� �� �ڵ����� ȣ��ȴ�.
CGameManger::~CGameManger()
{
	if (mBattleMgr)
	{
		delete mBattleMgr;
		mBattleMgr = nullptr;
	}
}

EMainMenu CGameManger::Menu()
{
	system("cls");
	std::cout << "1. ����" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. ����" << std::endl;
	std::cout << "4. ����" << std::endl;
	std::cout << "�޴��� �����ϼ���: ";

	int Input;

	std::cin >> Input;

	if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
		return EMainMenu::None;

	return (EMainMenu)Input;
}

bool CGameManger::Init()
{
	// ���� ������ Ŭ���� ������ �ʱ�ȭ
	mBattleMgr = new CBattleManager;

	// ����ü �����ʹ� -> �̿��ؼ� �����ϴ� ����� ����� ������ �� �ִ�.
	if (!mBattleMgr->Init())
		return false;

	return true;
}

void CGameManger::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EMainMenu::Battle:
			mBattleMgr->Run();
			break;
		case EMainMenu::Store:
			break;
		case EMainMenu::Inventory:
			break;
		case EMainMenu::Exit:
			return;
		}
	}
}

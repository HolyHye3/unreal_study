#include "GameManager.h"
#include "BattleManager.h"

// 인스턴스 메모리주소 null로 초기화
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
	std::cout << "1. 전투" << std::endl;
	std::cout << "2. 상점" << std::endl;
	std::cout << "3. 가방" << std::endl;
	std::cout << "4. 종료" << std::endl;
	std::cout << "메뉴를 선택하세요";

	int Input;

	std::cin >> Input;

	if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
		return EMainMenu::None;
	

	return (EMainMenu)Input;
}

bool CGameManager::Init()
{
	// 전투 관리자 인스턴스 생성과 초기화
	//CBattleManager::GetInst();

	return true;
	
}

void CGameManager::Run()
{
	switch (Menu())
	{
	case EMainMenu::Battle:
		// 전투관리자 인스턴스 생성과 실행
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
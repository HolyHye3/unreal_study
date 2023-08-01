#include "BattleManager.h"

// 전투 매니저 생성자
CBattleManager::CBattleManager()
{
	

}

// 전투 매니저 소멸자
CBattleManager::~CBattleManager()
{
}

// 전투 매니저 메뉴 호출하기함수
EBattleMenu CBattleManager::Menu()
{
	system("cls");
	std::cout << "1. 쉬움 " << std::endl;
	std::cout << "2. 보통 " << std::endl;
	std::cout << "3. 어려움 " << std::endl;
	std::cout << "4. 뒤로가기" << std::endl;
	std::cout << "메뉴를 선택하세요 : " << std::endl;

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

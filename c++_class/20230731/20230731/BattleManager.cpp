#include "BattleManager.h"
// 실제 Battle 클래스를 사용해야 하기 때문에 include를 해준다.
#include "Battle.h"

// 포인터변수 선언 후 nullptr로 초기화
CBattleManager* CBattleManager::mInst = nullptr;

// 전투 매니저 생성자
CBattleManager::CBattleManager():
	mBattle{}
{
	

}

// 전투 매니저 소멸자
CBattleManager::~CBattleManager()
{
}

// 전투 매니저 메뉴 호출하기함수
EBattleLevelMenu CBattleManager::Menu()
{
	system("cls");
	std::cout << "1. 쉬움 " << std::endl;
	std::cout << "2. 보통 " << std::endl;
	std::cout << "3. 어려움 " << std::endl;
	std::cout << "4. 뒤로가기" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";

	int Input;

	std::cin >> Input;

	if (Input <= (int)EBattleLevelMenu::None ||
		Input > (int)EBattleLevelMenu::Back)
		return EBattleLevelMenu::None;

	return (EBattleLevelMenu)Input;
}

bool CBattleManager::Init()
{
	// 전투 3개를 모두 생성해둔다.
	for (int i = 0; i < 3; i++)
	{
		mBattle[i] = new CBattle;

		mBattle[i]->Init((EBattleType)i);
	}

	return true;
}

void CBattleManager::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EBattleLevelMenu::Easy:
			mBattle[0]->Run();
			break;
		case EBattleLevelMenu::Normal:
			mBattle[1]->Run();
			break;
		case EBattleLevelMenu::Hard:
			mBattle[2]->Run();
			return;
		}
	}
}

#include "BattleManager.h"

CBattleManager* CBattleManager::mInst = nullptr;

CBattleManager::CBattleManager()
{
}

CBattleManager::~CBattleManager()
{
}

EBattleLevelMenu CBattleManager::Menu()
{
    system("cls");
    std::cout << "1. 쉬움" << std::endl;
    std::cout << "2. 보통" << std::endl;
    std::cout << "3. 어려움" << std::endl;
    std::cout << "4. 뒤로가기" << std::endl;

    int Input;

    std::cin >> Input;

    if (Input <= (int)EBattleLevelMenu::None || Input > (int)EBattleLevelMenu::Back)
        return EBattleLevelMenu::None;

    return (EBattleLevelMenu)Input;
}

bool CBattleManager::init()
{
    // 전투 3개를 모두 생성해둔다.
    for (int i = 0; i < 3;i++) {
        std::cout << i << std::endl;
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
            break;
        case EBattleLevelMenu::Nomal:
            break;
        case EBattleLevelMenu::Hard:
            break;
        case EBattleLevelMenu::Back:
            return;
        }
    }
    
  
}

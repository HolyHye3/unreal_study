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
    std::cout << "1. ����" << std::endl;
    std::cout << "2. ����" << std::endl;
    std::cout << "3. �����" << std::endl;
    std::cout << "4. �ڷΰ���" << std::endl;

    int Input;

    std::cin >> Input;

    if (Input <= (int)EBattleLevelMenu::None || Input > (int)EBattleLevelMenu::Back)
        return EBattleLevelMenu::None;

    return (EBattleLevelMenu)Input;
}

bool CBattleManager::init()
{
    // ���� 3���� ��� �����صд�.
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

#include "GameManager.h"
#include "Stor.h"

bool GameInit(Store* store, Item* inventory)
{
    // 상점 초기화
    

    return true;
}

EMainMenu Menu()
{
    system("cls");
    std::cout << "1. 전투" << std::endl;
    std::cout << "2. 상점" << std::endl;
    std::cout << "3. 가방" << std::endl;
    std::cout << "4. 종료" << std::endl;
    std::cout << "메뉴를 선택하세요: " << std::endl;

    int Input;

    std::cin >> Input;

    if (Input < (int)EMainMenu::None || Input>(int)EMainMenu::Exit)
    {

    }
}

void Run()
{
    while (true)
    {
        switch (Menu())
        {
        case EMainMenu::Battle:
            break;
        case EMainMenu::Stroe:
            break;
        case EMainMenu::Inventory:
            break;
        case EMainMenu::Exit:
            break;
        }
    }



}

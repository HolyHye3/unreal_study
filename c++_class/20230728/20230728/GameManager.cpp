#include "GameManager.h"
#include "Stor.h"

bool GameInit(Store* store, Item* inventory)
{
    // ���� �ʱ�ȭ
    

    return true;
}

EMainMenu Menu()
{
    system("cls");
    std::cout << "1. ����" << std::endl;
    std::cout << "2. ����" << std::endl;
    std::cout << "3. ����" << std::endl;
    std::cout << "4. ����" << std::endl;
    std::cout << "�޴��� �����ϼ���: " << std::endl;

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

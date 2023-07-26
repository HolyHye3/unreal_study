
#include "Info.h"


void Shuffle(int* Number, int Count)
{
	for (int i = 0; i < 100; ++i)
	{
		int	Index1 = rand() % Count;
		int	Index2 = rand() % Count;

		int	Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}
}



EMainMenu MainMenu()
{
	system("cls");
	std::cout << "1. 빙고" << std::endl;
	std::cout << "2. 퍼즐" << std::endl;
	std::cout << "3. 짝맞추기" << std::endl;
	std::cout << "4. 로또" << std::endl;
	std::cout << "5. 종료" << std::endl;
	std::cout << "게임을 선택하세요 : ";
	int	Input;
	std::cin >> Input;

	// 1 ~ 5 사이의 값이 아닌 잘못 입력된 값일 경우 
	// EMainMenu::None을 리턴한다.
	if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
		return EMainMenu::None;

	return (EMainMenu)Input;
}

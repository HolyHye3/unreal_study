
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
	std::cout << "1. ����" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. ¦���߱�" << std::endl;
	std::cout << "4. �ζ�" << std::endl;
	std::cout << "5. ����" << std::endl;
	std::cout << "������ �����ϼ��� : ";
	int	Input;
	std::cin >> Input;

	// 1 ~ 5 ������ ���� �ƴ� �߸� �Էµ� ���� ��� 
	// EMainMenu::None�� �����Ѵ�.
	if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
		return EMainMenu::None;

	return (EMainMenu)Input;
}

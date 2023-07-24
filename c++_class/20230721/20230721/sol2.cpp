
#include <iostream>
#include <time.h>

// _getch() 를 이용하기 위해 추가했다.
#include <conio.h>

/*
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 *

0으로 표시된 부분에 1 ~ 24 사이의 숫자를 섞어서 출력한다.
플레이어는 * 표시를 움직여줄 수 있다.
w : 위로 이동 s : 아래로 이동 a : 왼쪽 이동 d : 오른쪽 이동 q : 종료

이동 키를 누르면 해당 방향에 있는 값과 *의 위치를 변경해주고 숫자가 왼쪽 위부터
차례대로 1 ~ 24 까지 나오면 게임을 종료한다.
*/

int main()
{
	srand((unsigned int)time(0));
	rand();

	int	Number[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		Number[i] = i + 1;
	}

	Number[24] = INT_MAX;

	// 24번 인덱스를 제외하고 0 ~ 23번 인덱스를 섞어준다.
	for (int i = 0; i < 100; ++i)
	{
		int	Index1 = rand() % 24;
		int	Index2 = rand() % 24;

		int	Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	char	Input;
	int	StarIndex = 24;

	while (true)
	{
		system("cls");
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				int	Index = i * 5 + j;

				if (Number[Index] == INT_MAX)
					std::cout << "*\t";

				else
					std::cout << Number[Index] << "\t";
			}

			std::cout << std::endl;
		}

		std::cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료 : ";
		Input = _getch();

		if (Input == 'q' || Input == 'Q')
			break;

		switch (Input)
		{
		case 'w':
		case 'W':
			if (StarIndex >= 5)
			{
				// 위 인덱스를 구한다.
				int	Index = StarIndex - 5;

				// 두 값을 바꿔준다.
				int	Temp = Number[StarIndex];
				Number[StarIndex] = Number[Index];
				Number[Index] = Temp;

				StarIndex = Index;
			}
			break;
		case 's':
		case 'S':
			if (StarIndex <= 19)
			{
				// 위 인덱스를 구한다.
				int	Index = StarIndex + 5;

				// 두 값을 바꿔준다.
				int	Temp = Number[StarIndex];
				Number[StarIndex] = Number[Index];
				Number[Index] = Temp;

				StarIndex = Index;
			}
			break;
		case 'a':
		case 'A':
			if (StarIndex % 5 != 0)
			{
				// 위 인덱스를 구한다.
				int	Index = StarIndex - 1;

				// 두 값을 바꿔준다.
				int	Temp = Number[StarIndex];
				Number[StarIndex] = Number[Index];
				Number[Index] = Temp;

				StarIndex = Index;
			}
			break;
		case 'd':
		case 'D':
			if (StarIndex % 5 != 4)
			{
				// 위 인덱스를 구한다.
				int	Index = StarIndex + 1;

				// 두 값을 바꿔준다.
				int	Temp = Number[StarIndex];
				Number[StarIndex] = Number[Index];
				Number[Index] = Temp;

				StarIndex = Index;
			}
			break;
		}

		// 24개의 숫자중 1 ~ 24가 다 들어가 있으면 true가 유지될 것이고
		// 하나라도 연속된 숫자가 아니라면 false가 될것이다.
		bool Complete = true;

		for (int i = 0; i < 24; ++i)
		{
			if (Number[i] != i + 1)
			{
				Complete = false;
				break;
			}
		}

		if (Complete)
			break;
	}

	return 0;
}


#include "Puzzle.h"
#include <conio.h>

void OutputPuzzleBoard(int* Number)
{
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
}

void Move(int* Number, int* StarIndex, int ChangeIndex)
{
	// 두 값을 바꿔준다.
	int	Temp = Number[*StarIndex];
	Number[*StarIndex] = Number[ChangeIndex];
	Number[ChangeIndex] = Temp;

	*StarIndex = ChangeIndex;
}

bool IsComplete(int* Number)
{
	for (int i = 0; i < 24; ++i)
	{
		if (Number[i] != i + 1)
		{
			return false;
		}
	}

	return true;
}

void PuzzleMain()
{
	int	Number[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		Number[i] = i + 1;
	}

	Number[24] = INT_MAX;

	Shuffle(Number, 24);


	char	Input;
	int	StarIndex = 24;

	while (true)
	{
		system("cls");
		OutputPuzzleBoard(Number);

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

				Move(Number, &StarIndex, Index);
			}
			break;
		case 's':
		case 'S':
			if (StarIndex <= 19)
			{
				// 위 인덱스를 구한다.
				int	Index = StarIndex + 5;

				Move(Number, &StarIndex, Index);
			}
			break;
		case 'a':
		case 'A':
			if (StarIndex % 5 != 0)
			{
				// 위 인덱스를 구한다.
				int	Index = StarIndex - 1;

				Move(Number, &StarIndex, Index);
			}
			break;
		case 'd':
		case 'D':
			if (StarIndex % 5 != 4)
			{
				// 위 인덱스를 구한다.
				int	Index = StarIndex + 1;

				Move(Number, &StarIndex, Index);
			}
			break;
		}

		// 24개의 숫자중 1 ~ 24가 다 들어가 있으면 true가 유지될 것이고
		// 하나라도 연속된 숫자가 아니라면 false가 될것이다.
		if (IsComplete(Number))
			break;
	}
}
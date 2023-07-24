
#include <iostream>
#include <time.h>

// _getch() �� �̿��ϱ� ���� �߰��ߴ�.
#include <conio.h>

/*
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 *

0���� ǥ�õ� �κп� 1 ~ 24 ������ ���ڸ� ��� ����Ѵ�.
�÷��̾�� * ǥ�ø� �������� �� �ִ�.
w : ���� �̵� s : �Ʒ��� �̵� a : ���� �̵� d : ������ �̵� q : ����

�̵� Ű�� ������ �ش� ���⿡ �ִ� ���� *�� ��ġ�� �������ְ� ���ڰ� ���� ������
���ʴ�� 1 ~ 24 ���� ������ ������ �����Ѵ�.
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

	// 24�� �ε����� �����ϰ� 0 ~ 23�� �ε����� �����ش�.
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

		std::cout << "w : �� s : �Ʒ� a : ���� d : ������ q : ���� : ";
		Input = _getch();

		if (Input == 'q' || Input == 'Q')
			break;

		switch (Input)
		{
		case 'w':
		case 'W':
			if (StarIndex >= 5)
			{
				// �� �ε����� ���Ѵ�.
				int	Index = StarIndex - 5;

				// �� ���� �ٲ��ش�.
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
				// �� �ε����� ���Ѵ�.
				int	Index = StarIndex + 5;

				// �� ���� �ٲ��ش�.
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
				// �� �ε����� ���Ѵ�.
				int	Index = StarIndex - 1;

				// �� ���� �ٲ��ش�.
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
				// �� �ε����� ���Ѵ�.
				int	Index = StarIndex + 1;

				// �� ���� �ٲ��ش�.
				int	Temp = Number[StarIndex];
				Number[StarIndex] = Number[Index];
				Number[Index] = Temp;

				StarIndex = Index;
			}
			break;
		}

		// 24���� ������ 1 ~ 24�� �� �� ������ true�� ������ ���̰�
		// �ϳ��� ���ӵ� ���ڰ� �ƴ϶�� false�� �ɰ��̴�.
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

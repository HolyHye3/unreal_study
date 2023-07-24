
#include <iostream>
#include <time.h>

/*
5x5 로 출력.
숫자 1 ~ 25 사이의 값을 랜덤하게 섞어서 출력한다.
사용자는 숫자 1개를 입력하고 0을 입력하면 종료
1 ~ 25 사이의 숫자를 입력하면 해당 숫자를 찾아서 *로
출력되게 만든다. 나머지 숫자부분들은 해당 숫자 그대로 출력한다.

줄 체크를 한다. 가로 5줄 세로 5줄 대각선 2줄이 나온다.
이중 몇줄을 완성했는지 매번 체크하여 5줄 이상을 완성했을 경우
게임을 종료한다.
*/

int main()
{
	srand((unsigned int)time(0));
	rand();

	int	Number[25] = {};

	// 0 ~ 24번 인덱스에 1 ~ 25까지 값을 차례대로 넣어준다.
	for (int i = 0; i < 25; ++i)
	{
		Number[i] = i + 1;
	}

	for (int i = 0; i < 100; ++i)
	{
		int	Index1 = rand() % 25;
		int	Index2 = rand() % 25;

		int	Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	int	Input = 0;
	int	LineCount = 0;

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

		std::cout << "Line : " << LineCount << std::endl;
		std::cout << "숫자를 입력하세요(0 : 종료) : ";
		std::cin >> Input;

		if (Input == 0)
			break;

		else if (Input < 0 || Input > 25)
			continue;

		// 입력받은 숫자를 배열에서 찾아서 *로 바꿔준다.
		for (int i = 0; i < 25; ++i)
		{
			// 입력받은 숫자와 같은 숫자가 배열에 있을 경우
			if (Number[i] == Input)
			{
				// INT_MAX는 int값으로 표현할 수 있는 가장 큰 값이다.
				// 이 값일 경우 *로 판단하여 출력할 때 *로 출력한다.
				Number[i] = INT_MAX;

				// 숫자를 찾아서 *로 바꿨으면 더이상 검사할 필요가
				// 없기 때문에 for문을 빠져나간다.
				break;
			}
		}

		// 줄을 체크하기 전에 LineCount를 0으로 초기화하고
		// 매번 12줄 모두 새롭게 체크를 해준다.
		LineCount = 0;

		int	CheckCount = 0, CheckCount1 = 0;

		for (int i = 0; i < 5; ++i)
		{
			// i = 0, Index = 0, 1, 2, 3, 4
			// i = 1, Index = 5, 6, 7, 8, 9
			// 위와 같이 가로 한줄로 인덱스가 나오기 때문에
			// j for문이 5번 반복하면 가로 1줄을 체크하는 것이다.
			// j for문이 5번 반복될때 체크하는 숫자가 모두 * 이라면
			// 그 줄은 완성된 것이다.
			// 줄을 시작하기 전에 그 줄의 * 수를 카운트 하기 위한 변수를
			// 0으로 초기화하고 시작한다.
			CheckCount = 0;
			CheckCount1 = 0;

			for (int j = 0; j < 5; ++j)
			{
				if (Number[i * 5 + j] == INT_MAX)
					++CheckCount;


				if (Number[j * 5 + i] == INT_MAX)
					++CheckCount1;
			}

			// j for문이 완료되고 CheckCount의 값이 5라면 모두 * 로 변경된
			// 숫자라는 것이다.
			if (CheckCount == 5)
				++LineCount;

			if (CheckCount1 == 5)
				++LineCount;
		}

		// 왼쪽상단->오른쪽하단 대각선
		// 0 부터 시작해서 6씩 값이 증가한다.
		CheckCount = 0;
		for (int i = 0; i < 5; ++i)
		{
			if (Number[i * 6] == INT_MAX)
				++CheckCount;
		}

		if (CheckCount == 5)
			++LineCount;

		// 오른쪽 상단 -> 왼쪽 하단 대각선
		CheckCount = 0;

		for (int i = 1; i <= 5; ++i)
		{
			if (Number[i * 4] == INT_MAX)
				++CheckCount;
		}

		if (CheckCount == 5)
			++LineCount;
	}

	return 0;
}


#include "Bingo.h"

void OutputBingoBoard(int* Number)
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

bool ChangeNumber(int* Number, int Input)
{
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
			// 없기 때문에 함수를 빠져나간다.
			return true;
		}
	}

	// 입력받은 숫자가 없을 경우
	return false;
}

int CheckLineHV(int* Number)
{
	int	LineCount = 0;
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

	return LineCount;
}

int CheckLineDiagonal(int* Number)
{
	// 왼쪽상단->오른쪽하단 대각선
	// 0 부터 시작해서 6씩 값이 증가한다.
	int CheckCount = 0, LineCount = 0;
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

	return LineCount;
}

int CheckLine(int* Number)
{
	int	LineCount = CheckLineHV(Number);
	LineCount += CheckLineDiagonal(Number);

	return LineCount;
}

void BingoMain()
{
	// 빙고판을 만들기 위한 숫자 배열을 선언한다.
	int	Number[25] = {};

	// 0 ~ 24번 인덱스에 1 ~ 25까지 값을 차례대로 넣어준다.
	for (int i = 0; i < 25; ++i)
	{
		Number[i] = i + 1;
	}

	Shuffle(Number, 25);

	int	Input = 0;
	int	LineCount = 0;

	while (true)
	{
		system("cls");
		OutputBingoBoard(Number);

		std::cout << "Line : " << LineCount << std::endl;
		std::cout << "숫자를 입력하세요(0 : 종료) : ";
		std::cin >> Input;

		if (Input == 0)
			break;

		else if (Input < 0 || Input > 25)
			continue;

		if (ChangeNumber(Number, Input) == false)
		{
			continue;
		}

		// 줄을 체크하기 전에 LineCount를 0으로 초기화하고
		// 매번 12줄 모두 새롭게 체크를 해준다.
		LineCount = CheckLine(Number);
	}
}

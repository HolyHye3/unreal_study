
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
	// �Է¹��� ���ڸ� �迭���� ã�Ƽ� *�� �ٲ��ش�.
	for (int i = 0; i < 25; ++i)
	{
		// �Է¹��� ���ڿ� ���� ���ڰ� �迭�� ���� ���
		if (Number[i] == Input)
		{
			// INT_MAX�� int������ ǥ���� �� �ִ� ���� ū ���̴�.
			// �� ���� ��� *�� �Ǵ��Ͽ� ����� �� *�� ����Ѵ�.
			Number[i] = INT_MAX;

			// ���ڸ� ã�Ƽ� *�� �ٲ����� ���̻� �˻��� �ʿ䰡
			// ���� ������ �Լ��� ����������.
			return true;
		}
	}

	// �Է¹��� ���ڰ� ���� ���
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
		// ���� ���� ���� ���ٷ� �ε����� ������ ������
		// j for���� 5�� �ݺ��ϸ� ���� 1���� üũ�ϴ� ���̴�.
		// j for���� 5�� �ݺ��ɶ� üũ�ϴ� ���ڰ� ��� * �̶��
		// �� ���� �ϼ��� ���̴�.
		// ���� �����ϱ� ���� �� ���� * ���� ī��Ʈ �ϱ� ���� ������
		// 0���� �ʱ�ȭ�ϰ� �����Ѵ�.
		CheckCount = 0;
		CheckCount1 = 0;

		for (int j = 0; j < 5; ++j)
		{
			if (Number[i * 5 + j] == INT_MAX)
				++CheckCount;


			if (Number[j * 5 + i] == INT_MAX)
				++CheckCount1;
		}

		// j for���� �Ϸ�ǰ� CheckCount�� ���� 5��� ��� * �� �����
		// ���ڶ�� ���̴�.
		if (CheckCount == 5)
			++LineCount;

		if (CheckCount1 == 5)
			++LineCount;
	}

	return LineCount;
}

int CheckLineDiagonal(int* Number)
{
	// ���ʻ��->�������ϴ� �밢��
	// 0 ���� �����ؼ� 6�� ���� �����Ѵ�.
	int CheckCount = 0, LineCount = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (Number[i * 6] == INT_MAX)
			++CheckCount;
	}

	if (CheckCount == 5)
		++LineCount;

	// ������ ��� -> ���� �ϴ� �밢��
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
	// �������� ����� ���� ���� �迭�� �����Ѵ�.
	int	Number[25] = {};

	// 0 ~ 24�� �ε����� 1 ~ 25���� ���� ���ʴ�� �־��ش�.
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
		std::cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
		std::cin >> Input;

		if (Input == 0)
			break;

		else if (Input < 0 || Input > 25)
			continue;

		if (ChangeNumber(Number, Input) == false)
		{
			continue;
		}

		// ���� üũ�ϱ� ���� LineCount�� 0���� �ʱ�ȭ�ϰ�
		// �Ź� 12�� ��� ���Ӱ� üũ�� ���ش�.
		LineCount = CheckLine(Number);
	}
}

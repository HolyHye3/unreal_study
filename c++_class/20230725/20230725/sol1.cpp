
#include <iostream>
#include <time.h>

// _getch() �� �̿��ϱ� ���� �߰��ߴ�.
#include <conio.h>

/*
�Լ��� ����� ���Ƿ� �и��� �� �ִ�.
�Լ��� ���� : ��ȯŸ�� �Լ���(����Ÿ��); �̷��� ������ �� �ִ�.
*/
//void Shuffle(int*);
void Shuffle(int* Number);
void OutputBoard(int* Number);
void Move(int* Number, int* StarIndex, int ChangeIndex);
bool IsComplete(int* Number);

int main()
{
    srand((unsigned int)time(0));
    rand();

    int   Number[25] = {};

    for (int i = 0; i < 24; ++i)
    {
        Number[i] = i + 1;
    }

    Number[24] = INT_MAX;

    Shuffle(Number);

    char   Input;
    int   StarIndex = 24;

    while (true)
    {
        system("cls");
        OutputBoard(Number);

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
                int   Index = StarIndex - 5;

                Move(Number, &StarIndex, Index);
            }
            break;
        case 's':
        case 'S':
            if (StarIndex <= 19)
            {
                // �� �ε����� ���Ѵ�.
                int   Index = StarIndex + 5;

                Move(Number, &StarIndex, Index);
            }
            break;
        case 'a':
        case 'A':
            if (StarIndex % 5 != 0)
            {
                // �� �ε����� ���Ѵ�.
                int   Index = StarIndex - 1;

                Move(Number, &StarIndex, Index);
            }
            break;
        case 'd':
        case 'D':
            if (StarIndex % 5 != 4)
            {
                // �� �ε����� ���Ѵ�.
                int   Index = StarIndex + 1;

                Move(Number, &StarIndex, Index);
            }
            break;
        }

        // 24���� ������ 1 ~ 24�� �� �� ������ true�� ������ ���̰�
        // �ϳ��� ���ӵ� ���ڰ� �ƴ϶�� false�� �ɰ��̴�.
        if (IsComplete(Number))
            break;
    }

    return 0;
}

void Shuffle(int* Number)
{
    // 24�� �ε����� �����ϰ� 0 ~ 23�� �ε����� �����ش�.
    for (int i = 0; i < 100; ++i)
    {
        int   Index1 = rand() % 24;
        int   Index2 = rand() % 24;

        int   Temp = Number[Index1];
        Number[Index1] = Number[Index2];
        Number[Index2] = Temp;
    }
}

void OutputBoard(int* Number)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int   Index = i * 5 + j;

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
    // �� ���� �ٲ��ش�.
    int   Temp = Number[*StarIndex];
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
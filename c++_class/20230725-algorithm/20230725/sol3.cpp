
#include <iostream>
#include <time.h>

void Shuffle(int* Number)
{
    for (int i = 0; i < 100; ++i)
    {
        int   Index1 = rand() % 45;
        int   Index2 = rand() % 45;

        int   Temp = Number[Index1];
        Number[Index1] = Number[Index2];
        Number[Index2] = Temp;
    }
}

void Sort(int* Number)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = i + 1; j < 6; ++j)
        {
            if (Number[i] > Number[j])
            {
                int   Temp = Number[i];
                Number[i] = Number[j];
                Number[j] = Temp;
            }
        }
    }
}

void OutputNumber(int* Number)
{
    for (int i = 0; i < 6; ++i)
    {
        std::cout << Number[i] << "\t";
    }
}

int ComputePair(int* Number, int* ResultNumber)
{
    int   Pair = 0;

    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (ResultNumber[i] == Number[j])
            {
                ++Pair;
                break;
            }
        }
    }

    return Pair;
}

int main()
{
    srand((unsigned int)time(0));
    rand();

    int   ResultNumber[7] = {};

    int   GameCount = 0;

    std::cout << "���� ���� �Է��ϼ��� : ";
    std::cin >> GameCount;

    int   Number[45] = {};

    for (int i = 0; i < 45; ++i)
    {
        Number[i] = i + 1;
    }

    Shuffle(Number);

    Sort(Number);

    OutputNumber(Number);

    for (int i = 0; i < 6; ++i)
    {
        ResultNumber[i] = Number[i];
    }

    ResultNumber[6] = Number[6];
    std::cout << " / " << Number[6] << std::endl;

    std::cout << std::endl;

    for (int Count = 0; Count < GameCount; ++Count)
    {
        Shuffle(Number);

        Sort(Number);

        OutputNumber(Number);

        // ��÷��ȣ�� ���Ѵ�.
        int   Pair = ComputePair(Number, ResultNumber);

        switch (Pair)
        {
        case 3:
            std::cout << ": 5��" << std::endl;
            break;
        case 4:
            std::cout << ": 4��" << std::endl;
            break;
        case 5:
            bool NumberCheck;
            NumberCheck = false;
            for (int i = 0; i < 6; ++i)
            {
                if (Number[i] == ResultNumber[6])
                {
                    NumberCheck = true;
                    break;
                }
            }

            // ������ ���ʽ���ȣ�� ���� ���� ���� ���
            // NumberCheck ������ true�� ����Ǿ� �ִ�.
            // ���� ���� ��ȣ�� ���� ���
            // NumberCheck ������ false�� �����ϰ� �ִ�.
            if (NumberCheck)
                std::cout << ": 2��" << std::endl;

            else
                std::cout << ": 3��" << std::endl;
            break;
        case 6:
            std::cout << ": 1��" << std::endl;
            break;
        default:
            std::cout << ": ��" << std::endl;
            break;
        }
    }

    return 0;
}
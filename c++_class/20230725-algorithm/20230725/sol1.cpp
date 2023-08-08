
#include <iostream>
#include <time.h>

// _getch() 를 이용하기 위해 추가했다.
#include <conio.h>

/*
함수는 선언과 정의로 분리할 수 있다.
함수의 선언 : 반환타입 함수명(인자타입); 이렇게 선언할 수 있다.
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
                int   Index = StarIndex - 5;

                Move(Number, &StarIndex, Index);
            }
            break;
        case 's':
        case 'S':
            if (StarIndex <= 19)
            {
                // 위 인덱스를 구한다.
                int   Index = StarIndex + 5;

                Move(Number, &StarIndex, Index);
            }
            break;
        case 'a':
        case 'A':
            if (StarIndex % 5 != 0)
            {
                // 위 인덱스를 구한다.
                int   Index = StarIndex - 1;

                Move(Number, &StarIndex, Index);
            }
            break;
        case 'd':
        case 'D':
            if (StarIndex % 5 != 4)
            {
                // 위 인덱스를 구한다.
                int   Index = StarIndex + 1;

                Move(Number, &StarIndex, Index);
            }
            break;
        }

        // 24개의 숫자중 1 ~ 24가 다 들어가 있으면 true가 유지될 것이고
        // 하나라도 연속된 숫자가 아니라면 false가 될것이다.
        if (IsComplete(Number))
            break;
    }

    return 0;
}

void Shuffle(int* Number)
{
    // 24번 인덱스를 제외하고 0 ~ 23번 인덱스를 섞어준다.
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
    // 두 값을 바꿔준다.
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
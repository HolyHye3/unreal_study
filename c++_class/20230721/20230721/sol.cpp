#include <iostream>
#include <time.h>

/*
5x5 로 출력.
숫자 1 ~ 25 사이의 값을 랜덤하게 섞어서 출력한다.
사용자는 숫자 1개를 입력하고 0을 입력하면 종료
1 ~ 25 사이의 숫자를 입력하면 해당 숫자를 찾아서 *로
출력되게 만든다. 나머지 숫자부분들은 해당 숫자 그대로 출력한다.
*/

int main()
{
    srand((unsigned int)time(0));
    rand();

    int   Number[25] = {};

    // 0 ~ 24번 인덱스에 1 ~ 25까지 값을 차례대로 넣어준다.
    for (int i = 0; i < 25; ++i)
    {
        Number[i] = i + 1;
    }

    for (int i = 0; i < 100; ++i)
    {
        int   Index1 = rand() % 25;
        int   Index2 = rand() % 25;

        int   Temp = Number[Index1];
        Number[Index1] = Number[Index2];
        Number[Index2] = Temp;
    }

    int   Input = 0;

    while (true)
    {
        system("cls");
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
    }

    return 0;
}
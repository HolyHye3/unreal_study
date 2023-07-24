
#include <iostream>

int main()
{
    /*
    중첩for문 : for문 안쪽에 다른 for문을 추가하여 사용하는 방식이다.
    */
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            std::cout << "i = " << i << ", j = " << j <<
                std::endl;
        }
    }

    // 구구단을 2 ~ 9단까지 이중 for문을 이용해서 출력해보자.
    // 바깥쪽 for문을 단, 안쪽 for문을 곱하는 수
    for (int i = 2; i <= 9; ++i)
    {
        std::cout << i << " 단" << std::endl;

        for (int j = 1; j <= 9; ++j)
        {
            std::cout << i << " * " << j << " = " <<
                i * j << std::endl;
        }
    }

    int   Line = 0;
    std::cout << "줄 수를 입력하세요 : ";
    std::cin >> Line;

    // 아래의 내용을 이중for문을 이용해서 출력한다.
    // std::cout << "*"; 이 코드를 이용해서 출력해야 한다.
    /*
    *
    **
    ***
    ****
    *****
    */
    for (int i = 0; i < Line; ++i)
    {
        // i = 0, 1  i = 1, 2  i = 2, 3  i = 3, 4  i = 4, 5
        for (int j = 0; j <= i; ++j)
        {
            std::cout << "*";
        }

        // 줄이 끝나면 개행한다.
        std::cout << "\n";
    }

    std::cout << "\n";

    /*
    *****
    ****
    ***
    **
    *
    */
    for (int i = 0; i < Line; ++i)
    {
        /*5 - 0 = 5
        5 - 1 = 4
        5 - 2 = 3
        5 - 3 = 2
        5 - 4 = 1*/
        // i = 0, 5  i = 1, 4  i = 2, 3  i = 3, 2, i = 4, 1
        for (int j = 0; j < Line - i; ++j)
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }

    std::cout << "\n";

    // 공백은 std::cout << " ";
    /*
    *****
     ****
      ***
       **
        *
    별 : 5, 4, 3, 2, 1
    공백 : 0, 1, 2, 3, 4
    */
    for (int i = 0; i < Line; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            std::cout << " ";
        }

        for (int j = 0; j < Line - i; ++j)
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }

    std::cout << "\n";

    /*
        *
       **
      ***
     ****
    *****
    별 : 1, 2, 3, 4, 5
    공백 : 4, 3, 2, 1, 0
    */
    for (int i = 0; i < Line; ++i)
    {
        /*4 - 0 = 4
        4 - 1 = 3
        4 - 2 = 2
        4 - 3 = 1
        4 - 4 = 0*/
        for (int j = 0; j < Line - 1 - i; ++j)
        {
            std::cout << " ";
        }

        for (int j = 0; j <= i; ++j)
        {
            std::cout << "*";
        }

        // 줄이 끝나면 개행한다.
        std::cout << "\n";
    }

    std::cout << "\n";
    /*
       *
      ***
     *****
    *******
    별 : 1, 3, 5, 7
    공백 : 3, 2, 1, 0
    */
    for (int i = 0; i < Line; ++i)
    {
        /*
        3 - 0 = 3
        3 - 1 = 2
        3 - 2 = 1
        3 - 3 = 0
        */
        for (int j = 0; j < Line - 1 - i; ++j)
        {
            std::cout << " ";
        }

        /*
        x 0 + 1 = 1
        x 1 + 2 = 3
        x 2 + 3 = 5
        x 3 + 4 = 7
        0 * 2 + 1 = 1
        1 * 2 + 1 = 3
        2 * 2 + 1 = 5
        3 * 2 + 1 = 7
        */
        for (int j = 0; j < i * 2 + 1; ++j)
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }


    std::cout << "\n";
    /*
       *
      ***
     *****
    *******
     *****
      ***
       *
    별 : 1, 3, 5, 7, 5, 3, 1
    공백 : 3, 2, 1, 0, 1, 2, 3
    줄 0번, 6번 동일
    줄 1번, 5번 동일
    줄 2번, 4번 동일
    */

    // 다이아몬드는 무조건 홀수여야하기 때문에 짝수일 시 +1
    if (Line % 2 == 0)
        ++Line;

    int   Count = 0;

    for (int i = 0; i < Line; ++i)
    {
        Count = i;

        // i값이 4 이상일 경우에는 예외처리를 한다.
        if (i > Line / 2) {
            Count = Line - 1 - i;
            std::cout << "Count: " << Count << std::endl;
        }
            

        // 3 - 0 = 3
        // 3 - 1 = 2
        // 3 - 2 = 1
        // 3 - 3 = 0
        // 
        // 3 - 4 = -1 * -1
        // 3 - 5 = -2 * -1
        // 3 - 6 = -3 * -1
        // 또는
        // 6 - 4 = 2
        // 6 - 5 = 1
        // 6 - 6 = 0
        for (int j = 0; j < Line / 2 - Count; ++j)
        {
            std::cout << "Line / 2 - Count: " << Line / 2 - Count << std::endl;
            std::cout << " ";
        }

        for (int j = 0; j < Count * 2 + 1; ++j)
        {
            std::cout << "Count * 2 + 1: " << Count * 2 + 1 << std::endl;
            std::cout << "★";
        }

        std::cout << "\n";
    }

    return 0;
}
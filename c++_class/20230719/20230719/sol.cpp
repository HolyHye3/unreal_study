
#include <iostream>

int main()
{
    /*
    ��øfor�� : for�� ���ʿ� �ٸ� for���� �߰��Ͽ� ����ϴ� ����̴�.
    */
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            std::cout << "i = " << i << ", j = " << j <<
                std::endl;
        }
    }

    // �������� 2 ~ 9�ܱ��� ���� for���� �̿��ؼ� ����غ���.
    // �ٱ��� for���� ��, ���� for���� ���ϴ� ��
    for (int i = 2; i <= 9; ++i)
    {
        std::cout << i << " ��" << std::endl;

        for (int j = 1; j <= 9; ++j)
        {
            std::cout << i << " * " << j << " = " <<
                i * j << std::endl;
        }
    }

    int   Line = 0;
    std::cout << "�� ���� �Է��ϼ��� : ";
    std::cin >> Line;

    // �Ʒ��� ������ ����for���� �̿��ؼ� ����Ѵ�.
    // std::cout << "*"; �� �ڵ带 �̿��ؼ� ����ؾ� �Ѵ�.
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

        // ���� ������ �����Ѵ�.
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

    // ������ std::cout << " ";
    /*
    *****
     ****
      ***
       **
        *
    �� : 5, 4, 3, 2, 1
    ���� : 0, 1, 2, 3, 4
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
    �� : 1, 2, 3, 4, 5
    ���� : 4, 3, 2, 1, 0
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

        // ���� ������ �����Ѵ�.
        std::cout << "\n";
    }

    std::cout << "\n";
    /*
       *
      ***
     *****
    *******
    �� : 1, 3, 5, 7
    ���� : 3, 2, 1, 0
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
    �� : 1, 3, 5, 7, 5, 3, 1
    ���� : 3, 2, 1, 0, 1, 2, 3
    �� 0��, 6�� ����
    �� 1��, 5�� ����
    �� 2��, 4�� ����
    */

    // ���̾Ƹ��� ������ Ȧ�������ϱ� ������ ¦���� �� +1
    if (Line % 2 == 0)
        ++Line;

    int   Count = 0;

    for (int i = 0; i < Line; ++i)
    {
        Count = i;

        // i���� 4 �̻��� ��쿡�� ����ó���� �Ѵ�.
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
        // �Ǵ�
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
            std::cout << "��";
        }

        std::cout << "\n";
    }

    return 0;
}
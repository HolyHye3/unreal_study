#include <iostream>
#include <time.h>

/*
5x5 �� ���.
���� 1 ~ 25 ������ ���� �����ϰ� ��� ����Ѵ�.
����ڴ� ���� 1���� �Է��ϰ� 0�� �Է��ϸ� ����
1 ~ 25 ������ ���ڸ� �Է��ϸ� �ش� ���ڸ� ã�Ƽ� *��
��µǰ� �����. ������ ���ںκе��� �ش� ���� �״�� ����Ѵ�.
*/

int main()
{
    srand((unsigned int)time(0));
    rand();

    int   Number[25] = {};

    // 0 ~ 24�� �ε����� 1 ~ 25���� ���� ���ʴ�� �־��ش�.
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

        std::cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
        std::cin >> Input;

        if (Input == 0)
            break;

        else if (Input < 0 || Input > 25)
            continue;

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
                // ���� ������ for���� ����������.
                break;
            }
        }
    }

    return 0;
}
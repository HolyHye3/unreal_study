#include <iostream>
#include <time.h>

#include "bingoGame.h"

/*
	5 * 5�� ���
	���� 1 - 25 ������ ���� �����ϰ� ��� ����Ѵ�.
	����ڴ� ���� 1���� �Է��ϰ� 0�� �Է��ϸ� ����
	1-25������ ���ڸ� �Է��ϸ� �ش� ���ڸ� ã�Ƽ� *�� ����ϰ� �����.
	������ ���ںκе��� �ش� ���� �״�� ����Ѵ�.

	�� üũ�� �Ѵ�. ���� 5�� ���� 5�� �밢�� 2���� ���´�.
	���� �� ���� �ϼ��ߴ��� �Ź� üũ�Ͽ� 5�� �̻��� �ϼ����� ��� ������ �����Ѵ�.
*/



int main()
{
	srand((unsigned int)time(0));
	rand();


	int BingoStg[25] = {};
	int BingoCount = 0;


	// bingo�� �����
	for (int i = 0; i < 25; i++) {
		BingoStg[i] = i + 1;
	}

	// swap ����
	for (int i = 0; i < 50; i++) {
		int index1 = rand() % 25;
		int index2 = rand() % 25;

		int temp = BingoStg[index1];

		BingoStg[index1] = BingoStg[index2];
		BingoStg[index2] = temp;
	}


	while (true) {

		BingoStgCheck(BingoStg, &BingoCount);

		// bingo�� ���
		BingoStgPrint(BingoStg, &BingoCount);



		// ����� ���� ����
		int player;
		std::cout << "������ ���ڸ� �Է��ϼ���.(�����Ϸ��� 0�Է�): " << std::endl;
		std::cout << std::endl;
		std::cin >> player;

		if (player == 0)
			break;
		else if (player < 1 || player > 25) {
			std::cout << "1 ~ 25 ������ ���ڸ� �Է��ϼ���" << std::endl;
			continue;
		}

		// �����ǰ� ������ ���� ��
		for (int i = 0; i < 25; i++) {
			if (BingoStg[i] == player) {
				BingoStg[i] = INT_MAX;
			}
		}
	}

	return 0;
}
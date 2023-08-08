#include <iostream>
#include <time.h>

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

	int bingo[25] = {};
	bool bingoCheck[25] = {};
	int bingoCount = 0;

	// bingo�� �����
	for (int i = 0; i < 25; i++) {
		bingo[i] = i + 1;
	}

	// swap ����
	for (int i = 0; i < 50; i++) {
		int index1 = rand() % 25;
		int index2 = rand() % 25;
		
		int temp = bingo[index1];

		bingo[index1] = bingo[index2];
		bingo[index2] = temp;
	}
	
	
	int wLine[5] = {};
	int hLine[5] = {};
	int dLine[2] = {};


	while (true) {

		// bingo�� ���
		system("cls");
		std::cout << "���� ������: " << bingoCount << std::endl;
		std::cout << std::endl;

		for (int i = 0; i < 5; i++) {
			for (int j = i * 5; j < i * 5 + 5; j++) {
				if (bingoCheck[j] == true)
					std::cout << "*" << "\t";
				else
					std::cout << bingo[j] << "\t";
			}
				std::cout << std::endl;
		}
		std::cout << std::endl;


		int count = 0;

		// ���ΰ� ������ ��� üũ
		for (int i = 0; i < 5; i++) {

			// �ش������ ��������̶�� �˻� �ǳʶٱ�
			if (wLine[i] == true)
				continue;

			// �ش��� �˻��ϱ�
			for (int j = i * 5; j < i * 5 + 5; j++) {

				if (bingoCheck[j] == true)
					count++;

				if (count == 5) {
					bingoCount++;
					wLine[i] = true;
					/*std::cout << "BINGO!!!" << std::endl;
					system("pause");*/
				}

			}

			// ������ �˻縦 ���� �ʱ�ȭ
			count = 0;
		}

		// ���ΰ� ������ ��� üũ
		for (int i = 0; i < 5; i++) {
			if (hLine[i] == true)
				continue;

			for (int j = i; j < i + 22; j += 5) {

				if (bingoCheck[j] == true)
					count++;

				if (count == 5) {
					bingoCount++;
					hLine[i] = true;
					/*std::cout << "BINGO!!!" << std::endl;
					system("pause");*/
				}
			}

			// ������ �˻縦 ���� �ʱ�ȭ
			count = 0;
		}


		// �밢�� ������ ��� üũ
		if (dLine[0] == false) {
			for (int i = 0; i < 25; i += 6) {

				if (bingoCheck[i] == true)
					count++;

				if (count == 5) {
					bingoCount++;
					dLine[0] = true;
					/*std::cout << "BINGO!!!" << std::endl;
					system("pause");*/
				}
			}
			// ������ �˻縦 ���� �ʱ�ȭ
			count = 0;
		}
		if (dLine[1] == false) {
			for (int i = 4; i < 21; i += 4) {

				if (bingoCheck[i] == true)
					count++;

				if (count == 5) {
					bingoCount++;
					dLine[1] = true;
					/*std::cout << "BINGO!!!" << std::endl;
					system("pause");*/
				}
			}
			// ������ �˻縦 ���� �ʱ�ȭ
			count = 0;
		}

		
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
			if (bingo[i] == player) {
				bingoCheck[i] = true;
			}
		}

	}

	return 0;
}
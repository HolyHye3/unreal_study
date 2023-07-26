#include <iostream>
#include <time.h>

#include "randomGame.h"


int main() {
	srand((unsigned int)time(0));
	rand();

	system("cls");

	int ResultNumber[7] = {};
	int GameCount = 0;
	int Number[45] = {};

	std::cout << "���� ���� �Է��ϼ��� : ";
	std::cin >> GameCount;

	// ī�� 1 ~ 45���� ��ȣ �ο��ϱ�
	for (int i = 0; i < 45; i++) {
		Number[i] = i + 1;
	}


	RandomCard(Number);

	OutPutNumber(Number, ResultNumber);

	// ���ʽ� ��ȣ �����ϱ�
	ResultNumber[6] = Number[6];
	std::cout << "/" << Number[6] << std::endl;

	std::cout << std::endl;

	// ���� ����
	for (int count = 0; count < GameCount; count++) {


		RandomCard(Number);


		int Pair = PairCard(Number, ResultNumber);


		switch (Pair) {
		case 3:
			std::cout << ": 5�� " << std::endl;
			break;
		case 4:
			std::cout << ": 4��" << std::endl;
			break;
		case 5:
			bool NumberCheck;
			NumberCheck = false;
			for (int i = 0; i < 6; i++) {
				if (Number[i] == ResultNumber[6])
				{
					NumberCheck = true;
					break;
				}
			}
			/*
			������ ���ʽ���ȭ�� ���� ���� ���� ��� NumberCheck ������ true�� ����Ǿ� �ִ�.
			���� ���� ��ȣ�� ���� ��� NumberCheck������ false�� �����ϰ� �ִ�.
			*/

			if (NumberCheck)
				std::cout << ": 2��";
			else
				std::cout << ": 3��" << std::endl;
			break;
		case 6:
			std::cout << "1��: " << std::endl;
			break;
		default:
			std::cout << "��" << std::endl;
		}

	}

	int restart = 0;

	std::cout << std::endl;
	std::cout << "�ٽ��Ϸ��� 1�� �Է��ϼ���(�����Ϸ��� �ٸ� ����):" << std::endl;
	std::cin >> restart;

	if (restart == 1)
		main();

	return 0;
}
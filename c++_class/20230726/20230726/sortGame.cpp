#include <iostream>
#include <time.h>

#include "sortGame.h"

/*

*  1  2  3  4
5  6  7  8  9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24

0���� ǥ�õ� �κп� 1 ~ 24 ������ ���ڸ� ��� ����Ѵ�.
�÷��̾�� * ǥ�ø� �������� �� �ִ�.
w: ���� �̵� s: �Ʒ��� �̵� a: ���� �̵� d: ������ �̵� q: ����

�̵� Ű�� ������ �ش� ���⿡ �ִ� ���� *�� ��ġ�� �������ְ� ���ڰ� ���� ������ ���ʴ�� 1 ~ 24���� ������ ������ ����

*/

/*
�Լ��� ����� ���Ƿ� �и��� �� �ִ�.
�Լ��� ����: ��ȯŸ�� �Լ���(����Ÿ��); �̷��� ������ �� �ִ�.
*/
//void GameStg(int gameStg[]);
//void GameStgPrint(int gameStg[], int* location);
//void MoveLocation(int gameStg[], int moveLocation, int* location);
//bool CheckClear(int gameStg[]);

int main() {

	srand((unsigned int)time(0));
	rand();

	int gameStg[25] = {};
	int location = 0;

	GameStg(gameStg);

	// ���
	for (int i = 0; i < 5; i++) {
		for (int j = i * 5; j < i * 5 + 5; j++) {
			if (gameStg[j] == 0) {
				std::cout << "*" << "\t";
				// ���� ��ġ�� ����
				location = j;
			}
			else
				std::cout << gameStg[j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;



	while (true) {

		//w: ���� �̵� s: �Ʒ��� �̵� a: ���� �̵� d: ������ �̵� q: ����
		char player = 0;

		std::cout << "w: ���� �̵� s: �Ʒ��� �̵� a: ���� �̵� d: ������ �̵� q: ����";
		std::cout << std::endl;

		std::cin >> player;

		if (player == 'q' || player == 'Q') {
			break;
		}

		int newLocation = 0;
		switch (player)
		{

		case 'W':
		case 'w':
			newLocation = location - 5;

			if (newLocation > 24 || newLocation < 0)
				continue;

			MoveLocation(gameStg, newLocation, &location);

			break;
		case 'S':
		case 's':
			newLocation = location + 5;

			if (newLocation > 24 || newLocation < 0)
				continue;

			MoveLocation(gameStg, newLocation, &location);

			break;
		case 'A':
		case 'a':
			newLocation = location - 1;

			if (newLocation > 24 || newLocation < 0 || newLocation % 5 == 4)
				continue;

			MoveLocation(gameStg, newLocation, &location);

			break;
		case 'D':
		case 'd':
			newLocation = location + 1;

			if (newLocation > 24 || newLocation < 0 || newLocation % 5 == 0)
				continue;

			MoveLocation(gameStg, newLocation, &location);

			break;
		}

		// ���
		GameStgPrint(gameStg, &location);

		if (CheckClear(gameStg)) {
			std::cout << "�ϼ�!! ������ �����մϴ�.." << std::endl;
			break;
		}
	}

	return 0;
}


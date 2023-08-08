#pragma once

#include <iostream>

void GameStg(int gameStg[]) {

	// game stage �����
	for (int i = 0; i < 25; i++) {

		gameStg[i] = i;
	}

	// swap ����
	for (int i = 0; i < 50; i++) {
		int index1 = rand() % 25;
		int index2 = rand() % 25;

		int temp = gameStg[index1];

		gameStg[index1] = gameStg[index2];
		gameStg[index2] = temp;
	}
}

void GameStgPrint(int gameStg[], int* location) {
	system("cls");
	for (int i = 0; i < 5; i++) {
		for (int j = i * 5; j < i * 5 + 5; j++) {
			if (gameStg[j] == 0) {
				std::cout << "*" << "\t";
				// ���� ��ġ�� ����
				*location = j;
			}
			else
				std::cout << gameStg[j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void MoveLocation(int gameStg[], int moveLocation, int* location) {
	int newLocation = moveLocation;

	// ������ġ �ε��� ���� �Ʒ��� �ε����� ������ ��ȯ
	gameStg[*location] = gameStg[newLocation];
	// ���� ��ġ ����
	*location = newLocation;
	// �Ʒ��� �ε��� ���� ������ġ �ε��� ������
	gameStg[*location] = 0;
}

bool CheckClear(int gameStg[]) {
	// 24���� ������ 1 ~ 24�� �� �� ������ true�� ������ ���̰�
		// �ϳ��� ���ӵ� ���ڰ� �ƴ϶�� false�� �ɰ��̴�.
	bool Complete = true;

	for (int i = 0; i < 24; i++) {
		if (gameStg[i] != i) {
			return false;
			break;
		}
	}

	return true;

}
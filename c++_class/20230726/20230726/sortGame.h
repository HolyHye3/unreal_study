#pragma once

#include <iostream>

void GameStg(int gameStg[]) {

	// game stage 만들기
	for (int i = 0; i < 25; i++) {

		gameStg[i] = i;
	}

	// swap 구현
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
				// 현재 위치를 저장
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

	// 현재위치 인덱스 값을 아래쪽 인덱스의 값으로 변환
	gameStg[*location] = gameStg[newLocation];
	// 현재 위치 지정
	*location = newLocation;
	// 아래쪽 인덱스 값을 현재위치 인덱스 값으로
	gameStg[*location] = 0;
}

bool CheckClear(int gameStg[]) {
	// 24개의 숫자중 1 ~ 24가 다 들어가 있으면 true가 유지될 것이고
		// 하나라도 연속된 숫자가 아니라면 false가 될것이다.
	bool Complete = true;

	for (int i = 0; i < 24; i++) {
		if (gameStg[i] != i) {
			return false;
			break;
		}
	}

	return true;

}
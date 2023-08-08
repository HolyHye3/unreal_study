#include <iostream>
#include <time.h>

#include "sortGame.h"

/*

*  1  2  3  4
5  6  7  8  9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24

0으로 표시된 부분에 1 ~ 24 사이의 숫자를 섞어서 출력한다.
플레이어는 * 표시를 움직여줄 수 있다.
w: 위로 이동 s: 아래로 이동 a: 왼쪽 이동 d: 오른쪽 이동 q: 종료

이동 키를 누르면 해당 방향에 있는 값과 *의 위치를 변경해주고 숫자가 왼쪽 위부터 차례대로 1 ~ 24까지 나오면 게임을 종료

*/

/*
함수는 선언과 정의로 분리할 수 있다.
함수의 선언: 반환타입 함수명(인자타입); 이렇게 선언할 수 있다.
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

	// 출력
	for (int i = 0; i < 5; i++) {
		for (int j = i * 5; j < i * 5 + 5; j++) {
			if (gameStg[j] == 0) {
				std::cout << "*" << "\t";
				// 현재 위치를 저장
				location = j;
			}
			else
				std::cout << gameStg[j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;



	while (true) {

		//w: 위로 이동 s: 아래로 이동 a: 왼쪽 이동 d: 오른쪽 이동 q: 종료
		char player = 0;

		std::cout << "w: 위로 이동 s: 아래로 이동 a: 왼쪽 이동 d: 오른쪽 이동 q: 종료";
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

		// 출력
		GameStgPrint(gameStg, &location);

		if (CheckClear(gameStg)) {
			std::cout << "완성!! 게임을 종료합니다.." << std::endl;
			break;
		}
	}

	return 0;
}


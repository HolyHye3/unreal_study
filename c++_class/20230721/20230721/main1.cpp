#include <iostream>
#include <time.h>
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

int main() {
	
	srand((unsigned int)time(0));
	rand();

	int gameStage[25] = {};
	int location = 0;

	// game stage 만들기
	for (int i = 0; i < 25; i++) {
		

		gameStage[i] = i;
	}

	// swap 구현
	for (int i = 0; i < 50; i++) {
		int index1 = rand() % 25;
		int index2 = rand() % 25;

		int temp = gameStage[index1];

		gameStage[index1] = gameStage[index2];
		gameStage[index2] = temp;
	}


	// 출력
	for (int i = 0; i < 5; i++) {
		for (int j = i * 5; j < i * 5 + 5; j++) {
			if (gameStage[j] == 0) {
				std::cout << "*" << "\t";
				// 현재 위치를 저장
				location = j;
			}
			else
				std::cout << gameStage[j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;



	while (true) {

		//w: 위로 이동 s: 아래로 이동 a: 왼쪽 이동 d: 오른쪽 이동 q: 종료
		char player = 0;

		int move[4] = { location-5, location+5, location-1, location+1 };

		std::cout << "w: 위로 이동 s: 아래로 이동 a: 왼쪽 이동 d: 오른쪽 이동 q: 종료";
		std::cout << std::endl;

		std::cin >> player;
	
		// q입력
		if (player == 'q')
			break;


		// w를 입력했다면 위로 이동
		if (player == 'w') {

			int newLocation = location - 5;

			if (newLocation > 24 || newLocation < 0)
				continue;

			// 현재위치 인덱스 값을 위쪽 인덱스의 값으로 변환
			gameStage[location] = gameStage[newLocation];
			// 현재 위치 지정
			location = newLocation;
			// 위쪽 인덱스 값을 현재위치 인덱스 값으로
			gameStage[location] = 0;
			
		}

		// s를 클릭했다면 아래로 이동
		if (player == 's') {

			int newLocation = location + 5;

			if (newLocation > 24 || newLocation < 0)
				continue;

			// 현재위치 인덱스 값을 아래쪽 인덱스의 값으로 변환
			gameStage[location] = gameStage[newLocation];
			// 현재 위치 지정
			location = newLocation;
			// 아래쪽 인덱스 값을 현재위치 인덱스 값으로
			gameStage[location] = 0;
		}

		// a를 입력했다면 오른쪽으로 이동
		if (player == 'a') {

			int newLocation = location - 1;

			if (newLocation > 24 || newLocation < 0 || newLocation % 5 == 4)
				continue;
		

			// 현재위치 인덱스 값을 아래쪽 인덱스의 값으로 변환
			gameStage[location] = gameStage[newLocation];
			// 현재 위치 지정
			location = newLocation;
			// 아래쪽 인덱스 값을 현재위치 인덱스 값으로
			gameStage[location] = 0;
		}

		// d를 입력했다면 왼쪽으로 이동
		if (player == 'd') {

			int newLocation = location + 1;

			if (newLocation > 24 || newLocation < 0 || newLocation % 5 == 0)
				continue;

			// 현재위치 인덱스 값을 아래쪽 인덱스의 값으로 변환
			gameStage[location] = gameStage[newLocation];
			// 현재 위치 지정
			location = newLocation;
			// 아래쪽 인덱스 값을 현재위치 인덱스 값으로
			gameStage[location] = 0;
		}


		// 출력
		system("cls");
		for (int i = 0; i < 5; i++) {
			for (int j = i * 5; j < i * 5 + 5; j++) {
				if (gameStage[j] == 0) {
					std::cout << "*" << "\t";
					// 현재 위치를 저장
					location = j;
				}
				else
					std::cout << gameStage[j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

		int count = 0;
		for (int i = 0; i < 25; i++) {
			if (gameStage[i+1] == i + 1)
				count++;
		}
		if (count == 24) {
			std::cout << "완성!! 게임을 종료합니다.." << std::endl;
			break;
		}

	}
	

	return 0;
}
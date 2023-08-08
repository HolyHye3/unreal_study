#include <iostream>
#include <time.h>

/*
	5 * 5로 출력
	숫자 1 - 25 사이의 값을 랜덤하게 섞어서 출력한다.
	사용자는 숫자 1개를 입력하고 0을 입력하면 종료
	1-25사이의 숫자를 입력하면 해당 숫자를 찾아서 *로 출력하게 만든다.
	나머지 숫자부분들은 해당 숫자 그대로 출력한다.

	줄 체크를 한다. 가로 5줄 세로 5줄 대각선 2줄이 나온다.
	이중 몇 줄을 완성했는지 매번 체크하여 5줄 이상을 완성했을 경우 게임을 종료한다.
*/


int main()
{
	srand((unsigned int)time(0));
	rand();

	int bingo[25] = {};
	bool bingoCheck[25] = {};
	int bingoCount = 0;

	// bingo판 만들기
	for (int i = 0; i < 25; i++) {
		bingo[i] = i + 1;
	}

	// swap 구현
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

		// bingo판 출력
		system("cls");
		std::cout << "현재 빙고개수: " << bingoCount << std::endl;
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

		// 가로가 빙고일 경우 체크
		for (int i = 0; i < 5; i++) {

			// 해당라인이 빙고라인이라면 검사 건너뛰기
			if (wLine[i] == true)
				continue;

			// 해당줄 검사하기
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

			// 다음줄 검사를 위한 초기화
			count = 0;
		}

		// 새로가 빙고일 경우 체크
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

			// 다음줄 검사를 위한 초기화
			count = 0;
		}


		// 대각선 빙고일 경우 체크
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
			// 다음줄 검사를 위한 초기화
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
			// 다음줄 검사를 위한 초기화
			count = 0;
		}

		
		// 사용자 숫자 선택
		int player;
		std::cout << "선택할 숫자를 입력하세요.(종료하려면 0입력): " << std::endl;
		std::cout << std::endl;
		std::cin >> player;

		if (player == 0)
			break;
		else if (player < 1 || player > 25) {
			std::cout << "1 ~ 25 사이의 숫자를 입력하세요" << std::endl;
			continue;
		}

		// 빙고판과 선택한 숫자 비교
		for (int i = 0; i < 25; i++) {
			if (bingo[i] == player) {
				bingoCheck[i] = true;
			}
		}

	}

	return 0;
}
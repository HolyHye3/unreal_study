#include <iostream>
#include <time.h>

#include "bingoGame.h"

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


	int BingoStg[25] = {};
	int BingoCount = 0;


	// bingo판 만들기
	for (int i = 0; i < 25; i++) {
		BingoStg[i] = i + 1;
	}

	// swap 구현
	for (int i = 0; i < 50; i++) {
		int index1 = rand() % 25;
		int index2 = rand() % 25;

		int temp = BingoStg[index1];

		BingoStg[index1] = BingoStg[index2];
		BingoStg[index2] = temp;
	}


	while (true) {

		BingoStgCheck(BingoStg, &BingoCount);

		// bingo판 출력
		BingoStgPrint(BingoStg, &BingoCount);



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
			if (BingoStg[i] == player) {
				BingoStg[i] = INT_MAX;
			}
		}
	}

	return 0;
}
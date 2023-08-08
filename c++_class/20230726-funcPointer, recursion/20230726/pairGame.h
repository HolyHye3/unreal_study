#pragma once

#include <iostream>

void PrintBoard(bool Open[], char Card[]) {

	system("cls");

	// i가 세로 줄번호가 되고 j가 가로번호가 된다.
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; ++j) {

			// 인덱스 공식: 세로번호 * 가로개수 + 가로번호
			int Index = i * 5 + j;

			// 카드가 닫힌 상태라면 카드 번호를 출력한다.
			if (!Open[Index])
			{
				// 카드 번호를 출력한다.
				//std::cout << Card[Index] << "\t";
				std::cout << Index << "\t";
			}
			else {
				std::cout << Card[Index] << "\t";
			}
		}

		std::cout << std::endl;
	}
}
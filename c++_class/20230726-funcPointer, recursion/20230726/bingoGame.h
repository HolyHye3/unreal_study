#pragma once

#include <iostream>

// bingo판 출력
void BingoStgPrint(int BingoStg[], int* BingoCount) {


	system("cls");
	std::cout << "현재 빙고개수: " << *BingoCount << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 5; i++) {
		for (int j = i * 5; j < i * 5 + 5; j++) {
			if (BingoStg[j] == INT_MAX)
				std::cout << "*" << "\t";
			else
				std::cout << BingoStg[j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// bingo 체크
void BingoStgCheck(int BingoStg[], int* BingoCount) {

	*BingoCount = 0;

	int WidthCount = 0;
	int heightCount = 0;

	for (int i = 0; i < 5; i++) {
		WidthCount = 0;
		heightCount = 0;
		for (int j = 0; j < 5; j++) {

			if (BingoStg[i * 5 + j] == INT_MAX)
				WidthCount++;

			if (BingoStg[j * 5 + i] == INT_MAX)
				heightCount++;

		}

		if (WidthCount == 5)
			(*BingoCount)++;
		if (heightCount == 5)
			(*BingoCount)++;

	}



	// 대각선 빙고일 경우 체크
	int count = 0;

	for (int i = 0; i < 25; i += 6) {

		if (BingoStg[i] == INT_MAX)
			count++;
	}

	if (count == 5)
		(*BingoCount)++;


	count = 0;

	for (int i = 4; i < 21; i += 4) {

		if (BingoStg[i] == INT_MAX)
			count++;
	}

	if (count == 5)
		(*BingoCount)++;
}
#pragma once

#include <iostream>

void RandomCard(int* Number) {
	// 카드 랜덤으로 섞기
	for (int i = 0; i < 100; i++) {

		int Index1 = rand() % 45;
		int Index2 = rand() % 45;

		int Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;

	}

	// 카드 번호 정렬
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {

			if (Number[i] > Number[j]) {
				int Temp = Number[i];
				Number[i] = Number[j];
				Number[j] = Temp;
			}

		}
	}
}

int PairCard(int* Number, int* ResultNumber) {
	int Pair = 0;

	// 뽑은 숫자 출력
	for (int i = 0; i < 6; i++) {
		std::cout << Number[i] << "\t";
	}


	// 당첨번호와 비교한다.
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (ResultNumber[i] == Number[j]) {
				Pair++;
				break;
			}
		}
	}

	return Pair;
}

void OutPutNumber(int* Number, int* ResultNumber) {
	for (int i = 0; i < 6; i++) {
		std::cout << Number[i] << "\t";
		ResultNumber[i] = Number[i];
	}
}

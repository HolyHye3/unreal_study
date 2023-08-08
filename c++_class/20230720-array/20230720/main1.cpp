#include <iostream>
#include <time.h>

int main() {
	srand((unsigned int)time(0));
	rand();

	system("cls");

	int ResultNumber[7] = {};
	int GameCount = 0;
	int Number[45] = {};

	std::cout << "게임 수를 입력하세요 : ";
	std::cin >> GameCount;

	// 카드 1 ~ 45까지 번호 부여하기
	for (int i = 0; i < 45; i++) {
		Number[i] = i + 1;
	}


	// 카드 랜덤으로 섞기
	for (int i = 0; i < 45; i++) {

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

	// 보너스 번호 저장하기
	for (int i = 0; i < 6; i++) {
		std::cout << Number[i] << "\t";
		ResultNumber[i] = Number[i];
	}

	ResultNumber[6] = Number[6];
	std::cout << "/" << Number[6] << std::endl;

	std::cout << std::endl;

	// 게임 시작
	for (int count = 0; count < GameCount; count++) {
		

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


		// 뽑은 숫자 출력
		for (int i = 0; i < 6; i++) {
			std::cout << Number[i] << "\t";
		}


		// 당첨번호와 비교한다.
		int Pair = 0;

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (ResultNumber[i] == Number[j]) {
					Pair++;
					break;
				}
			}
		}

		switch (Pair) {
		case 3:
			std::cout << ": 5등 " << std::endl;
			break;
		case 4:
			std::cout << ": 4등" << std::endl;
			break;
		case 5:
			bool NumberCheck;
			NumberCheck = false;
			for (int i = 0; i < 6; i++) {
				if (Number[i] == ResultNumber[6])
				{
					NumberCheck = true;
					break;
				}
			}
			/*
			위에서 보너스번화와 같은 값이 있을 경우 NumberCheck 변수는 true로 변경되어 있다.
			만약 같은 번호가 없을 경우 NumberCheck변수는 false를 유지하고 있다.
			*/

			if (NumberCheck)
				std::cout << ": 2등";
			else
				std::cout << ": 3등" << std::endl;
			break;
		case 6:
			std::cout << "1등: " << std::endl;
			break;
		default:
			std::cout << "꽝" << std::endl;
		}

	}

	int restart = 0;

	std::cout << std::endl;
	std::cout << "다시하려면 1을 입력하세요(종료하려면 다른 숫자):" << std::endl;
	std::cin >> restart;

	if (restart == 1)
		main();

	return 0;
}
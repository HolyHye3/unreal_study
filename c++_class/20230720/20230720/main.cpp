#include <iostream>
#include <time.h>


int main() {
	srand((unsigned int)time(0));
	rand();
	/*
		배열: 한 번 선언으로 같은 타입의 변수 여러개를 생성할 수 있게 해주는 기능
		변수타입 배열이름[개수];

		int NumberArray[100];

		위와 같이 int배열 100개짜리를 생성하면 400바이트만큼의 메모리가 하나의 블록으로 잡히게 된다.

		배열의 각 요소에 접근하기 위해서는 인덱스를 이용한다.
		인덱스는 0 ~ 개수-1 까지 존재한다.
	*/

	// 초기화하지 않고 출력하면 쓰레기값이 나온다.
	// int NumberArray[100] = 0; -> 이렇게 초기화하는건 안된다.
	
	// 아래와 같이 초기화
	// 배열 전체요소를 0으로 초기화
	int NumberArray[100] = {};
	// 특정 인덱스만 초기화
	// int NumberArray[100] = {1,3,6,7,10}

	// int index = 105;
	// NumberArray[index] = 1020; -> 잘 못 된 접근

	int index = 10;

	NumberArray[0] = 500;

	NumberArray[1] += 20;

	if (index < 0 || index >= 100) {
		std::cout << "index Error" << std::endl;
	}
	else {
		NumberArray[index] = 1020;
	}

	std::cout << NumberArray[0] << std::endl;
	std::cout << NumberArray[index] << std::endl;

	std::cout << "\n" << std::endl;

	for (int i = 0; i < 100; i++) {
		std::cout << NumberArray[i] << std::endl;
	}

	/*
		다차원배열:

		1차원 배열과 2차원 배열의 차이점은 크기는 똑같지만 접근 방식에서 차이가 난다.
		

		int Number[5][10]
		int Number[5][10][6];
		모든 개수를 다 곱하여 전체 수를 구해준다.

		int Number[50] : 50개
		int Number[5][10]: 50개
		int Number[5][10][6] = 300개
	*/
	int NumberArray1[5][10] = {};
	NumberArray1[0][2] = 300;


	/*
		1차원 배열 특정 위치 찾는 식: 
		세로번호* 가로개수 + 가로번호
	*/
	int NumberArray2[50] = {};
	NumberArray2[2 * 10 + 7] = 1010;

	
	//======== 카드 게임 ========

	system("cls");

	int Card[50] = {};

	// Card의 0 ~ 49번 인덱스에 1 ~ 50까지 차례대로 대입해준다.
	for (int i = 0; i < 50; i++) {
		Card[i] = i + 1;
		// Card[i] = rand() % 50 + 1;
	}


	for (int i = 0; i < 50; i++) {
		
		// 랜덤 swap
		int index1 = rand() % 50;
		int index2 = rand() % 50;

		int temp = Card[index1];
		Card[index1] = Card[index2];
		Card[index2] = temp;
	}

	for (int i = 0; i < 50; i++) {
		std::cout << Card[i] << std::endl;
	}


	//숫자뽑기
	for (int i = 0; i < 6; i++) {
		// \t: Tab 키를 1번 누른것과 같은 효과
		std::cout << Card[i] << "\t";
	}

	return 0;
}
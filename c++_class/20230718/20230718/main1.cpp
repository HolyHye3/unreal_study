#include <iostream>
#include <time.h>

int main()
{
	// srand(0);
	srand(time(0));
	rand();
	std::cout << rand() % 100 + 100 << std::endl;
	std::cout << rand() % 100 + 100 << std::endl;
	std::cout << rand() % 100 + 100 << std::endl;
	std::cout << rand() % 100 + 100 << std::endl;
	std::cout << rand() % 100 + 100 << std::endl;
	/*
	if문: 조건을 체크하여 원하는 코드를 동작시킬지 말지를 결정할 수 있다.
	형태
	if(조건식)
	{
		조건이 true일 때 동작할 코드
	}
	*/
	if (true) {
		std::cout << "if문이 true 입니다." << std::endl;
	}

	int Number = 100;

	// if문 안의 코드가 1줄일 경우 코드블록을 생략 가능
	if (Number < 0)
		std::cout << "숫자가 0보다 작다." << std::endl;
	/*
	else는 if문 조건식이 false일 때 동작하는 기능이다.
	else는 혼자서 사용이 불가능하다. 반드시 if문과 함께 사용해야한다.
	else
	{
	}
	로 구성된다.
	*/
	else {
		std::cout << "숫자가 0보다 크다." << std::endl;
	}

	/*
	else if도 혼자서 사용이 불가능하다. 반드시 if문과 함께 사용해야한다.
	else if는 몇개든 추가할 수 있다.
	else 보다 위에 있어야 한다.

	형태
	else if(조건식)
	{
	}
	*/

	const int State1 = 0x1;		// 0000 0001
	const int State2 = 0x2;		// 0000 0010
	const int State3 = 0x4;		// 0000 0100
	const int State4 = 0x8;		// 0000 1000
	const int State5 = 0x10;	// 0001 0000
	const int State6 = 0x20;	// 0010 0000
	const int State7 = 0x40;	// 0100 0000

	int State = 0;

	State |= State2;
	State |= State3;
	State |= State6;

	if (State & State1)
		std::cout << "State1 On\n";
	if (State & State2)
		std::cout << "State2 On\n";
	if (State & State3)
		std::cout << "State3 On\n";
	if (State & State4)
		std::cout << "State4 On\n";
	if (State & State5)
		std::cout << "State5 On\n";
	if (State & State6)
		std::cout << "State6 On\n";

	Number = 30;
	// cin : 콘솔창에서 입력받을 수 있게 해주는 기능이다.
	std::cin >> Number;

	if (Number < 10)
		std::cout << "숫자가 10보다 작다\n";
	else if (Number < 20)
		std::cout << "숫자가 20보다 작다\n";



	return 0;
}
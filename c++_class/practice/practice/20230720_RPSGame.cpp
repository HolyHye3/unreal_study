#include <iostream>
#include <time.h>

int main()
{
	srand((unsigned int) time(0));
	rand();

	// 변수 및 타입 선언
	enum RPS {
		ROCK = 1,
		SCISSOR,
		PAPER
	};

	int player;
	int com;

}
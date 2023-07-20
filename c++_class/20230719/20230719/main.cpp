#include <iostream>

int main()
{
	/*
		반복문: 동일한 코드를 여러번 반복해서 동작시켜주는 기능.
		for, while, do while

		for의 형태
		for(초기값; 조건식; 증감)
		{
			동작할 코드
		}
		초기값: for문이 시작할 때 1번만 동작한다.
		조건식: for문이 반복해서 동작할때마다 체크한다.
				조건식은 결과가 true/false가 나올 수 있게 구성한다.
				현재 반복이 시작되기 직전에 조건식을 수행한다.
				조건식이 true이면 안의 코드가 동작하고 조건식이 false면 for문을 빠져나간다.
		증감: for문이 반복해서 동작할때마다 증감을 한다.
				현재 반복이 수행되고 후에 증감을 처리한다.

		동작방법
		초기값 -> 조건식 -> 코드실행 -> 증감 -> 조건식 -> 코드 실행 -> ...
		반복도중 조건식이 false가 되면 for문을 빠져나간다.

		조건식이 계속 true가 된다면 for문을 빠져나올 수 없기 때문에 조건식을 잘 구성해야 한다.

		의도적으로 무한루프를 돌리고 싶을 경우
		for(;;)
		{
		}

		초기값, 조건식, 등감을 모두 비워두면 무한루프를 돌릴 수 있다.

	*/
	for (int i = 0; i < 10; i++) {
		std::cout << i << std::endl;
	}

	std::cout << "\n" << std::endl;

	for (int i = 0; i < 10; i += 2) {
		std::cout << i << std::endl;
	}

	std::cout << "\n" << std::endl;

	for (int i = 0; i < 100; i++) {
		if (i % 4 == 0 && i % 7 == 0) {
			std::cout << i << std::endl;
		}
	}
	
	std::cout << "\n" << std::endl;

	for (int i = 0; i < 100; i++) {

		// break는 if문에는 영향을 줄 수 없다.
		// switch, for, while, do while을 빠져나가는 용도로 사용한다.
		if (i == 30)
			break;

		// continue: 현재 반복을 스킵해준다.
		else if (i % 2 == 0)
			continue;

		std::cout << i << std::endl;
	}

	// c++는 코드블럭단에서만 변수 사용가능
	{int num = 0;}
	// std::cout << num << std::endl;


	return 0;
}
#include <iostream>

int main()
{
	/*
	while(조건식)
	{

	}
	조건식이 true이면 동작
	조건식이 false이면 while문을 빠져나간다.

	for문처럼 break와 continue로 실행흐름을 제어할 수 있다.
	*/
	int Number = 0;
	while (Number < 10) {
		Number++;
	}

	/*while (true)
	{

	}*/

	/*
	do
	{
		반복할 코드
	}while(조건식);

	처음 1번은 조건식과 관계없이 무조건 코드가 동작이 된다.
	*/

	do
	{
		std::cout << Number << std::endl;
		++Number;
	} while (Number < 10);


	return 0;
}
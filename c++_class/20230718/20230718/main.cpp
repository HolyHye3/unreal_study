#include <iostream>
#include <time.h>

/*
플레이어는 가위, 바위, 보 셋 중 하나를 선택한다.
AI는 가위, 바위, 보 셋중 하나를 랜덤하게 얻어온다.
플레이어와 AI중 누가 이겼는지를 판단한다.
*/

/*
열거체: 상수에 이름을 부여하는 기능이다.
열거체를 이용하여 이름이 부여된 상수는 나열되는 순서에따라 값이 변경될 수 있다.

형태
enum 열거체명{
	이름 부여.
}; <- 세미콜론 붙여줘야함;;;

이름이 부여된 목록은 0부터 시작해서 값이 1씩 증가되어 지정된다.

열거형은 목록의 상수를 이용할 수도 있지만 열거형의 이름 자체가 일종의 사용자정의 변수타입이 된다.

열거형으로 만든 변수는 해당 열거형의 목록에 지정된 값만 값으로 저장할 수 있다.

열거형은 기본적으로 4byte다.
*/

enum SRP {
	SCISSOR = 1,
	ROCK,
	PAPER
};

// 직접적으로 사이즈 지정이 가능하다.
enum class SRP1 : unsigned char {
	SCISSOR1 = 1,
	ROCK1,
	PAPER1
};

/*
switch: 분기문의 한 종류이다.
형태
switch(분기를 하고자 하는 값)
{
case 체크할 상수(변수가 들어오면 안된다.):
	동작시킬 코드
	break; break는 switch문을 빠져나가는 역할을 한다.
case 체크할 상수(변수가 들어오면 안된다.):
	동작시킬 코드
	break;
case 체크할 상수(변수가 들어오면 안된다.):
	동작시킬 코드
	break;
}
*/

int main()
{
	// 형변환: (변환할 타입)의 형태로 사용하며, 어떤 값이나 변수를 지정한 타입으로 일시적으로 인식시켜주는 기능
	srand((unsigned int)time(0));
	rand();

	std::cout << "1. 가위" << std::endl;
	std::cout << "2. 바위" << std::endl;
	std::cout << "3. 보" << std::endl;
	std::cout << "선택하세요" << std::endl;

	// 플레이어 선택
	int player = 0;
	std::cin >> player;

	// 컴퓨터 랜덤선택
	int com = rand() % 3 + 1;

	switch (com) {
	case SCISSOR:
		std::cout << "com: 가위\n";
		break;
	case ROCK:
		std::cout << "com: 바위\n";
		break;
	case PAPER:
		std::cout << "com: 보\n";
		break;
}
	/*
	if (player == SCISSOR)
		std::cout << "플레이어 선택: 1.가위 " << std::endl;
	else if (player == SCISSOR)
		std::cout << "플레이어 선택: 2.바위 " << std::endl;
	else if (player == PAPER)
		std::cout << "플레이어 선택: 3.보 " << std::endl;

	if (com == SCISSOR)
		std::cout << "AI 선택: 1.가위" << std::endl;
	else if (com == SCISSOR)
		std::cout << "AI 선택: 2.바위 " << std::endl;
	else if (com == PAPER)
		std::cout << "AI 선택: 3.보 " << std::endl;
	*/

	std::cout << "\n";

	SRP srp; // = 100;
	srp = SCISSOR;

	SRP1 srp1;
	srp1 = SRP1::SCISSOR1;

	// player = SRP1::ROCK1;  // 할당 못한다.

	std::cout << "SRP Size: " << sizeof(SRP) << std::endl;
	std::cout << "SRP1 Size: " << sizeof(SRP1) << std::endl;

	int Result = player - com;
	
	if(Result == 1 || Result == -2)
	/*if ((player == SCISSOR && com == PAPER) ||
		(player == SCISSOR && com == 1) || 
		(player == PAPER && com == SCISSOR))
		*/
		std::cout << "당신이 이겼습니다." << std::endl;
	else if (player == com)
		std::cout << "비겼습니다." << std::endl;
	else
		std::cout << "당신이 졌습니다." << std::endl;


	
	return 0;
}
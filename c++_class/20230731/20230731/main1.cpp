#include "GameManger.h"

/*
클래스의 static 멤버변수
일반 멤버변수는 클래스를 이용해서 개체를 생성하면 각각의 객체마다 메모리가 할당되게 된다.
static 멤버변수는 클래스를 이용해서 객체를 아무리 많이 생성해도 무조건 1개의 공간만 만들어지게 되고 각 객체들이 이를 공유해서 사용하게 된다.
static 멤버변수는 클래스 외부에 해당 static 변수를 사용하겠다는 정의부분이 반드시 필요하다.
	변수타입 클래스이름::변수이름; 으로 정의할 수 있다.
	변수타입 클래스이름::변수이름 = 초기값; 으로도 정의할 수 있다.
*/

class CStatic
{
public:
	CStatic()
	{
	}

	~CStatic()
	{
	}
public:
	int mNumber1;
	static int mNumberStatic;
	static int mNumberStatic2;

public:
	void Output()
	{
		std::cout << "Output Fuction" << std::endl;
		std::cout << "mNumber1: " << mNumber1 << std::endl;
		std::cout << "mNumberStatic: " << mNumberStatic << std::endl;
		std::cout << "mNumberStatic2: " << mNumberStatic2 << std::endl;
	}

	static void OutputStatic()
	{
		std::cout << "OutputStatic Fuction" << std::endl;

		// static 멤버함수는 this가 없다. 그렇기 때문에 일반 멤버변수에 접근할 수 없고 static 멤버변수만 사용이 가능하다.
		// std::cout << "mNumber1: " << mNumber1 << std::endl;
		std::cout << "mNumberStatic: " << mNumberStatic << std::endl;
		std::cout << "mNumberStatic2: " << mNumberStatic2 << std::endl;
	}
};

// 클래스 외부에 해당 static 변수를 사용하겠다는 정의
int CStatic::mNumberStatic;
int CStatic::mNumberStatic2;

int main()
{
	CStatic st1, st2;

	st1.mNumber1 = 100;
	st2.mNumber1 = 200;

	st1.mNumberStatic = 300;
	st2.mNumberStatic = 400;
	CStatic::mNumberStatic = 500;

	st1.Output();
	st2.Output();

	st1.OutputStatic();
	st2.OutputStatic();
	CStatic::OutputStatic();

}


//int main()
//{
//
//	CGameManger		Mgr;
//
//	// 전체 게임 초기화
//	Mgr.Init();
//
//	// 전체 게임 동작
//	Mgr.Run();
//
//	return 0;
//}
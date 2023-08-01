#include "GameManger.h"

/*
클래스의 static 멤버변수
일반 멤버변수는 클래스를 이용해서 개체를 생성하면 각각의 객체마다 메모리가 할당되게 된다.
static 멤버변수는 클래스를 이용해서 객체를 아무리 많이 생성해도 무조건 1개의 공간만 만들어지게 되고 각 객체들이 이를 공유해서 사용하게 된다.
static 멤버변수는 클래스 외부에 해당 static 변수를 사용하겠다는 정의부분이 반드시 필요하다.
	변수타입 클래스이름::변수이름; 으로 정의할 수 있다.
	변수타입 클래스이름::변수이름 = 초기값; 으로도 정의할 수 있다.
*/
/*
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
		// std::cout << "mNumber1: " << mNumber1 << std::endl; // error
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

	return 0;
}
*/

/*
class CSingleton
{
	// 외부에서 추가적으로 생성하지 못하도록 막기위해 private로 생성
private:
	CSingleton()
	{
	}

	~CSingleton()
	{
	}

	// 싱글톤 객체가 생성되고 해당 메모리 주소를 저장하기 위한 변수를 생성한다.
private:
	static CSingleton* mInst;

public:
	static CSingleton* GetInst()
	{
		
		// mInst가 nullptr이라는 것은 동적할당된 객체의 메모리 주소가 아직 없다는 것이다.
		// 그러므로 CSingleton 클래스를 하나 동적할당하고 그 메모리 주소를 mInst변수에 저장해둔다.
		// 하지만 mInst가 nullptr이 아니라면 이미 동적할당된 메모리 주소를 가지고 있으므로 그냥 그 주소를 리턴만해준다.
		if (nullptr == mInst)
			mInst = new CSingleton;

		return mInst;

	}

	static void DestroyInst()
	{
		// nullptr이 아닐때 delete하면 크래쉬가 발생할 수 있다.
		if (nullptr != mInst)
		{
			delete mInst;
			mInst = nullptr;
		}
	}

};
*/


int main()
{
	// 1. GetInst 함수 호출하여 CGameManager 인스턴스 초기화
	// 2. 싱글톤 인스턴스에 대한 포인터 반환
	// 3. 해당 인스턴스에서 Init() 함수호출 -> 실패시 싱글톤 인스턴스 파괴
	if (CGameManager::GetInst()->Init() == false)
	{
		CGameManager::DestoryInst();
		return 0;
	}

	// 초기화 성공시 게임실행 함수 호출
	CGameManager::GetInst()->Run();

	// 게임실행 후 싱글톤 인스턴스 삭제하여 메모리 해제
	CGameManager::DestoryInst();

	// CGameManager가 싱글톤 객체가 되었으므로 객체 생성불가
	/*
		CGameManager		Mgr;

		// 전체 게임 초기화
		Mgr.Init();

		// 전체 게임 동작
		Mgr.Run();
	*/

	return 0;
}
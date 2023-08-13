#pragma once

#include "info.h"

enum class EMainMenu
{
	None,
	Battle,
	Store,
	Inventory,
	Exit
};

class CGameManager
{
// Singleton패턴을 위한 생성자 private로 선언
private:
	CGameManager();
	~CGameManager();

private:
	// CSingleton 클래스 동적할당
	static CGameManager* mInst;

public:
	
	static CGameManager* GetInst()
	{
		// 메모리 주소를 mInst변수에 저장
		if (nullptr == mInst)
			mInst = new CGameManager;

		// nullptr이 아니라면 이미 동적할당된 메모리 주소를 가지고 있으므로 
		// 그냥 그 주소를 리턴만 해준다.
		return mInst;
	}

	// 할당된 메모리 해제
	static void DestroyInst()
	{
		if (nullptr != mInst)
		{
			delete mInst;

			mInst = nullptr;
		}
	}

private:
	EMainMenu Menu();

public:
	void Init();
	void Run();

};


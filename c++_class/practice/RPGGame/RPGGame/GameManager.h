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
// Singleton패턴 을 위한 생성자 private로 선언
private:
	CGameManager();
	~CGameManager();

private:
	// CGameManager 메모리 동적 할당을 위한 포인터 변수 선언
	// 공간 마련
	static CGameManager* mInst;

public:
	
	static CGameManager* GetInst()
	{
		// 메모리 주소를 mInst변수에 저장
		// 객체 안에 직접 데이터를 저장하는 것이 아니라 힙 영역에 따로 저장이 되고
		// 객체는 데이터들이 어디에 있는지 알려주는 정보만 저장된다.
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
	bool Init();
	void Run();

};


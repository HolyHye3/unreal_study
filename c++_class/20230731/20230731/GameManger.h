#pragma once

#include "Info.h"
#include "BattleManager.h"

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
private:
	CGameManager();
	~CGameManager();

	
private:
	// 싱글톤 객체를 생성하고 해당 메모리 주소를 저장하기 위한 변수
	static CGameManager* mInst;

public:
	static CGameManager* GetInst()
	{
		if (nullptr == mInst)
			mInst = new CGameManager;
		// 싱글톤 인스턴스에 대한 포인터 반환
		return mInst;
	}

	static void DestoryInst()
	{
		if (nullptr != mInst)
		{
			delete mInst;
			mInst = nullptr;
		}
	}

// 변수가 많아 용량이 크므로 무조건 용량이 적은 메모리 주소(8바이트)로 넘겨준다.
// 메모리 크기가 크다면 무조건 포인터로 넘겨줌ㅋ (배열, 구조체, 클래스 등)
private:
	// 만약 일반 변수로 생성했다면 해당 게임의 용량이 커질 수록 게임 메니저의 크기가 늘어날 것이다.
	// 만약 일반 변수로 생성했다면 게임 메니저가 제거될 때 까지 해당 게임의 메모리도 제거가 되지 않을 것이다.
	// 동적할당했기 때문에 게임 메니저만 유지하고 해당 게임의 메모리는 제거할 수가 있는 것.
	// CBattleManager* mBattleMgr;

private:
	EMainMenu Menu();

public:
	bool Init();
	void Run();
};


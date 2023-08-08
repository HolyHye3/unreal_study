#pragma once

#include "GameInfo.h"


class CGameManager
{
private:
	CGameManager();
	~CGameManager();

private:
	static CGameManager* mInst;

public:
	static CGameManager* GetInst()
	{
		if (!mInst)
			mInst = new CGameManager;
		return mInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(mInst);

		/*if (mInst)
		{
			delete mInst;
			mInst = nullptr;
		}*/
	}

private:
	// Instance Handle -> 윈도우즈 운영체제에서 실행되는 프로그램들을 구별하기 위한 ID값
	HINSTANCE	mhInst;
	HWND		mhwnd;
	Resolution	mRS;
	static bool mLoop;

public:
	bool Init(HINSTANCE hInst);
	int Run();


};
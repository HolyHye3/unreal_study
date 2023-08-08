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
	// Instance Handle -> �������� �ü������ ����Ǵ� ���α׷����� �����ϱ� ���� ID��
	HINSTANCE	mhInst;
	HWND		mhwnd;
	Resolution	mRS;
	static bool mLoop;

public:
	bool Init(HINSTANCE hInst);
	int Run();


};
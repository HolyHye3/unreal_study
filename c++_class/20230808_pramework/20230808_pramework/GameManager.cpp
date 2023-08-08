#include "GameManager.h"

CGameManager* CGameManager::mInst = nullptr;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
}

bool CGameManager::Init(HINSTANCE hInst)
{
	mhInst = hInst;

	mRS.Width = 1280;
	mRS.Height = 720;

	return true;
}

int CGameManager::Run()
{

	MSG msg;

	// 기본 메시지 루프입니다:
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// 메세지가 없는 부분.
		else
		{
			
		}
	}


	return 0;
}

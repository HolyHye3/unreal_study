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

	// �⺻ �޽��� �����Դϴ�:
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// �޼����� ���� �κ�.
		else
		{
			
		}
	}


	return 0;
}

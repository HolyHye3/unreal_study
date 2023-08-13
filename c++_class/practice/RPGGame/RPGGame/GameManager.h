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
// Singleton������ ���� ������ private�� ����
private:
	CGameManager();
	~CGameManager();

private:
	// CSingleton Ŭ���� �����Ҵ�
	static CGameManager* mInst;

public:
	
	static CGameManager* GetInst()
	{
		// �޸� �ּҸ� mInst������ ����
		if (nullptr == mInst)
			mInst = new CGameManager;

		// nullptr�� �ƴ϶�� �̹� �����Ҵ�� �޸� �ּҸ� ������ �����Ƿ� 
		// �׳� �� �ּҸ� ���ϸ� ���ش�.
		return mInst;
	}

	// �Ҵ�� �޸� ����
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


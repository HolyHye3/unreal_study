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
// Singleton���� �� ���� ������ private�� ����
private:
	CGameManager();
	~CGameManager();

private:
	// CGameManager �޸� ���� �Ҵ��� ���� ������ ���� ����
	// ���� ����
	static CGameManager* mInst;

public:
	
	static CGameManager* GetInst()
	{
		// �޸� �ּҸ� mInst������ ����
		// ��ü �ȿ� ���� �����͸� �����ϴ� ���� �ƴ϶� �� ������ ���� ������ �ǰ�
		// ��ü�� �����͵��� ��� �ִ��� �˷��ִ� ������ ����ȴ�.
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
	bool Init();
	void Run();

};


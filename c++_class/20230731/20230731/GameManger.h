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
	// �̱��� ��ü�� �����ϰ� �ش� �޸� �ּҸ� �����ϱ� ���� ����
	static CGameManager* mInst;

public:
	static CGameManager* GetInst()
	{
		if (nullptr == mInst)
			mInst = new CGameManager;
		// �̱��� �ν��Ͻ��� ���� ������ ��ȯ
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

// ������ ���� �뷮�� ũ�Ƿ� ������ �뷮�� ���� �޸� �ּ�(8����Ʈ)�� �Ѱ��ش�.
// �޸� ũ�Ⱑ ũ�ٸ� ������ �����ͷ� �Ѱ��ܤ� (�迭, ����ü, Ŭ���� ��)
private:
	// ���� �Ϲ� ������ �����ߴٸ� �ش� ������ �뷮�� Ŀ�� ���� ���� �޴����� ũ�Ⱑ �þ ���̴�.
	// ���� �Ϲ� ������ �����ߴٸ� ���� �޴����� ���ŵ� �� ���� �ش� ������ �޸𸮵� ���Ű� ���� ���� ���̴�.
	// �����Ҵ��߱� ������ ���� �޴����� �����ϰ� �ش� ������ �޸𸮴� ������ ���� �ִ� ��.
	// CBattleManager* mBattleMgr;

private:
	EMainMenu Menu();

public:
	bool Init();
	void Run();
};


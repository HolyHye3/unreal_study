#pragma once

#include "info.h"

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

	static void DestroyInst()
	{
		if (nullptr != mInst)
		{

		}
	}




};


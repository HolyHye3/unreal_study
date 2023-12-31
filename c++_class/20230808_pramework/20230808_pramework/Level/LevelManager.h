#pragma once

// ../ : ��������
#include "../GameManager.h"

class CLevelManager
{
private:
	CLevelManager();
	~CLevelManager();

private:
	static CLevelManager* mInst;

public:
	static CLevelManager* GetInst()
	{
		if (!mInst)
			mInst = new CLevelManager;
		return mInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(mInst);
	}

private:
	class CLevel* mLevel;


public:
	void Init();
	void Input(float DeltaTime);
	void Update(float DeltaTime);
	void Collision(float DeltaTime);

	void Rander(HDC hDc);
	
};


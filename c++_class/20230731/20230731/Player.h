#pragma once

#include "Info.h"

enum class EJob
{
	None,
	Knight,
	Archer,
	Magicion,
	End
};

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

private:
	char	mName[32];
	EJob	mJob;
	int		mAttack;
	int		mArmor;
	int		mHP;
	int		mHPMax;
	int		mMP;
	int		mMPMax;
	int		mLevel;
	int		mExp;
	int		mMoney;

public:
	int GetAttack()
	{
		return mAttack;
	}

	int GetArmor()
	{
		return mArmor;
	}

	bool Damage(int Dmg)
	{
		mHP -= Dmg;

		// ü���� 0���� �۰ų� ���� ���(�׾��� ���) true, �ƴϸ� false�� �����Ѵ�.
	}

	void AddExp(int Exp)
	{
		mExp += Exp;
	}

	void AddMoney(int Money)
	{
		mMoney += Money;
	}

	void setAttack(int Attack)
	{
		mAttack = Attack;
	}

	void Resurrection()
	{
		mExp = (int)(mExp * 0.9f);
		mMoney = (int)(mMoney * 0.9f);

		mHP = mHPMax;
		mMP = mMPMax;
	}


public:
	bool Init();
	void Output();
};
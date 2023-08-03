#include "Battle.h"
#include "Player.h"
#include "ObjectManager.h"
#include "Monster.h"

CBattle::CBattle()
{
}

CBattle::~CBattle()
{
}

EBattleMenu CBattle::Menu()
{
	std::cout << "1. ����" << std::endl;
	std::cout << "2. �ڷΰ���" << std::endl;
	std::cout << "�޴��� �����ϼ��� : " << std::endl;
	int Input;

	std::cin >> Input;

	if (Input <= (int)EBattleMenu::None || (int)EBattleMenu::Back)
		return EBattleMenu::None;

	return (EBattleMenu)Input;
	
}

EBattleResult CBattle::Attack(CPlayer* Player, CMonster* Monster)
{
	int Damage = Player->GetAttack() - Monster->GetArmor();

	// ���׿����� : ������ üũ�Ͽ� true�϶��� false�϶��� ���� ������ �� �ִ�.
	Damage = Damage < 1 ? 1 : Damage;

	// Damage �Լ��� �׾��� ��� true�� ��ȯ�ȴ�.
	if (Monster->Damage(Damage))
	{

	}
}


bool CBattle::Init(EBattleType Type)
{
	mBattleType = Type;

	return true;
}

void CBattle::Run()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	CMonster* Monster = CObjectManager::GetInst()->CreateMonster(mBattleType);

	while (true)
	{
		system("cls");

		std::cout << "========== Player ==========" << std::endl;
		Player->Output();
		std::cout << std::endl;


		std::cout << "========== Monster ==========" << std::endl;
		Monster->Output();
		std::cout << std::endl;

		switch (EBattleMenu)
		{
		case EBattleMenu::Attack:
			break;
		case EBattleMenu::Back:
			break;
		}
	}



}


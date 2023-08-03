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
	std::cout << "1. 공격" << std::endl;
	std::cout << "2. 뒤로가기" << std::endl;
	std::cout << "메뉴를 선택하세요 : " << std::endl;
	int Input;

	std::cin >> Input;

	if (Input <= (int)EBattleMenu::None || (int)EBattleMenu::Back)
		return EBattleMenu::None;

	return (EBattleMenu)Input;
	
}

EBattleResult CBattle::Attack(CPlayer* Player, CMonster* Monster)
{
	int Damage = Player->GetAttack() - Monster->GetArmor();

	// 삼항연산자 : 조건을 체크하여 true일때와 false일때의 값을 지정할 수 있다.
	Damage = Damage < 1 ? 1 : Damage;

	// Damage 함수는 죽었을 경우 true가 반환된다.
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


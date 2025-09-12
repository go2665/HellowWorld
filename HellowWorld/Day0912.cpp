#include "Day0912.h"

void Day0912_Struct()
{
	Enemy Goblin;
	Goblin.Name = "고블린1호";
	printf("이름 : %s\n", Goblin.Name.c_str());
	printf("생명력 : %.1f\n", Goblin.Health);
	printf("공격력 : %.1f\n", Goblin.AttackPower);
	printf("보상 : %d Gold\n", Goblin.DropGold);

	// 1. 고블린 동적할당 받아보기(맴버 변수 4개도 조절하기)
	Enemy* pGoblin = new Enemy();
	pGoblin->Name = "고블린2호";
	pGoblin->Health = static_cast<float>(rand() % 100 + 50);	// 50~150
	pGoblin->AttackPower = static_cast<float>(rand() % 10 + 5);	// 5~15
	pGoblin->DropGold = static_cast<int>(pGoblin->Health * pGoblin->AttackPower);
	PrintEnemy(pGoblin);
	delete pGoblin;
	pGoblin = nullptr;
	
	// 2. 다른 구조체 만들어보기(ex:아이템, 무기, 방어구)
	Weapon Sword;
	Sword.Name = "강철검";
	Sword.Desc = "튼튼하다.";
	Sword.AttackPower = 15.0f;
	Sword.Price = 200;

	//Enemy Goblins[3];
	Enemy* Goblins = nullptr;
	Goblins = new Enemy[3];
	for (int i = 0; i < 3; i++)
	{
		// std::to_string : 문자열이 아닌것을 string으로 변경해주는 함수
		Goblins[i].Name = "고블린" + std::to_string(i + 1) + "호";	
		PrintEnemy(&Goblins[i]);
	}
	delete[] Goblins;
	Goblins = nullptr;

	Enemy NamedGoblin("뽀스 고블린");
	PrintEnemy(&NamedGoblin);

	Enemy* pModiGoblin = new Enemy("모디 고블린", 5.0f);
	PrintEnemy(pModiGoblin);
	delete pModiGoblin;
	pModiGoblin = nullptr;

	Enemy CopyGoblin(NamedGoblin);	// 복사 생성자
	PrintEnemy(&CopyGoblin);

}

void Day0912_OperatorOverloading()
{
	Enemy Goblin1("고블린1호");
	Enemy Goblin2("고블린2호");

	Enemy FusionGoblin = Goblin1 + Goblin2;
	PrintEnemy(&FusionGoblin);
}

void PrintEnemy(const Enemy* pEnemy)
{
	printf("이름 : %s\n", pEnemy->Name.c_str());
	printf("생명력 : %.1f\n", pEnemy->Health);
	printf("공격력 : %.1f\n", pEnemy->AttackPower);
	printf("보상 : %d Gold\n", pEnemy->DropGold);
}

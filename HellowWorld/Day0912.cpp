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
	// 2. 다른 구조체 만들어보기(ex:아이템, 무기, 방어구)
}

#include "Tiger.h"

void Tiger::Hunt()
{
	printf("[%s]가 사냥을 합니다.\n", Name.c_str());
	SetEnergy(Energy - 0.5f);
	printf("[%s] : 에너지가 50% 감소합니다.\n", Name.c_str());
}

void Tiger::Move()
{
	printf("[%s]가 포효합니다.\n", Name.c_str());
	//Animal::Move();
	if (Energy < 0.1f)
	{
		printf("[%s] : 힘이 없어서 움직일 수 없습니다.\n", Name.c_str());
	}
	else
	{
		printf("[%s] : 움직입니다.\n", Name.c_str());
		SetEnergy(Energy - 0.1f);
		printf("[%s] : 에너지가 10% 감소합니다.\n", Name.c_str());
	}
}

void Tiger::MakeSound()
{
	Animal::MakeSound();
	printf("어흥!\n");
}

void Tiger::Attack(ICanBattle* InTarget)
{
	InTarget->TakeDamage(AttackPower);
}

void Tiger::TakeDamage(float InDamage)
{
	printf("[%.0f]의 피해를 입었다.", InDamage);
}

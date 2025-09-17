#include "Hawk.h"

void Hawk::Move()
{
	//Animal::Move();	// 부모인 Animal의 Move 실행하기
	if (Energy < 0.1f)
	{
		printf("[%s] : 힘이 없어서 움직일 수 없습니다.\n", Name.c_str());
	}
	else
	{
		printf("[%s] : 날아다닙니다.\n", Name.c_str());
		SetEnergy(Energy - 0.1f);
		printf("[%s] : 에너지가 10% 감소합니다.\n", Name.c_str());
	}
}

void Hawk::MakeSound()
{
	Animal::MakeSound();
	printf("빼액!\n");
}

void Hawk::Fly()
{
	printf("[%s]가 난다요.", Name.c_str());
}

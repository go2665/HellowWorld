#include "Dog.h"

void Dog::Move()
{
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

void Dog::MakeSound()
{
	Animal::MakeSound();
	printf("멍멍\n");
}

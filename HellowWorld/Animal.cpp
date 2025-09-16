#include "Animal.h"

void Animal::Move()
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

void Animal::MakeSound()
{
	printf("[%s] : 소리를 냅니다.\n", Name.c_str());
}

void Animal::Eat()
{
	printf("[%s] : 먹습니다.\n", Name.c_str());
	printf("[%s] : 에너지를 30% 회복합니다.\n", Name.c_str());
	SetEnergy(Energy + 0.3f);
}

void Animal::Sleep()
{
	printf("[%s] : 잠을 잡니다.\n", Name.c_str());
	printf("[%s] : 에너지를 100% 회복합니다.\n", Name.c_str());
	SetEnergy(1.0f);
	Age++;
	printf("[%s] : 나이가 한살 증가합니다. %d살 입니다.\n", Name.c_str(), Age);
}

void Animal::ShowInfo()
{
	printf("이름\t: %s\n", Name.c_str());
	printf("나이\t: %d 살\n", Age);
	printf("에너지\t: %.0f 퍼센트\n", Energy * 100);
}

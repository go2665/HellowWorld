#include "Dog.h"

void Dog::Move()
{
	if (Energy < 0.1f)
	{
		printf("[%s] : ���� ��� ������ �� �����ϴ�.\n", Name.c_str());
	}
	else
	{
		printf("[%s] : �����Դϴ�.\n", Name.c_str());
		SetEnergy(Energy - 0.1f);
		printf("[%s] : �������� 10% �����մϴ�.\n", Name.c_str());
	}
}

void Dog::MakeSound()
{
	Animal::MakeSound();
	printf("�۸�\n");
}

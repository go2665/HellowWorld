#include <stdio.h>
#include "Car.h"

Car::Car()
{
	printf("�ڵ����� �����Ǿ����ϴ�.");
}

Car::~Car()
{
	printf("�ڵ����� �����Ǿ����ϴ�.");
}

void Car::Accel()	// CarŬ������ Accel �Լ�
{
	printf("�ڵ����� �����մϴ�.\n");
}

void Car::Brake()
{
	printf("�ڵ����� �����մϴ�.\n");
}

void Car::HandleTurn()
{
	printf("�ڵ��� �����ϴ�.\n");
}

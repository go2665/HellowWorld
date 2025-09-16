#include <stdio.h>
#include "Car.h"

Car::Car(const char* InName)
	: Name(InName)
{
	printf("[%s] 자동차가 생성되었습니다.\n", Name.c_str());
}

Car::~Car()
{
	printf("[%s] 자동차가 삭제되었습니다.\n", Name.c_str());
}

void Car::Accel()	// Car클래스의 Accel 함수
{
	printf("자동차를 가속합니다.\n");
}

void Car::Brake()
{
	printf("자동차를 감속합니다.\n");
}

void Car::HandleTurn()
{
	printf("핸들을 돌립니다.\n");
}

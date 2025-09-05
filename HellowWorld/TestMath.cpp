#include <stdio.h>
#include "TestMath.h"
#include "TestMath.h"

void PrintHelloWorld()
{
	printf("Hello World!\n");
	return;
}

int Sum(int Test1, int Test2)		// int Sum(int, int); 이 선언을 정의했다.
{
	int Result = Test1 + Test2;

	return Result;
}

float Sum(float Test1, float Test2)
{
	float Result = Test1 + Test2;
	return Result;
}

int Multiply(int Number1, int Number2)
{
	return Number1 * Number2;
}

int TestRecurcive(int Number)
{
	if (Number < 2)
	{
		return 1;
	}
	printf("Recurcive : %d\n", Number);
	return TestRecurcive(Number - 1);
}

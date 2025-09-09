#include "Day0909.h"
#include <iostream>
#include <stdio.h>

void PointerParameter(int* pNumber)
{
	(*pNumber) = (*pNumber) * 2;	// 입력받은 주소에 있는 int값을 2배로 만들기
}

void TestPointer(int* pInt, float pFloat)
{
	(*pInt) += 3;
	//(pFloat) /= 2;
	(pFloat) *= 0.5f;	// *과 / 중에 선택을 할 수 있는 상황이면 *가 성능상 유리하다.
}

void Day0909()
{
	// 간단 실습
	// Number라는 변수를 하나 선언하고 포인터 변수 p에 Number의 주소를 저장하기
	// p를 이용해서 Number의 값을 변경시키기

	float Number = 123.01f;
	int Number2 = 10;
	float* p = nullptr;	// p는 완전히 비어있다.
	p = &Number;		// p에 Number의 주소를 저장했다.
	//p = &Number2;		// 타입이 다르기 때문에 안된다.

	(*p) = 100.0f;

	PointerParameter(&Number2);

	// 간단 실습
	// int*와 float*를 파라메터로 받은 함수 만들기
	// int*로 받은 값은 3 더하기, float*로 받은 값은 절반으로 만들기

	float* test = p;
	test++;

	//(*test) = 20;	// 매우 위험. 절대 하면 안됨. 어차피 터짐.

	int i = 0;
}

void Day0909_ArrayAndPointer()
{
	// 배열과 포인터(기본적으로 같다.)
	int Array[5] = { 10, 20, 30, 40, 50 };
	int* pArray = Array;	// 배열의 이름은 배열의 첫번째 요소의 주소와 같다.
	int* pArray2 = &Array[0];	// Array == &Array[0] 두개는 같은 의미

	// pArray를 이용해서 Array[2]를 300으로 수정하기
	*(pArray + 2) = 300;

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\n");

	for (int data : Array)		// range-for : Array안의 요소들을 순차적으로 하나씩 data에 넣어 처리
	{
		printf("%d ", data);
	}
	printf("\n");
		
}

void Day0909_DynamicAllocation()
{
	// C 스타일 메모리 할당 및 해제
	int Size = 5;
	int* Array = nullptr;
	Array = (int*)malloc(sizeof(int) * Size);	// int 5개짜리 메모리 블럭 할당 받기

	Array[2] = 20;
	/*
	작업들
	*/

	free(Array);		// Array를 해제. malloc을 했으면 무조건 free부터 만들고 작업할것
	Array = nullptr;	// 댕글링 포인터 방지

	// C++ 스타일 메모리 할당 및 해제
	int* Data = new int(5);		// int 하나를 할당 받는데 주소가 가리키는 값은 5를 설정해라
	delete Data;
	Data = nullptr;
	Array = new int[10];	// int 10개짜리 배열을 만들어라
	delete[] Array;				// 배열은 반드시 이렇게 해제해야 한다.
	//delete Array;				// 절대 이렇게 하면 안된다. 이렇게 하면 Array[0]부분만 할당 해제가 된다.
	Array = nullptr;

	// 간단 실습
	// 1. int 배열 할당받기(첫 할당은 3개만)
	// 2. 숫자를 입력받을 때마다 배열에 추가하기
}

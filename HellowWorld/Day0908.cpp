#include "Day0908.h"
#include <stdio.h>
#include <limits.h>
#include <random>

void Day0908()
{
	int a = 10;
	int Array[5];	// int 5개를 관리하는 배열
	Array[0] = 10;	// 배열의 첫번째 요소에 10을 대입한다.
	Array[3] = 40;	// 배열의 네번째 요소에 40을 대입한다.

	int Array2[5] = { 1,2,3,4,5 };
	int Array3[5] = { 1,2,3 };
	int Array4[5] = { 0 };

	const int Size = 5;
	int Array5[Size] = {};
	//sizeof(Array5);	// Array5의 전체 바이트 크기를 알 수 있다.
	//sizeof(Array5[0]);	// Array5의 요소 하나의 크기를 알 수 있다.
	int ElementCount = sizeof(Array5) / sizeof(Array5[0]);	// Array5의 요소 개수

	//int Size2 = 5;
	//int Array6[Size2] = {};	// 배열 선언할 때 크기를 변수로 지정할 수는 없다.

	// Array[5] = 60;	// 버퍼오버런. 배열 영역 밖을 접근하려고 하기 때문에 에러가 발생한다.

	// 간단 실습
	// 1. 배열 만들고 초기화 해보기
	// 2. 배열의 모든 요소의 값을 더하고 평균 구하기
	// 3. 배열의 모든 요소 중 최대값과 최소값 구하기

	// 1.
	int Numbers[3] = { 5, 8, 3 };

	// 2. 
	int Sum = 0;
	float Average = 0.0f;
	int ArrayCount = static_cast<int>(sizeof(Numbers) / sizeof(Numbers[0]));
	for (int i = 0; i < ArrayCount; i++)
	{
		Sum += Numbers[i];
	}
	Average = Sum / static_cast<float>(ArrayCount);
	printf("평균은 %.2f입니다.\n", Average);

	int MaxNumber = INT_MIN;
	int MinNumber = INT_MAX;
	for (int i = 0; i < ArrayCount; i++)
	{
		if (MaxNumber < Numbers[i])
		{
			MaxNumber = Numbers[i];
		}
		if (MinNumber > Numbers[i])
		{
			MinNumber = Numbers[i];
		}
	}

	int Array6[4][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {0,1,2} };
	int test = Array6[1][2];	// test = 6
	int Array7[12] = { 1,2,3,4,5,6,7,8,9,0,1,2 };

	Shuffle(Array7, 12);

	int i = 0;
}

void Day0908_Cast()
{
	// 캐스트(Cast)
	int a = 10;
	float b = 15.5f;

	a = (int)b;	// b를 int형으로 캐스팅해서 a에 대입한다. (C스타일, 명시적 캐스팅)
	a = b;		// b를 a에 대입한다. 그런데 a와 b는 타입이 다르니까 b를 a로 암시적으로 캐스팅해서 대입한다.(C스타일, 암시적 캐스팅)
	b = a;		// 암시적 캐스팅은 대체로 표현이 작은쪽에서 큰쪽으로는 문제없는 경우가 많다.

	// C++ 캐스팅
	// static_cast : C스타일 캐스팅을 안전하게 만든 것. 컴파일 타임에 결정됨
	// dynamic_cast : 다음에(클래스 이후에)
	// const_cast : const 속성을 제거하거나 추가하는데 사용. 사용하지 않는 것이 권장.
	// reinterpret_cast : C스타일 캐스팅에서 위험한 부분. 원래 타입의 구조를 무시하고 새 타입으로 해석하게 한다.

	a = static_cast<int>(b);	// b를 int형으로 캐스팅해서 a에 대입한다. (C++스타일, 명시적 캐스팅)

}

void Shuffle(int Array[], int Length)
{
	/*
	* 1. 배열의 마지막 요소에서 첫 요소까지 순회.
	* 2. 현재 요소의 인덱스(i)와 , 0~i 중 임의의 인덱스(j)를 선택한다.
	* 3. i번째 요소와 j번째 요소를 서로 교환
	* 4. i가 0이 될 때까지 반복
	*/

	for (int i = Length - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		int Temp = Array[i];
		Array[i] = Array[j];
		Array[j] = Temp;
	}
}

void TestRef(int& OutData, const int& ReadData)
{
	OutData *= ReadData;
	//ReadData = 10;
}

void Day0908_Ref()
{
	int Number = 10;
	int Number2 = 2;
	int& Ref = Number;	// Number의 참조는 Ref다.
	//
	
	TestRef(Number, Number2);

	int i = 0;
	
}

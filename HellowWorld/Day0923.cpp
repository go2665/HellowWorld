#include "Day0923.h"
#include "Coordinate.h"
#include "Calcurator.h"
#include <cstdio>
#include <vector>

void Day0923::TestTemplateClass()
{
	Coordinate<int> PositionInt(1,3);
	Coordinate<float> PositionFloat(0.05f,5.7f);

	printf("PositionInt : %d, %d\n", PositionInt.x, PositionInt.y);
	printf("PositionFloat : %f, %f\n", PositionFloat.x, PositionFloat.y);

	PositionInt.Print();
	PositionFloat.Print();

	Coordinate<std::string> PositionString("A", "B");
	PositionString.Print();

}

void Day0923::TestCalcurator()
{
	Calcurator Calc;
	int ResultInt = Calc.Add(1, 3);
	float ResultFloat = Calc.Add(2.5f, 7.3f);
	Coordinate<int> ResultCoord = Calc.Add(Coordinate<int>(1, 2), Coordinate<int>(3, 4));

	ResultInt = Calc.Multiply(5, 3);
	ResultFloat = Calc.Multiply(3.5f, 2.0f);
	ResultCoord = Calc.Multiply(Coordinate<int>(1, 2), Coordinate<int>(3, 4));

	ResultFloat = Calc.Add(2.5f, 7.3f);
	bool ResultBool = Calc.Equal(9.8f, ResultFloat);
	bool ResultBool2 = (9.8 == ResultFloat);

	int i = 0;
}

void Day0923::TestVector()
{
	// #include <vector> 필수
	std::vector<int> Scores;	// int배열 Scores를 만듬
	Scores.reserve(5);			// 내가 사용할 것으로 예상되는 최대 크기를 적는 것이 좋음

	Scores.push_back(10);		// vector의 뒤에 추가
	Scores.push_back(20);
	Scores.push_back(30);

	// 특정 값으로 초기화 된 vector를 만들고 싶을 때(3개가 "무명"으로 초기화된 vector)
	std::vector<std::string> Names(3, "무명");	

	printf("첫번째 점수 : %d\n", Scores[0]);	// 배열 사용하듯이 사용. 다만 범위를 벗어나면 터진다.
	//printf("네번째 점수 : %d\n", Scores[3]);	// 터짐
	printf("두번째 점수 : %d\n", Scores.at(1));	// 두번째 요소에 접근
	//printf("네번째 점수 : %d\n", Scores.at(3));	// 네번째 요소에 접근(=예외를 발생)
	printf("세번째 점수 : %d\n", Scores.back());		// 마지막 요소에 접근
	printf("첫번째 점수 : %d\n", Scores.front());	// 첫번째 요소에 접근

	// 일반적인 순회 방식
	printf("모든 점수 : ");
	for (int i = 0; i < Scores.size(); i++)
	{
		printf("%d ", Scores[i]);
	}
	printf("\n");

	// 반복자를 통한 순회 방식
	printf("모든 점수 : ");
	for (auto iter = Scores.begin(); iter != Scores.end(); iter++)
	//for (std::vector<int>::iterator iter = Scores.begin(); iter != Scores.end(); iter++)
	{
		printf("%d ", *iter);	// 현재 iter위치에 있는 값을 출력
	}
	printf("\n");

	// 용량 확인(Size, Capacity)
	//	Size : 현재 vector에서 실제 사용되는 값이 들어있는 개수
	//	Capacity : 현재 vector에 할당된 메모리 개수(실제 사용하지 않은 것도 포함)
	printf("현재 점수 개수(Size) : %u\n", static_cast<unsigned int>(Scores.size()));
	printf("할당된 메모리(Capacity) : %u\n", static_cast<unsigned int>(Scores.capacity()));

	// 삭제하기 : 뒤에서 삭제하는 것이 좋다.
	Scores.pop_back(); // 마지막 원소 하나 제거
	printf("모든 점수 : ");
	for (auto iter = Scores.begin(); iter != Scores.end(); iter++)
	{
		printf("%d ", *iter);
	}
	printf("\n");

	Scores.clear();	// 모든 원소 제거(Size는 0, Capacity는 그대로)
	printf("모든 점수 : ");
	for (auto iter = Scores.begin(); iter != Scores.end(); iter++)
	{
		printf("%d ", *iter);	
	}
	printf("\n");
	printf("현재 점수 개수(Size) : %u\n", static_cast<unsigned int>(Scores.size()));
	printf("할당된 메모리(Capacity) : %u\n", static_cast<unsigned int>(Scores.capacity()));

	if (Scores.empty())
	{
		printf("Scores가 비었다.\n");
	}

	// 중간에 추가 삭제하는 함수.(어지간하면 쓰지 말것)
	//Scores.insert();
	//Scores.erase();

	// 스왑 앤 팝
	// - 백터의 원소들의 순서가 중요하지 않을 때 사용가능.
	// - 중간에 있는 원소를 삭제할 때 마지막에 있는 원소와 서로 교환하고 pop_back으로 제거하는 전략
	std::vector<int> Numbers = { 10,20,30,40,50 };
	int DeleteNumber = 20;

	std::vector<int>::iterator FindIter = std::find(Numbers.begin(), Numbers.end(), DeleteNumber);
	if (FindIter != Numbers.end())
	{
		// 찾았다.
		*FindIter = Numbers.back();	// 찾은 위치에 마지막 값을 넣어라.
		Numbers.pop_back();			// 마지막 요소 제거
	}
	else
	{
		// 없다.
	}

	int i = 0;
}

void Day0923::TestVectorPractice()
{
	// std::vector 연습하기
	/*
		1. 정수 입력받고 출력하기
		2. 최대, 최소 구하기
		3. 정렬하기 (std::sort)
		4. 특정 값 찾기 (std::find없이)
		5. 중복 제거하기
		6. 벡터 두개 합치기
		7. 문자열 뒤집어서 출력하기
		8. 모든 요소 더하기
	*/
}

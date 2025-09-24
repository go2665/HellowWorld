#include "Day0924.h"
#include <vector>
#include <algorithm>

bool operator<(const SortTest& Left, const SortTest& Right)
{
	return Left.a < Right.a;
}

void PrintVector(std::vector<int>& InVector)
{
	printf("Vector : ");
	for (int n : InVector)
	{
		printf("%d ", n);
	}
	printf("\n");
}

void PrintVector(std::vector<SortTest>& InVector)
{
	printf("Vector : ");
	for (const SortTest& n : InVector)
	{
		printf("(%d, %.1f) ", n.a, n.b);
	}
	printf("\n");
}

void Day0924::TestLambda()
{
	std::vector<int> Numbers = { 5,7,1,9,3 };
	//std::sort(Numbers.begin(), Numbers.end());	// 오름차순 정렬
	PrintVector(Numbers);

	std::sort(Numbers.begin(), Numbers.end(), 
		[](int a, int b)
		{
			return a > b;	// 내림차순 정렬
		}
	);
	PrintVector(Numbers);
}

void Day0924::TestLambda2()
{
	std::vector<SortTest> Test = { {1, 5.0f}, {7, 3.5f}, {5, 10.0f} };
	PrintVector(Test);
	std::sort(Test.begin(), Test.end());
	PrintVector(Test);
	std::sort(Test.begin(), Test.end(),
		[](const SortTest& first, const SortTest& second)
		{
			return first.b < second.b;
		}
	);
	PrintVector(Test);

	// 람다로 a,b 내림차순 정렬 각각 만들어보기
}

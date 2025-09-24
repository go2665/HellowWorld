#pragma once
#include <type_traits>

class Day0924
{
public:
	void TestLambda();
	void TestLambda2();
	void TestLambdaPractice();
	void TestSet();
	void TestSetPractice();
	void TestMap();
	void TestUnorderedMap();
};

struct SortTest
{
	int a;
	float b;

	SortTest(int InA, float InB) : a(InA), b(InB){}

	bool operator==(const SortTest& other)const
	{
		return a == other.a;
	}
};

namespace std
{
	template <>
	struct hash<SortTest>
	{
		size_t operator()(const SortTest& InValue) const
		{
			return static_cast<size_t>(InValue.a);
		}
	};
}

bool operator<(const SortTest& Left, const SortTest& Right);

enum class CharacterType
{
	Warrior,
	Mage,
	Archer,
	Thief
};

struct CharacterStatus
{
	int Level = 0;
	int Health = 100;
	int Attack = 10;
};
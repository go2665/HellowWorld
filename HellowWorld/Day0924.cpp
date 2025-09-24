#include "Day0924.h"
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <cstdio>
#include <iostream>

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
	//std::sort(Numbers.begin(), Numbers.end());	// �������� ����
	PrintVector(Numbers);

	std::sort(Numbers.begin(), Numbers.end(), 
		[](int a, int b)
		{
			return a > b;	// �������� ����
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
}

void Day0924::TestLambdaPractice()
{
	// ���� �ǽ�
	// 1. ���ٷ� SortTest�� a,b �������� ���� ���� ������
	std::vector<SortTest> Test = { {1, 5.0f}, {7, 3.5f}, {5, 10.0f} };
	PrintVector(Test);
	std::sort(Test.begin(), Test.end(),
		[](const SortTest& Left, const SortTest& Right)
		{
			return Left.a > Right.a;
		}
	);
	PrintVector(Test);
	std::sort(Test.begin(), Test.end(),
		[](const SortTest& Left, const SortTest& Right)
		{
			return Left.b > Right.b;
		}
	);
	PrintVector(Test);

	// 2. Ư�� ������ �����ϴ� ù��° ���� ã��
	std::vector<int> Numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int Threshold = 5;	// threshold���� ū ù��° ���� ã��
	std::vector<int>::iterator iter = std::find_if(Numbers.begin(), Numbers.end(), 
		[Threshold](int n)
		{
			return Threshold < n;	// ĸ���� Threshold���� ũ�� true
		});
	if (iter != Numbers.end())
	{
		// ã�Ҵ�.
		printf("%d���� ū ù��° ���Ҵ� %d�Դϴ�.\n", Threshold, *iter);
	}
}

void PrintSet(const std::set<int>& InSet)
{
	printf("Set : ");
	for (int n : InSet)
	{
		printf("%d ", n);
	}
	printf("\n");
}

void Day0924::TestSet()
{
	//#include <set> �ʼ�
	std::set<int> TestSet;
	
	printf("\nset�� �߰��ϱ�\n");
	TestSet.insert(30);
	TestSet.insert(10);
	TestSet.insert(50);
	TestSet.insert(20);
	TestSet.insert(30);	// ���õ�
	PrintSet(TestSet);

	printf("\nset�� ũ��\n");
	printf("size : %d\n", static_cast<int>(TestSet.size()));

	printf("\n���� ã��\n");
	int Target = 200;
	std::set<int>::iterator iter = TestSet.find(Target);	// ���� Ȯ�� + ���� Ȯ��
	if (iter != TestSet.end())
	{
		// ã�Ҵ�.
		printf("find : %d�� ã�ҽ��ϴ�.\n", Target);
	}
	else
	{
		// ��ã�Ҵ�.
		printf("find : %d�� ��ã�ҽ��ϴ�.\n", Target);
	}
	bool IsFind = TestSet.contains(Target);	// Target�� �ִ��� ������ Ȯ���ϴ� �Լ�
	if (IsFind)
	{
		// ã�Ҵ�.
		printf("contains : %d�� ã�ҽ��ϴ�.\n", Target);
	}
	else
	{
		// ��ã�Ҵ�.
		printf("contains : %d�� ��ã�ҽ��ϴ�.\n", Target);
	}

	printf("\n�ϳ��� �����ϱ�(30)\n");
	TestSet.erase(30);
	PrintSet(TestSet);

	printf("\n���� �����ϱ�\n");
	TestSet.clear();
	PrintSet(TestSet);

	printf("\n��Ʈ�� ������� �Ⱥ������ Ȯ���ϱ�\n");
	if (TestSet.empty())
	{
		// �����.
		printf("����ִ�.");
	}
	else
	{
		// �Ⱥ����.
		printf("�Ⱥ���ִ�.");
	}
}

void Day0924::TestSetPractice()
{
	/*
	1. �ߺ� ���� ���� �Է� �� ���    
		����ڰ� ���� ���� ������ �Է��ϸ� �ߺ� ���� �����ϰ� ����ϴ� ���α׷��� ��������.    
	2. ���� ����(������, ������, ������)    
		�� ���� set�� ���� ������, ������, �������� ���ϴ� �ǽ��� �غ�����.    
	3. Ư�� ���� ���� ���� Ȯ��    
		set�� Ư�� ���� ����ִ��� �˻��ϴ� ���α׷��� ��������.    
	4. ��������/�������� ���    
		set�� ���Ҹ� �������� �Ǵ� ������������ ����ϴ� �ǽ��� �غ�����.(�ݺ����� ����)
	5. ���ڿ����� �ߺ��Ǵ� ���� ����   ( aaabbc -> abc )
		���ڿ��� �Է¹޾� �ߺ��Ǵ� ���� ���� �����ϰ� ����ϴ� �ǽ��� �غ�����.    
	6. �ִ�, �ּڰ� ã��    
		set���� ���� ū ���� ���� ���� ã�� ����ϴ� �ǽ��� �غ�����.(�ݺ��ڸ� Ȱ���ϱ�)
	7. set�� vector�� ��ȯ    
		set�� ����� ���� vector�� �Űܼ� Ȱ���ϴ� ���α׷��� ��������.
	*/

	// 1. �ߺ� ���� ���� �Է� �� ���
	//printf("\n�ߺ� ���� ���� �Է� �� ���\n");
	//std::set<int> TestSet1;
	//int InputNumber = 0;
	//while (InputNumber != -1)
	//{
	//	printf("������ �Է��ϼ��� (-1: ����) : ");
	//	std::cin >> InputNumber;
	//	if (InputNumber != -1)
	//	{
	//		TestSet1.insert(InputNumber);
	//	}
	//}
	//PrintSet(TestSet1);

	// 2. ���� ����(������, ������, ������)
	std::set<int> TestSet2_1 = { 1,2,3,4,5 };
	std::set<int> TestSet2_2 = { 3,4,5,6,7 };
	std::set<int> TestSet2_Result;

	printf("\n2. ���� ����(������, ������, ������)\n");
	PrintSet(TestSet2_1);
	PrintSet(TestSet2_2);

	printf("������ = ");
	// ������
	TestSet2_Result = TestSet2_1;
	for (int n : TestSet2_2)
	{
		TestSet2_Result.insert(n);
	}
	PrintSet(TestSet2_Result);

	printf("������ = ");
	TestSet2_Result.clear();
	for (int n : TestSet2_2)
	{
		if (TestSet2_1.contains(n))
		{
			TestSet2_Result.insert(n);
		}
	}
	PrintSet(TestSet2_Result);

	printf("������ = ");
	TestSet2_Result = TestSet2_1;
	for (int n : TestSet2_2)
	{
		if (TestSet2_1.contains(n))
		{
			TestSet2_Result.erase(n);
		}
	}
	PrintSet(TestSet2_Result);

	// 4. ��������/�������� ���
	printf("\n4. ��������/�������� ���\n");
	std::set<int> TestSet4 = { 5,7,3,1,6,8,2,4,9 };
	PrintSet(TestSet4);

	printf("Set Reverse : ");
	for(auto iter = TestSet4.rbegin(); iter != TestSet4.rend() ; iter++)
	{
		printf("%d ", *iter);
	}
	printf("\n");

	// 5. ���ڿ����� �ߺ��Ǵ� ���� ����
	printf("\n5. ���ڿ����� �ߺ��Ǵ� ���� ����\n");
	std::string TestString = "Hello World!";	// "Helo Wrd!"
	std::set<char> TestSet5;
	std::string TestResult5;
	for (char c : TestString)	
		// for(auto iter = TestString.begin() ; iter != TestString.end() ; iter++
		// for(int i=0;i<TestString.size();i++)
	{
		if (!TestSet5.contains(c))
		{
			TestSet5.insert(c);
			TestResult5 += c;
		}
	}
	printf("Result = %s\n", TestResult5.c_str());

	// 6. �ִ밪, �ּҰ� ã��
	printf("\n6. �ִ밪, �ּҰ� ã��\n");
	std::set<int> TestSet6 = { 5,7,6,25,8,87,65,2,4,7,52 };
	PrintSet(TestSet6);
	if (!TestSet6.empty())
	{
		printf("�ִ밪 = %d, �ּҰ� = %d\n", *TestSet6.begin(), *TestSet6.rbegin());
	}

	// 7. set�� vector�� ��ȯ
	printf("\n7. set�� vector�� ��ȯ\n");
	std::set<int> TestSet7 = { 1,5,74,6,3,1,5,7,6,5 };
	PrintSet(TestSet7);
	std::vector<int> TestVector7_1(TestSet7.begin(), TestSet7.end());
	PrintVector(TestVector7_1);
	std::vector<int> TestVector7_2;
	TestVector7_2.reserve(TestSet7.size());
	for (int n : TestSet7)
	{
		TestVector7_2.push_back(n);
	}
	PrintVector(TestVector7_2);
	
}

std::string ToString(CharacterType InType)
{
	switch (InType)
	{
	case CharacterType::Warrior:
		return "����";
	case CharacterType::Mage:
		return "������";
	case CharacterType::Archer:
		return "�ü�";
	case CharacterType::Thief:
		return "����";
	default:
		break;
	}
	return "�� �� ����";
}
void PrintStatus(const CharacterStatus& InStatus)
{
	printf(" | ���� : %2d | ü�� : %3d | ���ݷ� : %2d\n", InStatus.Level, InStatus.Health, InStatus.Attack);
}

void Day0924::TestMap()
{
	std::map<CharacterType, CharacterStatus> Characters;

	Characters[CharacterType::Warrior] = { 10, 200, 15 };
	Characters[CharacterType::Mage] = { 8, 100, 5 };
	Characters[CharacterType::Archer] = { 12, 150, 20 };

	if (Characters.contains(CharacterType::Mage))	// ���� Ű�� �����ϴ� ���� �����ϱ� ���� �ݵ�� üũ�ؾ� �Ѵ�.
	{
		// �ִ�.
		CharacterStatus& MageStatus = Characters[CharacterType::Mage]; // []�����ڷ� Value�� ����
		printf("\n[] ���ٹ� : %s", ToString(CharacterType::Mage).c_str());
		PrintStatus(MageStatus);
	}
	else
	{
		// ����.
	}

	// ���� �׸� �����ϸ� �� �׸��� �����.
	CharacterStatus& ThiefStatus = Characters[CharacterType::Thief];	
	printf("[] ���� Ű ���� : %s", ToString(CharacterType::Thief).c_str());
	PrintStatus(ThiefStatus);

	printf("\n��ü ĳ���� ���\n");
	for (const auto& pair : Characters)
	//for( const std::pair<CharacterType, CharacterStatus>& pair : Characters)
	{
		printf("ĳ���� Ÿ�� : %6s", ToString(pair.first).c_str());
		PrintStatus(pair.second);	// first = Ű, second = value
	}

	printf("\n���� ����\n");
	Characters.erase(CharacterType::Thief);

	printf("\n��ü ĳ���� ���\n");
	for (const auto& pair : Characters)
	{
		printf("ĳ���� Ÿ�� : %6s", ToString(pair.first).c_str());
		PrintStatus(pair.second);	// first = Ű, second = value
	}

	printf("\n��ü ����\n");
	Characters.clear();
	printf("\n��ü ĳ���� ���\n");
	for (const auto& pair : Characters)
	{
		printf("ĳ���� Ÿ�� : %6s", ToString(pair.first).c_str());
		PrintStatus(pair.second);	// first = Ű, second = value
	}

	int i = 0;
	
}

void Day0924::TestUnorderedMap()
{
	std::unordered_map<SortTest, std::string> TestMap;
	SortTest Test1 = { 1, 2.5f };
	SortTest Test2 = { 3, 1.5f };
	TestMap[Test1] = "Hello";
	TestMap[Test2] = "World";
	// Ű���� Hash �Լ��� �־�� �Ѵ�.
	// Ű���� ������ ���� �� �ֵ��� == �����ڰ� �־�� �Ѵ�.
	int i = 0;
}

#include "Day0923.h"
#include "Coordinate.h"
#include "Calcurator.h"
#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

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
	// #include <vector> �ʼ�
	std::vector<int> Scores;	// int�迭 Scores�� ����
	Scores.reserve(5);			// ���� ����� ������ ����Ǵ� �ִ� ũ�⸦ ���� ���� ����

	Scores.push_back(10);		// vector�� �ڿ� �߰�
	Scores.push_back(20);
	Scores.push_back(30);

	// Ư�� ������ �ʱ�ȭ �� vector�� ����� ���� ��(3���� "����"���� �ʱ�ȭ�� vector)
	std::vector<std::string> Names(3, "����");	

	printf("ù��° ���� : %d\n", Scores[0]);	// �迭 ����ϵ��� ���. �ٸ� ������ ����� ������.
	//printf("�׹�° ���� : %d\n", Scores[3]);	// ����
	printf("�ι�° ���� : %d\n", Scores.at(1));	// �ι�° ��ҿ� ����
	//printf("�׹�° ���� : %d\n", Scores.at(3));	// �׹�° ��ҿ� ����(=���ܸ� �߻�)
	printf("����° ���� : %d\n", Scores.back());		// ������ ��ҿ� ����
	printf("ù��° ���� : %d\n", Scores.front());	// ù��° ��ҿ� ����

	// �Ϲ����� ��ȸ ���
	printf("��� ���� : ");
	for (int i = 0; i < Scores.size(); i++)
	{
		printf("%d ", Scores[i]);
	}
	printf("\n");

	// �ݺ��ڸ� ���� ��ȸ ���
	printf("��� ���� : ");
	for (auto iter = Scores.begin(); iter != Scores.end(); iter++)
	//for (std::vector<int>::iterator iter = Scores.begin(); iter != Scores.end(); iter++)
	{
		printf("%d ", *iter);	// ���� iter��ġ�� �ִ� ���� ���
	}
	printf("\n");

	// �뷮 Ȯ��(Size, Capacity)
	//	Size : ���� vector���� ���� ���Ǵ� ���� ����ִ� ����
	//	Capacity : ���� vector�� �Ҵ�� �޸� ����(���� ������� ���� �͵� ����)
	printf("���� ���� ����(Size) : %u\n", static_cast<unsigned int>(Scores.size()));
	printf("�Ҵ�� �޸�(Capacity) : %u\n", static_cast<unsigned int>(Scores.capacity()));

	// �����ϱ� : �ڿ��� �����ϴ� ���� ����.
	Scores.pop_back(); // ������ ���� �ϳ� ����
	printf("��� ���� : ");
	for (auto iter = Scores.begin(); iter != Scores.end(); iter++)
	{
		printf("%d ", *iter);
	}
	printf("\n");

	Scores.clear();	// ��� ���� ����(Size�� 0, Capacity�� �״��)
	printf("��� ���� : ");
	for (auto iter = Scores.begin(); iter != Scores.end(); iter++)
	{
		printf("%d ", *iter);	
	}
	printf("\n");
	printf("���� ���� ����(Size) : %u\n", static_cast<unsigned int>(Scores.size()));
	printf("�Ҵ�� �޸�(Capacity) : %u\n", static_cast<unsigned int>(Scores.capacity()));

	if (Scores.empty())
	{
		printf("Scores�� �����.\n");
	}

	// �߰��� �߰� �����ϴ� �Լ�.(�������ϸ� ���� ����)
	//Scores.insert();
	//Scores.erase();

	// ���� �� ��
	// - ������ ���ҵ��� ������ �߿����� ���� �� ��밡��.
	// - �߰��� �ִ� ���Ҹ� ������ �� �������� �ִ� ���ҿ� ���� ��ȯ�ϰ� pop_back���� �����ϴ� ����
	std::vector<int> Numbers = { 10,20,30,40,50 };
	int DeleteNumber = 20;

	std::vector<int>::iterator FindIter = std::find(Numbers.begin(), Numbers.end(), DeleteNumber);
	if (FindIter != Numbers.end())
	{
		// ã�Ҵ�.
		*FindIter = Numbers.back();	// ã�� ��ġ�� ������ ���� �־��.
		Numbers.pop_back();			// ������ ��� ����
	}
	else
	{
		// ����.
	}

	int i = 0;
}

void Day0923::TestVectorPractice()
{
	// std::vector �����ϱ�
	/*
		1. ���� �Է¹ް� ����ϱ�
		2. �ִ�, �ּ� ���ϱ�
		3. �����ϱ� (std::sort, #include <algorithm> �ʼ�)
		4. Ư�� �� ã�� (std::find����)
		5. �ߺ� �����ϱ�
		6. ���� �ΰ� ��ġ��
		7. ���ڿ� ����� ����ϱ�
		8. ��� ��� ���ϱ�
	*/

	// 1. ���� �Է¹ް� ����ϱ�(-1�� �Է¹��� ������ �ݺ��Է� �ޱ�)
	//constexpr int ExitNumber = -1;
	//std::vector<int> Numbers;
	//Numbers.reserve(10);
	//int InputNumber = 0;
	//while ( InputNumber != ExitNumber)
	//{
	//	printf("1. ���ڸ� �Է��ϼ���(-1�̸� ����) : ");
	//	std::cin >> InputNumber;
	//	if (InputNumber != ExitNumber)
	//	{
	//		Numbers.push_back(InputNumber);
	//	}
	//} 
	//printf("�Է� ���� ���� : ");
	//for (int Number : Numbers)
	//{
	//	printf("%d ", Number);
	//}
	//printf("\n\n");

	//// 2. �ִ�, �ּ� ���ϱ�
	//std::vector<int> Numbers2 = { 10, 20, 30, 40, 50 };
	//
	//int Min = INT_MAX;
	//int Max = INT_MIN;
	//for (int i = 0; i < Numbers2.size(); i++)
	//{
	//	if (Min > Numbers2[i])
	//	{
	//		Min = Numbers2[i];
	//	}
	//	if (Max < Numbers2[i])
	//	{
	//		Max = Numbers2[i];
	//	}
	//}
	//printf("Min = %d, Max = %d\n", Min, Max);

	//auto MinMax = std::minmax_element(Numbers2.begin(), Numbers2.end());
	////std::pair<std::vector<int>::iterator, std::vector<int>::iterator> MinMax = std::minmax_element(Numbers2.begin(), Numbers2.end());
	//Min = *(MinMax.first);
	//Max = *(MinMax.second);
	//printf("Min = %d, Max = %d\n", Min, Max);

	//// 3. �����ϱ� (std::sort, #include <algorithm> �ʼ�)
	//std::vector<int> Numbers3 = { 5,7,3,2,4 };
	//std::sort(Numbers3.begin(), Numbers3.end()); // �������� ����
	//printf("�������� ���� : ");
	//for (int n : Numbers3)
	//{
	//	printf("%d ", n);
	//}
	//printf("\n\n");

	////4. Ư�� �� ã�� (std::find����)
	//std::vector<int> Numbers4 = { 10, 20, 30, 40 ,50 };
	//int FindNumber = 300;
	//auto Iter = Numbers4.begin();
	//while (Iter != Numbers4.end())
	//{
	//	if (FindNumber == *Iter)
	//	{
	//		break;
	//	}
	//	Iter++;
	//}
	//if (Iter != Numbers4.end())
	//{
	//	// ã�Ҵ�.
	//	printf("%d�� ���� ���ο� �ֽ��ϴ�.\n", FindNumber);
	//}
	//else
	//{
	//	// ��ã�Ҵ�.
	//	printf("%d�� ���� ���ο� �����ϴ�.\n", FindNumber);
	//}

	//// 5. �ߺ� �����ϱ�
	//std::vector<int> Numbers5 = { 10, 20, 30, 30, 40, 50, 30, 40 };
	//std::vector<int> Result5;
	//Result5.reserve(Numbers5.size());
	//for (int n : Numbers5)
	//{
	//	auto iter = std::find(Result5.begin(), Result5.end(), n);
	//	if (iter == Result5.end())
	//	{
	//		Result5.push_back(n);
	//	}
	//}
	////Numbers5 = Result5;
	//printf("�ߺ����� ��� : ");
	//for (int n : Result5)
	//{
	//	printf("%d ", n);
	//}
	//printf("\n\n");
	//std::sort(Numbers5.begin(), Numbers5.end());	// unique�� �������ؼ��� ���ĵǾ� �־�� �Ѵ�.
	//auto last = std::unique(Numbers5.begin(), Numbers5.end());	// �ߺ��Ǵ� ������ �ڷ� ������ �ߺ��Ǳ� �� �������� ����
	//Numbers5.erase(last, Numbers5.end());	// �ߺ��Ǵ� �κе��� ������ ����
	//printf("�ߺ����� ��� : ");
	//for (int n : Numbers5)
	//{
	//	printf("%d ", n);
	//}
	//printf("\n\n");

	//// 6. ���� �ΰ� ��ġ��
	//std::vector<int> Numbers6_1 = { 10, 20, 30 };
	//std::vector<int> Numbers6_2 = { 100, 200, 300 };
	//std::vector<int> Result6(Numbers6_1);
	//for (int n : Numbers6_2)
	//{
	//	Result6.push_back(n);
	//}

	// 7. ���ڿ� ����� ����ϱ�
	printf("���ڿ��� �Է��ϼ��� : ");
	std::string InputWord;
	std::cin >> InputWord;
	std::vector<char> chars(InputWord.begin(), InputWord.end());
	printf("������ ��� : ");
	for (auto rIter = chars.rbegin(); rIter != chars.rend(); rIter++)
	{
		printf("%c", *rIter);
	}
	printf("\n\n");

	std::reverse(chars.begin(), chars.end());
	int i = 0;
}

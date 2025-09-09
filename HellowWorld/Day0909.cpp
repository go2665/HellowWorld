#include "Day0909.h"
#include <iostream>
#include <stdio.h>

void PointerParameter(int* pNumber)
{
	(*pNumber) = (*pNumber) * 2;	// �Է¹��� �ּҿ� �ִ� int���� 2��� �����
}

void TestPointer(int* pInt, float pFloat)
{
	(*pInt) += 3;
	//(pFloat) /= 2;
	(pFloat) *= 0.5f;	// *�� / �߿� ������ �� �� �ִ� ��Ȳ�̸� *�� ���ɻ� �����ϴ�.
}

void Day0909()
{
	// ���� �ǽ�
	// Number��� ������ �ϳ� �����ϰ� ������ ���� p�� Number�� �ּҸ� �����ϱ�
	// p�� �̿��ؼ� Number�� ���� �����Ű��

	float Number = 123.01f;
	int Number2 = 10;
	float* p = nullptr;	// p�� ������ ����ִ�.
	p = &Number;		// p�� Number�� �ּҸ� �����ߴ�.
	//p = &Number2;		// Ÿ���� �ٸ��� ������ �ȵȴ�.

	(*p) = 100.0f;

	PointerParameter(&Number2);

	// ���� �ǽ�
	// int*�� float*�� �Ķ���ͷ� ���� �Լ� �����
	// int*�� ���� ���� 3 ���ϱ�, float*�� ���� ���� �������� �����

	float* test = p;
	test++;

	//(*test) = 20;	// �ſ� ����. ���� �ϸ� �ȵ�. ������ ����.

	int i = 0;
}

void Day0909_ArrayAndPointer()
{
	// �迭�� ������(�⺻������ ����.)
	int Array[5] = { 10, 20, 30, 40, 50 };
	int* pArray = Array;	// �迭�� �̸��� �迭�� ù��° ����� �ּҿ� ����.
	int* pArray2 = &Array[0];	// Array == &Array[0] �ΰ��� ���� �ǹ�

	// pArray�� �̿��ؼ� Array[2]�� 300���� �����ϱ�
	*(pArray + 2) = 300;

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\n");

	for (int data : Array)		// range-for : Array���� ��ҵ��� ���������� �ϳ��� data�� �־� ó��
	{
		printf("%d ", data);
	}
	printf("\n");
		
}

void Day0909_DynamicAllocation()
{
	// C ��Ÿ�� �޸� �Ҵ� �� ����
	int Size = 5;
	int* Array = nullptr;
	Array = (int*)malloc(sizeof(int) * Size);	// int 5��¥�� �޸� �� �Ҵ� �ޱ�

	Array[2] = 20;
	/*
	�۾���
	*/

	free(Array);		// Array�� ����. malloc�� ������ ������ free���� ����� �۾��Ұ�
	Array = nullptr;	// ��۸� ������ ����

	// C++ ��Ÿ�� �޸� �Ҵ� �� ����
	int* Data = new int(5);		// int �ϳ��� �Ҵ� �޴µ� �ּҰ� ����Ű�� ���� 5�� �����ض�
	delete Data;
	Data = nullptr;
	Array = new int[10];	// int 10��¥�� �迭�� ������
	delete[] Array;				// �迭�� �ݵ�� �̷��� �����ؾ� �Ѵ�.
	//delete Array;				// ���� �̷��� �ϸ� �ȵȴ�. �̷��� �ϸ� Array[0]�κи� �Ҵ� ������ �ȴ�.
	Array = nullptr;

	// ���� �ǽ�
	// 1. int �迭 �Ҵ�ޱ�(ù �Ҵ��� 3����)
	// 2. ���ڸ� �Է¹��� ������ �迭�� �߰��ϱ�
}

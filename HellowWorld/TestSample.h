#pragma once
#include <stdio.h>

class Parent
{
public:
	Parent()
	{
		printf("부모 생성자\n");
	}
	virtual ~Parent()
	{
		printf("부모 소멸자\n");
	}
};

class Child : public Parent
{
public:
	Child()
	{
		Data = new int[100];
		printf("자식 생성자. 메모리 할당받음.\n");
	}
	virtual ~Child()
	{
		delete[] Data;
		Data = nullptr;
		printf("자식 소멸자. 메모리 해제.\n");
	}
private:
	int* Data = nullptr;
};
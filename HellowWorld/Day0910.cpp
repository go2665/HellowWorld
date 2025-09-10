#include "Day0910.h"
#include <iostream>
#include <stdio.h>

void Day0910_String()
{
	char HelloString[14];
	HelloString[0] = 'H';
	HelloString[1] = 'e';
	HelloString[2] = 'l';
	HelloString[3] = 'l';
	HelloString[4] = 'o';
	HelloString[5] = ' ';
	HelloString[6] = 'W';
	HelloString[7] = 'o';
	HelloString[8] = 'r';
	HelloString[9] = 'l';
	HelloString[10] = 'd';
	HelloString[11] = '!';
	HelloString[12] = '\n';
	HelloString[13] = '\0';
	//char HelloString[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\n' };
	//char HelloString[] = "Hello World!\n";

	printf("%s", HelloString);	// ���ڿ� ����ϱ�

	HelloString[5] = '\0';
	printf("%s", HelloString);	// Hello�� ��µ�

	// ���� �ǽ�
	// HelloString���� 'e'�� ���°�� �ִ��� ����غ���

	printf("\n\n\n\n\n\n\n\n\n\n\n");
	//int Index = 0;
	//char Target = 'e';
	//bool IsFind = false;
	//while (HelloString[Index] != '\0')
	//{
	//	if (HelloString[Index] == Target)
	//	{
	//		IsFind = true;
	//		break;
	//	}
	//	Index++;
	//}
	//if (IsFind)
	//{
	//	printf("[%c]�� %d�� �ε����� �ֽ��ϴ�.\n", Target, Index);
	//}
	//else
	//{
	//	printf("[%c]�� ã�� �� �����ϴ�.\n", Target);
	//}

	char Target = 'e';
	int Index = FindCharIndex(HelloString, Target);
	if (Index >= 0)
	{
		printf("[%c]�� %d�� �ε����� �ֽ��ϴ�.\n", Target, Index);
	}
	else
	{
		printf("[%c]�� ã�� �� �����ϴ�.\n", Target);
	}

	// �ǽ�
	// 1. ���ڿ��� ���̸� �����ϴ� �Լ� �����
	//		int MyStringLength(const char* Target);
	const char* TestString = "Hello";
	int Length = MyStringLength(TestString);
	printf("\n\n���ڿ� ���� ����\n");
	printf("[%s]�� ���̴� %d�Դϴ�.", TestString, Length);

	// 2. ���ڿ��� �����ϴ� �Լ� �����
	//		void MyStringCopy(const char* Source, char* Destination);
	char Destination[256] = {0};	// ũ��� �׳� ����ϴٰ� ����
	char* Destination2 = new char[MyStringLength(TestString) + 1];	// +1�� '\0'�� ����
	MyStringCopy(TestString, Destination2);
	printf("\n\n���ڿ� �����ϱ�\n");
	printf("Source\t\t: %s\n", TestString);
	printf("Destination\t: %s\n", Destination2);
	delete[] Destination2;
	Destination2 = nullptr;

	// 3. ���ڿ��� ��ġ�� �Լ� �����(Source �ڿ� Destination�� ������ ���̱�)
	//		void MyStringCat(char* Source, const char* Destination);
	printf("\n\n���ڿ� ��ġ��\n");
	char TestSource[32] = "Hello";
	printf("���� : %s\n", TestSource);
	MyStringCat(TestSource, " World!");
	printf("��� : %s\n", TestSource);
	
	// 4. ���ڿ� �ΰ��� ���ϴ� �Լ� �����
	//		���� ���� �� ���ڿ��� ������ 0, ù��°�� ������ ����, �ι�°�� ������ ���
	//		int MyStringCompare(const char* String1, const char* string2);
	// 5. ���ڿ��� �Է� �޾� ������ �����ϴ� �Լ� �����
	//		int MyAtoI(const char* Source);
	// 6. ���ڿ��� �Է� �޾� �Ǽ��� �����ϴ� �Լ� �����
	//		float MyAtoF(const char* Source);

	const int Size = 32;
	char InputString[Size];
	printf("\n\n������ �Է��ϼ��� : ");
	std::cin.getline(InputString, Size);
	printf("�Էµ� ������ [%s]�Դϴ�.", InputString);

	// ���� �ǽ�
	// ,�ڿ� �ִ� ���� ���ĺ��� ��� �빮���̾�� �Ѵ�.
	// �Է¹��� ���� : "Hello,World!"
	// ��¹��� ���� : "Hello,WORLD!"
	
}

int FindCharIndex(const char* TargetString, const char TargetCharacter)
{
	int Index = 0;
	bool IsFind = false;
	while (TargetString[Index] != '\0')
	{
		if (TargetString[Index] == TargetCharacter)
		{
			IsFind = true;
			break;
		}
		Index++;
	}

	if (!IsFind)
	{
		Index = -1;
	}
	return Index;
}

int MyStringLength(const char* Target)
{
	int Length = 0;
	while (Target[Length] != '\0')
	{
		Length++;
	}
	return Length;
}

void MyStringCopy(const char* Source, char* Destination)
{
	int Index = 0;
	while (Source[Index] != '\0')
	{
		Destination[Index] = Source[Index];
		Index++;
	}
	Destination[Index] = '\0';
}

void MyStringCat(char* Source, const char* Destination)
{
	int SourceLast = MyStringLength(Source);
	int Index = 0;
	while (Destination[Index] != '\0')
	{
		Source[SourceLast + Index] = Destination[Index];
		Index++;
	}
	Source[SourceLast + Index] = '\0';
}


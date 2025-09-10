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

	printf("%s", HelloString);	// 문자열 출력하기

	HelloString[5] = '\0';
	printf("%s", HelloString);	// Hello만 출력됨

	// 간단 실습
	// HelloString에서 'e'가 몇번째에 있는지 출력해보기

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
	//	printf("[%c]는 %d번 인덱스에 있습니다.\n", Target, Index);
	//}
	//else
	//{
	//	printf("[%c]는 찾을 수 없습니다.\n", Target);
	//}

	char Target = 'e';
	int Index = FindCharIndex(HelloString, Target);
	if (Index >= 0)
	{
		printf("[%c]는 %d번 인덱스에 있습니다.\n", Target, Index);
	}
	else
	{
		printf("[%c]는 찾을 수 없습니다.\n", Target);
	}

	// 실습
	// 1. 문자열의 길이를 측정하는 함수 만들기
	//		int MyStringLength(const char* Target);
	const char* TestString = "Hello";
	int Length = MyStringLength(TestString);
	printf("\n\n문자열 길이 측정\n");
	printf("[%s]의 길이는 %d입니다.", TestString, Length);

	// 2. 문자열을 복사하는 함수 만들기
	//		void MyStringCopy(const char* Source, char* Destination);
	char Destination[256] = {0};	// 크기는 그냥 충분하다고 가정
	char* Destination2 = new char[MyStringLength(TestString) + 1];	// +1은 '\0'용 공간
	MyStringCopy(TestString, Destination2);
	printf("\n\n문자열 복사하기\n");
	printf("Source\t\t: %s\n", TestString);
	printf("Destination\t: %s\n", Destination2);
	delete[] Destination2;
	Destination2 = nullptr;

	// 3. 문자열을 합치는 함수 만들기(Source 뒤에 Destination의 내용을 붙이기)
	//		void MyStringCat(char* Source, const char* Destination);
	printf("\n\n문자열 합치기\n");
	char TestSource[32] = "Hello";
	printf("원본 : %s\n", TestSource);
	MyStringCat(TestSource, " World!");
	printf("결과 : %s\n", TestSource);
	
	// 4. 문자열 두개를 비교하는 함수 만들기
	//		리턴 값이 두 문자열이 같으면 0, 첫번째가 작으면 음수, 두번째가 작으면 양수
	//		int MyStringCompare(const char* String1, const char* string2);
	// 5. 문자열을 입력 받아 정수를 리턴하는 함수 만들기
	//		int MyAtoI(const char* Source);
	// 6. 문자열을 입력 받아 실수를 리턴하는 함수 만들기
	//		float MyAtoF(const char* Source);

	const int Size = 32;
	char InputString[Size];
	printf("\n\n문장을 입력하세요 : ");
	std::cin.getline(InputString, Size);
	printf("입력된 문장은 [%s]입니다.", InputString);

	// 간단 실습
	// ,뒤에 있는 영어 알파벳은 모두 대문자이어야 한다.
	// 입력문장 예시 : "Hello,World!"
	// 출력문장 예시 : "Hello,WORLD!"
	
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


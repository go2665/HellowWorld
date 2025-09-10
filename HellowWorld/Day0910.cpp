#include "Day0910.h"
#include <iostream>
#include <stdio.h>
#include <direct.h>
#include <fstream>
#include <string>

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
	printf("입력된 문장은 [%s]입니다.\n", InputString);

	// 간단 실습
	// ,뒤에 있는 영어 알파벳은 모두 대문자이어야 한다.
	// 입력문장 예시 : "Hello,World!"
	// 출력문장 예시 : "Hello,WORLD!"
	SimpleParser(InputString, ',');
	printf("파싱된 문장은 [%s]입니다.\n", InputString);

	// #include <direct.h> 추가
	char Working[256];
	if (_getcwd(Working, 256) != nullptr)
	{
		printf("작업 디렉토리 : %s\n", Working);
	}

	// 파일 읽기
	ReadFile();
	
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

void SimpleParser(char* Source, const char Delimiter)
{
	int CommaIndex = FindCharIndex(Source, Delimiter);
	char* AfterComma = Source + CommaIndex + 1;
	const int ToUpperGap = 'a' - 'A';
	while ((*AfterComma) != '\0')
	{
		if ((*AfterComma) >= 'a' && (*AfterComma) <= 'z')
		{
			(*AfterComma) -= ToUpperGap;
		}
		AfterComma++;
	}
}

void ReadFile()
{
	//#include <fstream>	#include <string> 필요
	const char* FilePath = ".\\Data\\TestData.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// 파일이 열렸는지 확인하는 함수
	{
		printf("파일을 열 수 없습니다.\n");
		printf("[%s] 경로를 확인하세요.\n", FilePath);
		return;
	}

	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile에 있는 글자들을 모두 읽어서 FileContents에 저장하기

	printf("파일 내용은 다음과 같습니다.\n");
	printf("%s\n", FileContents.c_str());	// FileContents안에 있는 문자열을 const char*로 돌려주는 함수
}

void TestString()
{
	//#include <string>
	std::string str1 = "Hello";
	std::string str2("World");	// str1보다 이쪽이 더 바람직하다

	const char* Temp1 = "Hello";
	char Temp2[32] = { 0 };
	//Temp2 = Temp1;
	//char* Temp3 = Temp1;

	std::string str3 = str1;		// 복사
	size_t Length = str3.length();	// 길이 확인
	//int Size = Length;	// 크기가 안맞아서 짤릴 수 있다.
	Length = str3.size();

	std::string str4 = str1 + " " + str2;	// str4 = "Hello World", + 방식은 성능에 문제가 있을 수 있다.
	str4 += "!";

	if (str1 == str2)
	{

	}
	if (str1 != str2)
	{

	}
	if (str1 > str2)	// 사전 순서대로 비교
	{

	}

	size_t Position = str1.find('e');
	// 발견을 못했으면 std::string::npos 리턴
	Position = str1.find('e', Position+1);	// 두번째 e를 찾을 때(첫번째 e가 발견되었다는 전제하에)

	str1[1] = 'E';	// 특정 위치의 글자에 접근하기. 인덱스 범위 확인을 안함. 런타임 에러가 뜰 수 있음
	//str1[10] = 'E';	// 터짐
	str1.at(1) = 'E';	// 안전하게 접근

	str1.c_str();	// C스타일 문자열 접근하기
}


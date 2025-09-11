#include <fstream>
#include <stdio.h>
#include <string>
#include "Day0909.h"
#include "Day0910.h"
#include "Day0911.h"

bool ReadMapFile(const char* MapFileName, std::string& OutDataString)
{
	//const char* FilePath = ".\\Data\\TestData.txt";
	char FilePath[256];
	//MyStringCopy(DirectoryName, FilePath);
	//MyStringCat(FilePath, MapFileName);
	strcpy(FilePath, DirectoryName);
	strcat(FilePath, MapFileName);

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	// 파일이 열렸는지 확인하는 함수
	{
		printf("파일을 열 수 없습니다.\n");
		printf("[%s] 경로를 확인하세요.\n", FilePath);
		return false;
	}

	std::string DataString(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile에 있는 글자들을 모두 읽어서 FileContents에 저장하기

	//printf("파일 내용은 다음과 같습니다.\n");
	//printf("%s\n", FileContents.c_str());	// FileContents안에 있는 문자열을 const char*로 돌려주는 함수	

	return true;
}

bool ParseMapData(std::string& DataString)
{
	char Source[512];
	strcpy(Source, DataString.c_str());

	// 라인 분리하기
	char Line[128];
	char* Current = GetNextLine(Source);
	strcpy(Line, Source);

	char* LinePointer = Line;
	int SizeNumbers[2] = { 0 };
	int SizeIndex = 0;
	while ((*LinePointer) == '\0')
	{
		int Result = 0;
		while ((*LinePointer) != ',')
		{
			Result = Result * 10 + (*LinePointer) - '0';
			LinePointer++;
		}
		// Result = 숫자로 완성
		SizeNumbers[SizeIndex] = Result;
		SizeIndex++;

		if (*LinePointer == ',')
			LinePointer++;
	}

	printf("Size : %d, %d\n", SizeNumbers[0], SizeNumbers[1]);

	return false;
}

char* GetNextLine(char* Source)
{
	int Index = FindCharIndex(Source, '\n');
	if (Index == -1)
	{
		return Source + FindCharIndex(Source, '\0');	// 마지막 줄 처리
	}
	*(Source + Index) = '\0';
	return Source + Index + 1;
	//return strtok(Source, "\n") + 1;
}

void Day0911()
{
	std::string Data;
	ReadMapFile("MapData.txt", Data);

	ParseMapData(Data);
}

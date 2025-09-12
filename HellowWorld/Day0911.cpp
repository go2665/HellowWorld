#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <stdio.h>
#include <string>
#include "Day0909.h"
#include "Day0910.h"
#include "Day0911.h"

const char* DirectoryName = ".\\Data\\";

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

	OutDataString = std::string((std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>()); // InputFile에 있는 글자들을 모두 읽어서 OutDataString에 저장하기

	//printf("파일 내용은 다음과 같습니다.\n");
	//printf("%s\n", FileContents.c_str());	// FileContents안에 있는 문자열을 const char*로 돌려주는 함수	

	return true;
}

bool ParseMapData(std::string& DataString)
{
	char Source[512];
	char* Current = Source;
	strcpy(Source, DataString.c_str());

	// 첫째 줄 처리
	// 라인 분리하기
	char* LinePtr = GetLine(&Current);

	// 라인 파싱하기
	int SizeNumbers[2] = { 0 };
	ParseLineData(LinePtr, 2, SizeNumbers);
	
	//printf("ArraySize : %d, %d\n", SizeNumbers[0], SizeNumbers[1]);

	// 맵의 크기를 알았다. => Maze 생성
	MazeWidth = SizeNumbers[0];
	MazeHeight = SizeNumbers[1];

	Maze = new int* [MazeHeight];
	for (int y = 0; y < MazeHeight; y++)
	{
		Maze[y] = new int[MazeWidth];
		//memset(&Maze[y], 0, sizeof(int) * MazeWidth);
	}

	int HeightIndex = 0;
	while ((*Current) != '\0')	// Current가 \0이 될 때까지 반복
	{
		LinePtr = GetLine(&Current);	// 한줄 잘라내고
		ParseLineData(LinePtr, MazeWidth, Maze[HeightIndex]);	// 파싱해서 데이터 넣고	
		HeightIndex++;

		if (HeightIndex >= MazeHeight)	// 크기을 벗어나지 못하게 체크
			break;
	}

	return true;
}

char* GetLine(char** InOutSource)
{
	char* Result = (*InOutSource);
	int Index = FindCharIndex((*InOutSource), '\n');
	if (Index == -1)
	{
		(*InOutSource) = (*InOutSource) + FindCharIndex((*InOutSource), '\0');
	}
	else
	{
		*((*InOutSource) + Index) = '\0';
		(*InOutSource) = (*InOutSource) + Index + 1;
	}

	return Result;
}

void ParseLineData(const char* LineData, int ArraySize, int* OutArray)
{
	const char* LinePointer = LineData;
	int SizeIndex = 0;
	while ((*LinePointer) != '\0')
	{
		int Result = 0;
		while ((*LinePointer) != ',' && (*LinePointer) != '\0')
		{
			Result = Result * 10 + (*LinePointer) - '0';	// 숫자 만들기
			LinePointer++;
		}
		OutArray[SizeIndex] = Result;	// 숫자 결과 저장
		SizeIndex++;

		if (ArraySize <= SizeIndex)	// 배열 크기 이상으로 넣는 것을 방지
			break;

		if (*LinePointer < '0' || *LinePointer > '9')	// 숫자 외에는 스킵
			LinePointer++;
	}
}

void InitializeMaze()
{
	std::string Data;
	ReadMapFile("MapData.txt", Data);	// 파일 읽기

	ParseMapData(Data);	// 읽은 데이터로 맵 정보 구성하기
}

void ClearMaze()
{
	if (Maze != nullptr)
	{
		for (int i = 0; i < MazeHeight; i++)
		{
			delete[] Maze[i];
			Maze[i] = nullptr;
		}
		delete[] Maze;
		Maze = nullptr;
	}
}

void Day0911()
{
	InitializeMaze();

	MazeEscapeRun();

	ClearMaze();
}

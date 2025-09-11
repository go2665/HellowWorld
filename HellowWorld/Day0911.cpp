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
	if (!InputFile.is_open())	// ������ ���ȴ��� Ȯ���ϴ� �Լ�
	{
		printf("������ �� �� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���.\n", FilePath);
		return false;
	}

	std::string DataString(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	//InputFile�� �ִ� ���ڵ��� ��� �о FileContents�� �����ϱ�

	//printf("���� ������ ������ �����ϴ�.\n");
	//printf("%s\n", FileContents.c_str());	// FileContents�ȿ� �ִ� ���ڿ��� const char*�� �����ִ� �Լ�	

	return true;
}

bool ParseMapData(std::string& DataString)
{
	char Source[512];
	strcpy(Source, DataString.c_str());

	// ���� �и��ϱ�
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
		// Result = ���ڷ� �ϼ�
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
		return Source + FindCharIndex(Source, '\0');	// ������ �� ó��
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

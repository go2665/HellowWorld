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

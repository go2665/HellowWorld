#include <stdio.h>
#include <iostream>
#include "Day0915.h"
#include "DayOfWeek.h"

void Day0915_WeekPractice()
{
	int Year = 0;
	int Month = 0;
	int Day = 0;
	printf("��¥�� �Է� �ϼ���(��: 2025 9 15) : ");
	std::cin >> Year >> Month >> Day;
	printf("�ش� ��¥�� [%s]�Դϴ�.\n", GetDayOfWeek(Year, Month, Day));	
}
#include <stdio.h>
#include <iostream>
#include "Day0915.h"
#include "DayOfWeek.h"

void Day0915_WeekPractice()
{
	int Year = 0;
	int Month = 0;
	int Day = 0;
	printf("날짜를 입력 하세요(예: 2025 9 15) : ");
	std::cin >> Year >> Month >> Day;
	printf("해당 날짜는 [%s]입니다.\n", GetDayOfWeek(Year, Month, Day));	
}
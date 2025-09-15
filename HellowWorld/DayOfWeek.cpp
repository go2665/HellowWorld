#include "DayOfWeek.h"

// 각 월별 날짜
const int DaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

// 요일
const char* Week[7] = { "월요일", "화요일", "수요일", "목요일", "금요일", "토요일", "일요일" };

const char* GetDayOfWeek(int Year, int Month, int Day)
{
	int Days = GetTotalDays(Year, Month, Day);
	return Week[Days % 7];
}

bool IsLeap(int Year)
{
	// 4의 배수는 윤년이다. 그리고 100의 배수는 윤년이 아니다.
	// 그런데 400의 배수는 윤년이다.
	// (Year % 4 == 0) : 4의 배수이다. -> 윤년이다.
	// (Year % 100 != 0) : 100의 배수가 아니다 -> 윤년이다.
	// (Year % 400 == 0) : 400의 배수이다 -> 윤년이다.

	// 4의 배수이고 100의 배수가 아니거나, 400의 배수면 윤년이다.
	return ((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0);
}

int GetTotalDays(int Year, int Month, int Day)
{
	int Days = 0;
	for (int Y = 1; Y < Year; Y++)
	{
		Days += (IsLeap(Y) ? 366 : 365);	// 윤년이면 366일 추가, 아니면 365일 추가
	}
	for (int M = 1; M < Month; M++)
	{
		Days += DaysInMonth[M - 1];
		if (M == 2 && IsLeap(Year))
		{
			Days += 1;	// 윤년이면 2월일 때 하루 추가
		}
	}
	Day += (Day - 1);

	return Days;
}

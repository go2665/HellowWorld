#include "FixedStack.h"
#include <stdio.h>

void FixedStack::Push(int InValue)
{
	if (IsFull())
	{
		printf("오류: 스택이 가득 찼습니다! (Stack Overflow)\n");
		return;
	}
	TopIndex++;					// Top위치를 증가 시키고
	Data[TopIndex] = InValue;	// 그 위치에 값을 넣기
}

int FixedStack::Pop()
{
	if (IsEmpty())
	{
		printf("오류: 스택이 비어있습니다! (Stack Underflow)\n");
		return;
	}
	int Result = Data[TopIndex];
	TopIndex--;
	return Result;
}

int FixedStack::Top() const
{
	if (IsEmpty)
	{
		printf("오류: 스택이 비어있습니다! 값을 반환할 수 없습니다.\n");
		return Empty;	// 실제 값이 아니라 오류값으로 우리가 설정한 값을 리턴하는 것
	}

	return Data[TopIndex];
}
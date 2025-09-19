#pragma once
#include <stdio.h>

// 서큘러 큐. 크기 고정. 데이터는 int
class CircularQueue
{
public:
	// 큐에 데이터 하나 추가
	void Enqueue(int InValue);
	// 큐에서 데이터 하나 제거
	int Dequeue();

	// 순수하게 테스트용. 큐 내부를 모두 출력
	void TestPrintQueue();

	// 큐가 가득 찼는지 확인하는 함수
	inline bool IsFull() const
	{
		// Rear가 하나 더 증가했을 때 Front를 침범하냐 마냐로 가득참을 체크
		return (Rear + 1) % MaxSize == Front;	
	}
	// 큐가 비었는지 확인하는 함수
	inline bool IsEmpty() const
	{
		return Front == Empty;	// Front가 배열내 아무곳도 가리키지 않으면 비었다고 판단
	}
	// 큐의 Front에 있는 값을 확인하는 함수
	inline int Peek() const
	{
		if (IsEmpty())
		{
			printf("오류: 큐가 비어있습니다.\n");
			return Empty;
		}
		return Data[Front];
	}
	// 큐의 길이를 출력하는 함수
	inline int GetSize() const
	{
		return ((Rear + MaxSize) - Front) % MaxSize + 1;
	}

private:
	static constexpr int Empty = -1;
	static constexpr unsigned int MaxSize = 10;

	int Front = Empty;
	int Rear = Empty;
	int Data[MaxSize];
};


#pragma once
#include <stdio.h>

// 서큘러 큐. 크기 고정. 데이터는 int
class CircularQueue2
{
public:
	CircularQueue2(unsigned int InSize = 5)
		: MaxSize(InSize == 0 ? MinSize : InSize)
	{ 
		if (InSize == 0)
		{
			printf("요청한 크기 0은 유효하지 않으므로 최소크기인 %u로 설정했습니다.", MinSize);
		}
		Data = new int[MaxSize];
	}
	~CircularQueue2()
	{
		if (Data != nullptr)
		{
			delete[] Data;
			Data = nullptr;
		}
	}

	// 복사 방지
	CircularQueue2(const CircularQueue2&) = delete;	// 복사 생성자는 없음
	CircularQueue2& operator=(const CircularQueue2&) = delete;	// 대입 연산자가 없음

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
	static constexpr unsigned int MinSize = 1;
	
	unsigned int MaxSize = 1;

	int Front = Empty;
	int Rear = Empty;
	int* Data = nullptr;
};


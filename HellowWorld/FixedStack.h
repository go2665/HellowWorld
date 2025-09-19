#pragma once
// 데이터는 int로 가정. 크기가 정해진 스택.
class FixedStack
{
public:
	// 스택에 InValue를 추가하는 함수
	void Push(int InValue);

	// 스택의 Top 위치에 있는 값을 꺼내는 함수
	int Pop();

	// Top에 있는 값을 확인한 하는 함수. 꺼내지는 않는다.(Peek이라고도 함)
	int Top() const;

	// 스택이 가득 찼는지 확인하는 함수. Stack Overflow 방지를 위해 사용.
	inline bool IsFull() const
	{
		return TopIndex == (StackCapacity - 1);
	}

	// 스택이 비어있는지 확인하는 함수. Stack Underflow 방지를 위해 사용.
	inline bool IsEmpty() const
	{
		return TopIndex == Empty;
	}

	// 스택의 현재 크기를 반환하는 함수.(실제 들어와 있는 데이터 개수)
	inline int GetSize() const
	{
		return TopIndex + 1;
	}

private:
	// 스택의 전체 크기
	static constexpr int StackCapacity = 10;

	// 스택이 비었음을 표시하기 위한 인덱스용 상수
	static constexpr int Empty = -1;

	// 현재 Top의 위치. Empty면 비어있다.
	int TopIndex = Empty;

	// 스택의 데이터를 저장하는 배열
	int Data[StackCapacity];
};


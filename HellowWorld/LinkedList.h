#pragma once
#include <cstdint>

using int32 = int32_t;
using uint32 = uint32_t;

struct ListNode
{
	int32 Data = 0;				// 일단 데이터는 int32로 확정
	ListNode* Next = nullptr;	// 다음 노드의 주소(nullptr이면 다음 노드가 없다)

	ListNode(int32 InData) : Data(InData) {};
};

class LinkedList
{
public:
	LinkedList() = default;
	
	// 만들어진 노드들을 정리하기 위해 필요
	~LinkedList();	

	// 데이터를 리스트에 하나 추가하는 함수(리스트의 마지막에 추가)
	void Add(int32 InData);

	// 데이터를 특정 위치에 추가하는 함수(범위를 벗어나면 마지막에 추가)
	void InsertAt(int32 InData, uint32 InPosition);

	// 데이터를 삭제하는 함수(InData와 같은 값을 가지는 노드를 삭제하는 함수. 중복 없음.)
	void Remove(int32 InData);

	// 데이터를 삭제하는 함수(InPosition번째의 데이터를 삭제하는 함수. 범위 벗어나면 에러만 출력.)
	void RemoveAt(uint32 InPosition);

	// InData를 가진 노드를 찾아 리턴하는 함수(없으면 nullptr 리턴)
	ListNode* Search(int32 InData) const;

	// 리스트 내용을 출력하는 함수
	void PrintList() const;


private:
	inline bool IsEmpty() const { return Head == nullptr; }

	// 리스트의 첫번째 노드
	ListNode* Head = nullptr;

	// 리스트의 마지막 노드
	ListNode* Tail = nullptr;

	// 리스트에 있는 노드의 수
	uint32 Size = 0;
};


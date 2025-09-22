#include "Day0919.h"
#include "FixedStack.h"
#include "CircularQueue.h"
#include "CircularQueue2.h"

void Day0919::TestStack()
{
	FixedStack Stack;

	// 1.초기 상태 테스트
	//	스택이 비었는지 확인해보기(IsEmpty와 GetSize 사용하고 printf로 출력하기)
	// 2. Push 테스트
	//	데이터(10) 넣고 Top 위치에 있는 값과 스택 크기 출력해보기
	//	데이터(20) 넣고 Top 위치에 있는 값과 스택 크기 출력해보기
	//	데이터(30) 넣고 Top 위치에 있는 값과 스택 크기 출력해보기
	// 3. Pop 테스트
	//	데이터 하나 빼고 뺀 값 출력해보기, 스탟의 남은 Top 위치값과 스택 크기 출력해보기
	// 4. 스택 오버플로우 테스트
	//	스택 가득 채우고 한번 더 넣어 보기
	// 5. 스택 언더플로우 테스트
	//	스택 다 비우고 한번 더 빼보기
}

void Day0919::TestQueue()
{	
	// 1.테스트용 메뉴 만들기
	//		1. Enqueue
	//		2. Dequeue
	//		3. Peek	
	//		4. TestPrintQueue
	//		5. 종료
	// 2. Circular Queue2 만들기
	//		생성자에서 파라메터를 받아 크기를 조절 가능하게 만들기

	CircularQueue queue;
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(40);
	queue.Enqueue(50);
	queue.Enqueue(60);
	queue.Enqueue(70);
	queue.Enqueue(80);
	queue.Enqueue(90);
	queue.Enqueue(100);

	queue.Dequeue();
	queue.Dequeue();
	queue.Dequeue();
	queue.Dequeue();

	queue.Enqueue(110);
	queue.Enqueue(120);

}

void Day0919::TestQueue2()
{
	CircularQueue2 queue;
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(40);
	queue.Enqueue(50);
	queue.Enqueue(60);
	queue.Enqueue(70);
	queue.Enqueue(80);
	queue.Enqueue(90);
	queue.Enqueue(100);

	queue.Dequeue();
	queue.Dequeue();
	queue.Dequeue();
	queue.Dequeue();

	queue.Enqueue(110);
	queue.Enqueue(120);
}

void Day0919::TestSwallowCopy()
{
	// 얕은 복사 : 복사를 할 때 완전한 사본을 만드는 것이 아니라 주소만 복사하는 복사
	CircularQueue2 a(5);
	a.Enqueue(10);
	a.Enqueue(20);

	//CircularQueue2 b(a);	// 복사 생성자로 a의 사본을 만든 것
	//CircularQueue2 c = a;	// 대입 연산자로 a의 사본을 만든 것

	//a.Enqueue(30);

	//printf("a\n");
	//a.TestPrintQueue();
	//printf("\nb\n");
	//b.TestPrintQueue();
	//printf("\nc\n");
	//c.TestPrintQueue();

	//TestSwallowCopy(a);
	TestSwallowCopy(a);		// 참조 넘기기
	TestSwallowCopy(&a);	// 주소 넘기기
}

void Day0919::TestSwallowCopy(CircularQueue2* temp)
{
	temp->TestPrintQueue();
}

void Day0919::TestSwallowCopy(CircularQueue2& temp)
{
	temp.TestPrintQueue();
}


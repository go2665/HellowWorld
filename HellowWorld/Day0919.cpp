#include "Day0919.h"
#include "FixedStack.h"
#include "CircularQueue.h"
#include "CircularQueue2.h"

void Day0919::TestStack()
{
	FixedStack Stack;

	// 1.�ʱ� ���� �׽�Ʈ
	//	������ ������� Ȯ���غ���(IsEmpty�� GetSize ����ϰ� printf�� ����ϱ�)
	// 2. Push �׽�Ʈ
	//	������(10) �ְ� Top ��ġ�� �ִ� ���� ���� ũ�� ����غ���
	//	������(20) �ְ� Top ��ġ�� �ִ� ���� ���� ũ�� ����غ���
	//	������(30) �ְ� Top ��ġ�� �ִ� ���� ���� ũ�� ����غ���
	// 3. Pop �׽�Ʈ
	//	������ �ϳ� ���� �� �� ����غ���, ������ ���� Top ��ġ���� ���� ũ�� ����غ���
	// 4. ���� �����÷ο� �׽�Ʈ
	//	���� ���� ä��� �ѹ� �� �־� ����
	// 5. ���� ����÷ο� �׽�Ʈ
	//	���� �� ���� �ѹ� �� ������
}

void Day0919::TestQueue()
{	
	// 1.�׽�Ʈ�� �޴� �����
	//		1. Enqueue
	//		2. Dequeue
	//		3. Peek	
	//		4. TestPrintQueue
	//		5. ����
	// 2. Circular Queue2 �����
	//		�����ڿ��� �Ķ���͸� �޾� ũ�⸦ ���� �����ϰ� �����

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
	// ���� ���� : ���縦 �� �� ������ �纻�� ����� ���� �ƴ϶� �ּҸ� �����ϴ� ����
	CircularQueue2 a(5);
	a.Enqueue(10);
	a.Enqueue(20);

	//CircularQueue2 b(a);	// ���� �����ڷ� a�� �纻�� ���� ��
	//CircularQueue2 c = a;	// ���� �����ڷ� a�� �纻�� ���� ��

	//a.Enqueue(30);

	//printf("a\n");
	//a.TestPrintQueue();
	//printf("\nb\n");
	//b.TestPrintQueue();
	//printf("\nc\n");
	//c.TestPrintQueue();

	//TestSwallowCopy(a);
	TestSwallowCopy(a);		// ���� �ѱ��
	TestSwallowCopy(&a);	// �ּ� �ѱ��
}

void Day0919::TestSwallowCopy(CircularQueue2* temp)
{
	temp->TestPrintQueue();
}

void Day0919::TestSwallowCopy(CircularQueue2& temp)
{
	temp.TestPrintQueue();
}


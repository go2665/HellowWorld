#include "Day0918.h"
#include "LinkedList.h"

void Day0918::TestSingleLinkedList()
{
	LinkedList MyList;

	// Add Å×½ºÆ®
	MyList.Add(10);
	MyList.Add(20);
	MyList.Add(30);
	MyList.PrintList();

	// InsertAt test
	MyList.InsertAt(40, 100);
	MyList.PrintList();
	MyList.InsertAt(5, 0);
	MyList.PrintList();
	MyList.InsertAt(15, 2);
	MyList.PrintList();

	// Remove test
	MyList.Remove(20);
	MyList.PrintList();
	MyList.Remove(123);
	MyList.PrintList();

	// RemoveAt test
	MyList.RemoveAt(10);
	MyList.PrintList();
	MyList.Remove(1);
	MyList.PrintList();

	// Search test
	ListNode* Found = MyList.Search(15);
	if (Found)
	{
	}
	else
	{
	}
	Found = MyList.Search(999);
	if (Found)
	{
	}
	else
	{
	}

}

#include "Day0908.h"

void Day0908()
{
	int a = 10;
	int Array[5];	// int 5���� �����ϴ� �迭
	Array[0] = 10;	// �迭�� ù��° ��ҿ� 10�� �����Ѵ�.
	Array[3] = 40;	// �迭�� �׹�° ��ҿ� 40�� �����Ѵ�.

	int Array2[5] = { 1,2,3,4,5 };
	int Array3[5] = { 1,2,3 };
	int Array4[5] = { 0 };

	const int Size = 5;
	int Array5[Size] = {};
	//sizeof(Array5);	// Array5�� ��ü ����Ʈ ũ�⸦ �� �� �ִ�.
	//sizeof(Array5[0]);	// Array5�� ��� �ϳ��� ũ�⸦ �� �� �ִ�.
	int ElementCount = sizeof(Array5) / sizeof(Array5[0]);	// Array5�� ��� ����

	//int Size2 = 5;
	//int Array6[Size2] = {};	// �迭 ������ �� ũ�⸦ ������ ������ ���� ����.

	// Array[5] = 60;	// ���ۿ�����. �迭 ���� ���� �����Ϸ��� �ϱ� ������ ������ �߻��Ѵ�.
}

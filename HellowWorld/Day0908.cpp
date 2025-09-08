#include "Day0908.h"

void Day0908()
{
	int a = 10;
	int Array[5];	// int 5개를 관리하는 배열
	Array[0] = 10;	// 배열의 첫번째 요소에 10을 대입한다.
	Array[3] = 40;	// 배열의 네번째 요소에 40을 대입한다.

	int Array2[5] = { 1,2,3,4,5 };
	int Array3[5] = { 1,2,3 };
	int Array4[5] = { 0 };

	const int Size = 5;
	int Array5[Size] = {};
	//sizeof(Array5);	// Array5의 전체 바이트 크기를 알 수 있다.
	//sizeof(Array5[0]);	// Array5의 요소 하나의 크기를 알 수 있다.
	int ElementCount = sizeof(Array5) / sizeof(Array5[0]);	// Array5의 요소 개수

	//int Size2 = 5;
	//int Array6[Size2] = {};	// 배열 선언할 때 크기를 변수로 지정할 수는 없다.

	// Array[5] = 60;	// 버퍼오버런. 배열 영역 밖을 접근하려고 하기 때문에 에러가 발생한다.
}

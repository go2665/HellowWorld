#include "Day0917.h"
#include "Tiger.h"
#include "Hawk.h"
#include "Dog.h"
#include "TestSample.h"

void Day0917::TestPolymorphism()
{
	Tiger* pTiger = new Tiger("호식이");
	Hawk* pHawk = new Hawk("매형");

	printf("호식이 이동\n");
	pTiger->Move();
	printf("매형 이동\n");
	pHawk->Move();

	printf("동물 이동\n");
	Animal* pAnimal = pHawk;
	pAnimal->Move();	// Animal의 Move가 실행됨 -> 가상함수가 된 후에는 원래 클래스의 Move가 실행된다.
	pAnimal = pTiger;
	pAnimal->Move();

	// C 스타일 캐스팅(위험)
	//Tiger* pTempTiger = (Tiger*)pAnimal;
	//pTempTiger->Hunt();
	//((Tiger*)pAnimal)->Hunt();

	// C++ 스타일 캐스팅 중 하나
	// dynamic_cast : 런타임(실행중)에 이 주소가 실제 어떤 자식 클래스의 객체를 가리키고 있는지 안전하게 확인해주는 cast

	Tiger* pTempTiger = dynamic_cast<Tiger*>(pAnimal);
	if (pTempTiger == nullptr)
	{
		// pAnimal은 Tiger*가 아니다.
	}
	else
	{
		// pAnimal에 저장된 주소는 Tiger의 주소가 맞다.
		pTempTiger->Hunt();
	}

	// pAnimal->Hunt(); // 사용 불가능

	delete pTiger;
	pTiger = nullptr;

	delete pHawk;
	pHawk = nullptr;
}

void Day0917::TestVirtualFunction()
{
	Parent* pParent = new Child();	// 가능
	delete pParent;
	pParent = nullptr;
}

void Day0917::TestPractice1()
{
	// 간단 실습
	// Animal*의 배열 만들기
	// 여러 종류의 동물을 넣기
	// 배열에 들어있는 모든 동물의 MakeSound 실행하기

	const int Size = 5;
	Animal* Zoo[Size];
	Zoo[0] = new Tiger("호식이");
	Zoo[1] = new Tiger("호돌이");
	Zoo[2] = new Hawk("매형");
	Zoo[3] = new Hawk("매동생");
	Zoo[4] = new Dog("멍멍이");

	for (int i = 0; i < Size; i++)
	{
		Zoo[i]->MakeSound();
	}

	for (int i = 0; i < Size; i++)
	{
		delete Zoo[i];
		Zoo[i] = nullptr;
	}


}



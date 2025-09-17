#include "Day0917.h"
#include "Tiger.h"
#include "Hawk.h"
#include "Dog.h"
#include "Shape.h"
#include "TestSample.h"
#include <stdint.h>

void Day0917::TestPolymorphism()
{
	Tiger* pTiger = new Tiger("ȣ����");
	Hawk* pHawk = new Hawk("����");

	printf("ȣ���� �̵�\n");
	pTiger->Move();
	printf("���� �̵�\n");
	pHawk->Move();

	printf("���� �̵�\n");
	Animal* pAnimal = pHawk;
	pAnimal->Move();	// Animal�� Move�� ����� -> �����Լ��� �� �Ŀ��� ���� Ŭ������ Move�� ����ȴ�.
	pAnimal = pTiger;
	pAnimal->Move();

	// C ��Ÿ�� ĳ����(����)
	//Tiger* pTempTiger = (Tiger*)pAnimal;
	//pTempTiger->Hunt();
	//((Tiger*)pAnimal)->Hunt();

	// C++ ��Ÿ�� ĳ���� �� �ϳ�
	// dynamic_cast : ��Ÿ��(������)�� �� �ּҰ� ���� � �ڽ� Ŭ������ ��ü�� ����Ű�� �ִ��� �����ϰ� Ȯ�����ִ� cast

	Tiger* pTempTiger = dynamic_cast<Tiger*>(pAnimal);
	if (pTempTiger == nullptr)
	{
		// pAnimal�� Tiger*�� �ƴϴ�.
	}
	else
	{
		// pAnimal�� ����� �ּҴ� Tiger�� �ּҰ� �´�.
		pTempTiger->Hunt();
	}

	// pAnimal->Hunt(); // ��� �Ұ���

	delete pTiger;
	pTiger = nullptr;

	delete pHawk;
	pHawk = nullptr;
}

void Day0917::TestVirtualFunction()
{
	Parent* pParent = new Child();	// ����
	delete pParent;
	pParent = nullptr;
}

void Day0917::TestPractice1()
{
	// ���� �ǽ�
	// Animal*�� �迭 �����
	// ���� ������ ������ �ֱ�
	// �迭�� ����ִ� ��� ������ MakeSound �����ϱ�

	const int Size = 5;
	Animal* Zoo[Size];
	Zoo[0] = new Tiger("ȣ����");
	Zoo[1] = new Tiger("ȣ����");
	Zoo[2] = new Hawk("����");
	Zoo[3] = new Hawk("�ŵ���");
	Zoo[4] = new Dog("�۸���");

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

void Day0917::TestAbstractClass()
{
	//Shape* pShape = new Shape();

	// ���� �ǽ�
	// Animal�� Move�Լ��� ���� ���� �Լ��� ���� Animal�� �߻�Ŭ������ �����
	// �� �������� Move�� ������ �� �����ϱ�

	const int Size = 5;
	Animal* Zoo[Size];
	Zoo[0] = new Tiger("ȣ����");
	Zoo[1] = new Tiger("ȣ����");
	Zoo[2] = new Hawk("����");
	Zoo[3] = new Hawk("�ŵ���");
	Zoo[4] = new Dog("�۸���");

	for (int i = 0; i < Size; i++)
	{
		Zoo[i]->Move();
	}

	for (int i = 0; i < Size; i++)
	{
		delete Zoo[i];
		Zoo[i] = nullptr;
	}
}

// ���� �ǽ�
// ���� �������̽� �����
// ���� �������̽� �����
void Day0917::TestEnumClass()
{
	enum Color
	{
		Red = 0,
		Green,
		Blue
	};
	enum Fruit
	{
		Apple = 0,
		Orange,
		Banana
	};
	//enum TrafficLight
	//{
	//	Red, Yellow, Green
	//};	// ���� enum�� ������ �����̱� ������ �̸��� ��ġ�� �ȵ�

	Color myColor = Green;
	Fruit myFruit = Orange;
	if (myColor == myFruit)
	{
		// �������δ� ���� �ȵ����� ���������� ����� ��
	}

	enum class Color2
	{
		Red = 0,
		Green,
		Blue
	};
	enum class Fruit2
	{
		Apple = 0,
		Orange,
		Banana
	};
	enum class TrafficLight2
	{
		Red = 0,	// TrafficLight2�ȿ� �ִ� Red�� ������ �̸��� ��ġ�� �ʴ´�.
		Yellow, 
		Green
	};
	Color2 myColor2 = Color2::Red;
	Fruit2 myFruit2 = Fruit2::Apple;
	//if (myColor2 == myFruit2)
	//{
	//	// ���������� ����.
	//}
	//int Number = myColor2;	// �Ͻ��� ĳ������ ����
	int Number = static_cast<int>(myColor2);	// ����� ĳ������ �ʼ�

		

	PlayerState state = PlayerState::None;
	state = static_cast<PlayerState>(static_cast<int>(state) | static_cast<int>(PlayerState::OnGround));
	state = state | PlayerState::OnGround;	// ��ɾ� �����ε��� �ؾ� ����

	// ���� �ǽ�
	// &, ~, |=, &=

}

#include "Day0916.h"
#include "Car.h"
#include "Animal.h"
#include "Tiger.h"

//Day0916::Day0916()
//{
//	// 객체가 생성 될 때 호출
//}
//
//Day0916::~Day0916()
//{
//	// 객제가 해제될 때 호출
//}

void Day0916::ClassInstance()
{
	Car myCar = Car("지역변수");	// 인스턴스 생성. 사라지는 타이밍은 함수가 종료되었을 때 사라짐
	myCar.Accel();
	
	Car* pCar = new Car("동적할당");
	pCar->HandleTurn();
	delete pCar;
	pCar = nullptr;
}

void Day0916::TestAnimal()
{
	Animal animal;
	animal.ShowInfo();
	animal.MakeSound();
	animal.Move();
	animal.Move();
	animal.Move();
	animal.ShowInfo();
	animal.Eat();
	animal.ShowInfo();
	animal.Move();
	animal.Move();
	animal.Move();
	animal.ShowInfo();
	animal.Sleep();
	animal.ShowInfo();	

	int Age = animal.GetAge();
	const std::string& Name = animal.GetName();
}

void Day0916::TestTiger()
{
	Tiger tiger = Tiger("호식이");
	tiger.Move();
	tiger.Hunt();
	tiger.ShowInfo();
}

// 간단 실습
// 다른 동물 만들어보기(3종류)
// 다른 동물 전용 함수 구현하기
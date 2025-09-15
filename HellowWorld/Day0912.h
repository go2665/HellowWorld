#pragma once
#include <string>

// 구조체는 해더에 선언한다.
struct Enemy
{
	// 맴버 변수들
	std::string Name = "고블린";	
	float Health = 100.0f;
	float AttackPower = 10.0f;
	int DropGold = 100;

	// 기본 생성자.
	Enemy()
	{
		// 정해진 값이 아닌 값들로 초기화 되어야 할 때 사용
		DropGold = rand() % 100 + 50;	// 50 ~ 150 랜덤으로 생성됨
	}

	Enemy(std::string _Name)
	{
		Name = _Name;
	}

	// 간단 실습
	// float Modifier를 파라메터로 받는 생성자 만들기
	//	- Health는 모디파이어의 10배로 설정
	//	- AttackPower는 모디파이어의 5배로 설정
	//	- DropGold는 모디파이어의 100배로 설정

	Enemy(float Modifier)
	{
		Health = Modifier * 10.0f;
		AttackPower = Modifier * 5.0f;
		DropGold = static_cast<int>(Modifier * 100.0f);
	}

	Enemy(std::string _Name, float Modifier)
	{
		Name = _Name;
		Health = Modifier * 10.0f;
		AttackPower = Modifier * 5.0f;
		DropGold = static_cast<int>(Modifier * 100.0f);
	}

	Enemy(std::string _Name, float _Health, float _AttackPower, int _DropGold)
		: Name(_Name), Health(_Health), AttackPower(_AttackPower), DropGold(_DropGold)	// 만들때부터 값이 박힌체로 만들어진다.
	{
		// 여기서 쓰는 것은 만들어 놓고 고쳐 쓰는 것(그래서 계산이 필요한 것들은 이쪽에 해야함)
		//Name = _Name;
		//Health = _Health;
		//AttackPower = _AttackPower;
		//DropGold = _DropGold;
	}

	// +연산자를 새로 쓰겠다.
	// +는 이항연산자(+의 왼쪽과 오른쪽을 계산하는데 사용한다)
	//	왼쪽 : 자기 자신
	//	오른쪽 : other
	//	결과 : 리턴 값
	Enemy operator+(const Enemy& other) const	// <- 마지막에 붙은 const는 이 함수에서 맴버 변수의 수정을 안하겠다는 의미
	{
		// 이름은 왼쪽것을 사용
		// Health는 합치고
		// AttackPower는 양쪽다 70%사용
		// DropGold는 합치기
		return Enemy(
			Name + "(합체)",
			Health + other.Health,
			AttackPower * 0.7f + other.AttackPower * 0.7f,
			DropGold + other.DropGold);
	}

	// 간단 실습
	// 1. Enemy -연산자 오버로딩하기
	//		왼쪽에 있는 것에서 오른쪽의 값 절반을 빼기
	// 2. Enemy *연산자 오버로딩하기
	//		왼쪽은 float타입이다.
	//		Enemy operator*(float Multiplier) const { return };
	//		// 실사용 예시
	//		Enemy Goblin;
	//		Enemy Goblin2 = Goblin * 2.0f;
	// 3. Enemy *= 연산자 오버로딩하기
	//		Enemy& operator*=(float Multiplier) { return };
};

struct Weapon
{
	std::string Name = "무기";
	std::string Desc = "무기 배경 이야기";
	float AttackPower = 10.0f;
	int Price = 100;

	//Weapon()	// 없어도 자동으로 생김
	//{
	//}	
};

void Day0912_Struct();
void Day0912_OperatorOverloading();

/// <summary>
/// 적 정보 출력하는 함수
/// </summary>
/// <param name="pEnemy">출력할 적(읽기 전용)</param>
void PrintEnemy(const Enemy* pEnemy);	// pEnemy는 읽기 전용

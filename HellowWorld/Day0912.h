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

/// <summary>
/// 적 정보 출력하는 함수
/// </summary>
/// <param name="pEnemy">출력할 적(읽기 전용)</param>
void PrintEnemy(const Enemy* pEnemy);	// pEnemy는 읽기 전용

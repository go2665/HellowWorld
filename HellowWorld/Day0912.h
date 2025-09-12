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
};

void Day0912_Struct();
#pragma once
#include <string>

// ����ü�� �ش��� �����Ѵ�.
struct Enemy
{
	// �ɹ� ������
	std::string Name = "���";
	float Health = 100.0f;
	float AttackPower = 10.0f;
	int DropGold = 100;
};

void Day0912_Struct();
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

	// �⺻ ������.
	Enemy()
	{
		// ������ ���� �ƴ� ����� �ʱ�ȭ �Ǿ�� �� �� ���
		DropGold = rand() % 100 + 50;	// 50 ~ 150 �������� ������
	}

	Enemy(std::string _Name)
	{
		Name = _Name;
	}

	// ���� �ǽ�
	// float Modifier�� �Ķ���ͷ� �޴� ������ �����
	//	- Health�� ������̾��� 10��� ����
	//	- AttackPower�� ������̾��� 5��� ����
	//	- DropGold�� ������̾��� 100��� ����
};

struct Weapon
{
	std::string Name = "����";
	std::string Desc = "���� ��� �̾߱�";
	float AttackPower = 10.0f;
	int Price = 100;

	//Weapon()	// ��� �ڵ����� ����
	//{
	//}	
};

void Day0912_Struct();

/// <summary>
/// �� ���� ����ϴ� �Լ�
/// </summary>
/// <param name="pEnemy">����� ��(�б� ����)</param>
void PrintEnemy(const Enemy* pEnemy);	// pEnemy�� �б� ����

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
		: Name(_Name), Health(_Health), AttackPower(_AttackPower), DropGold(_DropGold)	// ���鶧���� ���� ����ü�� ���������.
	{
		// ���⼭ ���� ���� ����� ���� ���� ���� ��(�׷��� ����� �ʿ��� �͵��� ���ʿ� �ؾ���)
		//Name = _Name;
		//Health = _Health;
		//AttackPower = _AttackPower;
		//DropGold = _DropGold;
	}

	// +�����ڸ� ���� ���ڴ�.
	// +�� ���׿�����(+�� ���ʰ� �������� ����ϴµ� ����Ѵ�)
	//	���� : �ڱ� �ڽ�
	//	������ : other
	//	��� : ���� ��
	Enemy operator+(const Enemy& other) const	// <- �������� ���� const�� �� �Լ����� �ɹ� ������ ������ ���ϰڴٴ� �ǹ�
	{
		// �̸��� ���ʰ��� ���
		// Health�� ��ġ��
		// AttackPower�� ���ʴ� 70%���
		// DropGold�� ��ġ��
		return Enemy(
			Name + "(��ü)",
			Health + other.Health,
			AttackPower * 0.7f + other.AttackPower * 0.7f,
			DropGold + other.DropGold);
	}

	// ���� �ǽ�
	// 1. Enemy -������ �����ε��ϱ�
	//		���ʿ� �ִ� �Ϳ��� �������� �� ������ ����
	// 2. Enemy *������ �����ε��ϱ�
	//		������ floatŸ���̴�.
	//		Enemy operator*(float Multiplier) const { return };
	//		// �ǻ�� ����
	//		Enemy Goblin;
	//		Enemy Goblin2 = Goblin * 2.0f;
	// 3. Enemy *= ������ �����ε��ϱ�
	//		Enemy& operator*=(float Multiplier) { return };
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
void Day0912_OperatorOverloading();

/// <summary>
/// �� ���� ����ϴ� �Լ�
/// </summary>
/// <param name="pEnemy">����� ��(�б� ����)</param>
void PrintEnemy(const Enemy* pEnemy);	// pEnemy�� �б� ����

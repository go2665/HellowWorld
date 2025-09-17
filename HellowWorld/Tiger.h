#pragma once
#include "Animal.h"
#include "ICanBattle.h"

// Tiger�� Animal�� ��� ��� �޾Ҵ�.
class Tiger : public Animal, public	ICanBattle
{
public:
	void Hunt();	// ȣ���� ���� �Լ�
	virtual void Move() override;	// ȣ���̴� Animal�� Move�Լ��� �������.
	virtual void MakeSound() override;

	virtual void Attack(ICanBattle* Target) override;
	virtual void TakeDamage(float InDamage) override;

public:
	// ������/�Ҹ��ڴ� ����� ����� �ƴϴ�.
	Tiger() = default;
	Tiger(std::string InName)
		: Animal(InName)	// �θ� Ŭ������ Animal���� ������ ó���ϴ� �Ͱ� �Ȱ��� �ض�.
	{
	}
	virtual ~Tiger() {}

	float AttackPower = 10.0f;
};


#pragma once
class Car
{
	float Speed = 0.0f;	// �ӵ�
	float fuel = 1.0f;	// ���ᷮ

	Car();
	~Car();

	void Accel();		// ���� ���
	void Brake();		// ���� ���
	void HandleTurn();	// �ڵ� ����
};


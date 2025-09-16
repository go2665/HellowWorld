#pragma once
class Car
{
	float Speed = 0.0f;	// 속도
	float fuel = 1.0f;	// 연료량

	Car();
	~Car();

	void Accel();		// 가속 기능
	void Brake();		// 감속 기능
	void HandleTurn();	// 핸들 조향
};


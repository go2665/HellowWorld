#pragma once
#include <string>

class Car
{
public:
	std::string Name;
	float Speed = 0.0f;	// 속도
	float fuel = 1.0f;	// 연료량

	Car(const char* InName);
	~Car();

	void Accel();		// 가속 기능
	void Brake();		// 감속 기능
	void HandleTurn();	// 핸들 조향
};


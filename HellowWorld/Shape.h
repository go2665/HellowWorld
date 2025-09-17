#pragma once
class Shape	// Draw 때문에 추상 클래스가 되었다.
{
public:
	virtual void Draw() = 0;	// 순수 가상 함수.
	void Move();
};


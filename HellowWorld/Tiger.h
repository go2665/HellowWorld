#pragma once
#include "Animal.h"

class Tiger : public Animal	// Tiger는 Animal을 모두 상속 받았다.
{
public:
	void Hunt();	// 호랑이 전용 함수
	virtual void Move() override;	// 호랑이는 Animal의 Move함수를 덮어쓸꺼다.
	virtual void MakeSound() override;

public:
	// 생성자/소멸자는 상속의 대상이 아니다.
	Tiger() = default;
	Tiger(std::string InName)
		: Animal(InName)	// 부모 클래스인 Animal에서 생성자 처리하는 것과 똑같이 해라.
	{
	}
	virtual ~Tiger() {}
};


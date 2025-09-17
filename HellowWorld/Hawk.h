#pragma once
#include "Animal.h"
#include "IFlyable.h"

class Hawk : public Animal, public IFlyable
{
public:
	virtual void Move() override;
	virtual void MakeSound() override;
	virtual void Fly() override;

public:
	Hawk() = default;
	Hawk(std::string InName)
		: Animal(InName) 
	{
	}
	virtual ~Hawk() {};

};


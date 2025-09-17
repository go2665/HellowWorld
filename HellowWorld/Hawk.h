#pragma once
#include "Animal.h"
class Hawk : public Animal
{
public:
	virtual void Move() override;
	virtual void MakeSound() override;

public:
	Hawk() = default;
	Hawk(std::string InName)
		: Animal(InName) 
	{
	}
	virtual ~Hawk() {};

};


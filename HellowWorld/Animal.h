#pragma once
#include <string>

class Animal
{
public:
	void Move();
	void MakeSound();
	void Eat();
	void Sleep();

	void ShowInfo();

	// Getter/Setter
	// Energy는 외부에서는 읽기 전용이다.
	inline const float GetEnergy() const { return Energy; }	
		
public:
	Animal() = default;
	Animal(std::string InName)
		: Name(InName)
	{
	}	// 짧은 경우는 함수의 구현이 해더에 있어도 된다(자동 inline처리)

private:
	inline void SetEnergy(float InEnergy) 
	{ 
		// Energy의 범위는 0.0f ~ 1.0f이다.
		if (InEnergy < 0)
		{
			Energy = 0.0f;
		}
		else if (InEnergy > 1.0f)
		{
			Energy = 1.0f;
		}
		else
		{
			Energy = InEnergy;
		}
	}

	std::string Name = "동물";
	int Age = 0;
	float Energy = 1.0f;	// 0.0f ~ 1.0f : 1.0f일 때 100%;
};


/*
동물 클래스 만들어보기
	Name : std::string
	Energy : float
	Age : int

	동물은 움직이면(Move) 에너지를 소비한다.
	동물은 소리를 지를 수 있다.(MakeSound)
	동물은 먹으면(Eat) 에너지가 증가한다.
	동물은 잠을 자면(Sleep) 나이가 증가하고 에너지가 완전 회복된다.
	동물의 모든 정보를 출력할 수 있다.(ShowInfo)
*/
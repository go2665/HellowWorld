#pragma once
#include <iostream>
#include <type_traits>

template <typename T>
struct Coordinate
{
	T x;
	T y;
		
	Coordinate() : x{}, y{} 
	{
	}
	Coordinate(T InX, T InY)
		: x(InX), y(InY)
	{
	}

	void Print() const
	{
		// std::is_same_v<T, int> : T 타입이 int면 true, 아니면 false
		// if constexpr : 컴파일 타임에 조건이 true면 코드를 생성하고 아니면 생성하지 않는다.
		if constexpr (std::is_same_v<T, int>)
		{
			printf("(%d, %d)\n", x, y);
		}
		else if constexpr (std::is_same_v<T, float>)
		{
			printf("(%f, %f)\n", x, y);
		}
		else
		{
			std::cout << "(" << x << ", " << y << ")" << std::endl;
		}
	}

	//Coordinate& operator+=(const Coordinate& other)
	//{
	//	x += other.x;
	//	y += other.y;
	//	return *this;
	//}
	//Coordinate& operator-=(const Coordinate& other)
	//{
	//	x -= other.x;
	//	y -= other.y;
	//	return *this;
	//}
};

//// 이항연산자는 구조체 밖에 쓰는 것이 일반적이다.
//Coordinate operator+(const Coordinate& a, const Coordinate& b);
//Coordinate operator-(const Coordinate& a, const Coordinate& b);
//bool operator==(const Coordinate& a, const Coordinate& b);
//bool operator!=(const Coordinate& a, const Coordinate& b);
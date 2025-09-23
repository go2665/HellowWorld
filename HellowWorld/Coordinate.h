#pragma once
#include <iostream>
#include <type_traits>
#include <limits>

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

	Coordinate& operator+=(const Coordinate& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	Coordinate& operator-=(const Coordinate& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
};

template <typename T>
T Abs(T InValue)
{
	return (InValue < 0) ? -InValue : InValue;
}

template <typename T>
Coordinate<T> operator+(const Coordinate<T>& a, const Coordinate<T>& b)
{
	return Coordinate<T>(a.x + b.x, a.y + b.y);
}

template <typename T>
Coordinate<T> operator-(const Coordinate<T>& a, const Coordinate<T>& b)
{
	return Coordinate<T>(a.x - b.x, a.y - b.y);
}

template <typename T>
Coordinate<T> operator*(const Coordinate<T>& a, const Coordinate<T>& b)
{
	return Coordinate<T>(a.x * b.x, a.y * b.y);
}

template <typename T>
bool operator==(const Coordinate<T>& a, const Coordinate<T>& b)
{
	return a.x == b.x && a.y == b.y;
}

// 앞에 template<>를 붙이고 T자리에 특수화하고 싶은 타입을 적는다.
template <>
bool operator==(const Coordinate<float>& a, const Coordinate<float>& b)
{
	return Abs(a.x - b.x) <= FLT_EPSILON && Abs(a.y - b.y) <= FLT_EPSILON;
}
template <>
bool operator==(const Coordinate<double>& a, const Coordinate<double>& b)
{
	return Abs(a.x - b.x) <= DBL_EPSILON && Abs(a.y - b.y) <= DBL_EPSILON;
}

template <typename T>
bool operator!=(const Coordinate<T>& a, const Coordinate<T>& b)
{
	return !(a == b);
}


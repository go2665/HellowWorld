#include "Position.h"


// 이항연산자는 구조체 밖에 쓰는 것이 일반적이다.
Position operator+(const Position& a, const Position& b)
{
	return Position(a.x + b.x, a.y + b.y);
}

Position operator-(const Position& a, const Position& b)
{
	return Position(a.x - b.x, a.y - b.y);
}

bool operator==(const Position& a, const Position& b)
{
	return (a.x == b.x) && (a.y == b.y);
}

bool operator!=(const Position& a, const Position& b)
{
	//return (a.x != b.x) || (a.y != b.y);
	return !(a == b);
}


#pragma once
#include "Position.h"
class Ship
{
public:
	// 배가 가질 수 있는 최대 크기
	static constexpr int MaxShipSize = 5;

	Ship() = default;

	// 함선 배치하는 함수(InPosition은 배치될 좌표들의 시작주소, InSize는 좌표들의 개수)
	void Place(const Position* InPosition, int InSize);

	// 명중 여부를 체크하고 명중 처리를 하는 함수
	// return : 명중 여부(이미 침몰한 배는 명중안된 것으로 취급)
	// InAttackPos : 공격이 들어온 좌표
	bool CheckAndProcessHit(const Position& InAttackPos);

	// 명중 회수가 사이즈보다 크거나 같으면 이 배는 가라 앉았다.
	inline bool IsSunk() const { return Hits >= Size; }

private:
	// 배의 크기
	int Size = 0;

	// 배가 배치된 좌표들(배의 크기에 따라 낭비되는 부분이 있지만 개발 편의성을 위해 감수)
	Position Positions[MaxShipSize];

	// 맞은 회수
	int Hits = 0;
};


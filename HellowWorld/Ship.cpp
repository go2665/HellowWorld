#include "Ship.h"

void Ship::Place(const Position* InPosition, int InSize)
{
	// 함선을 배치하면서 데이터 초기화가 일어난다.
	Size = InSize;
	Hits = 0;
	for (int i = 0; i < Size; i++)
	{
		Positions[i] = InPosition[i];
	}
	for (int i = Size; i < MaxShipSize; i++)
	{
		Positions[i] = Position(-1, -1);	// 안쓰는 곳은 불가능한 좌표로 초기화
	}
}

bool Ship::CheckAndProcessHit(const Position& InAttackPos)
{
	if (IsSunk())
		return false;	// 이미 침몰한 배는 더 처리 안한다.

	for (int i = 0; i < Size; i++)
	{
		if (Positions[i] == InAttackPos)	// 명중했으면
		{
			Hits++;			// 피격 회수 증가
			return true;	// 맞았다고 리턴
		}
	}

	return false;	// 명중한 곳이 없다.
}

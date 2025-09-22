#pragma once
#include "Ship.h"
#include "HiddenMap.h"
#include "Position.h"

// 적 함선들의 배치, 피격처리, 상태 관리 등등을 처리
class ShipManager
{
public:
	ShipManager() = default;

	// 모든 함선을 맵에 배치
	void PlaceAllShips(HiddenMap& InMap);

	// 특정 좌표에 대한 공격 처리. 피격되면 true
	bool ProcessAttack(const Position& InAttackPos);

	// 방금 배가 침몰했는지 확인하는 함수
	inline bool WasShipJustSunk() const { return ShipJustSunk; }

	// 모든 배가 침몰했는지 확인하는 함수
	inline bool IsAllSunk() const { return SunkShipCount >= ShipTypeCount; }

	// 침몰하지 않은 배의 수
	inline int GetAliveShipCount() const { return ShipTypeCount - SunkShipCount; }

private:
	static constexpr int ShipTypeCount = 4;	// 함선의 가지수

	// 적 함선들
	Ship Ships[ShipTypeCount];

	// 침몰한 배의 수
	int SunkShipCount = 0;

	// 가장 최근 공격으로 함선이 침몰했는지 여부(배가 가라앉았을 때 출력 체크용)
	bool ShipJustSunk = false;

	// 함선이 배치 가능한지 확인하는 헬퍼 함수.
	bool CanPlaceShip(int InX, int InY, int InSize, bool InHorizontal, const HiddenMap& InMap) const;
};


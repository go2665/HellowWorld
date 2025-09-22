#pragma once
#include "HiddenMap.h"
#include "PlayerMap.h"
#include "ShipManager.h"
#include "Position.h"

class BattleShip
{
public:
	BattleShip();
	void Play();

private:
	// 최대 턴 수
	static constexpr int MaxTurns = 50;

	// 공격하는 함수
	bool Shoot(int InX, int InY);

	// 입력 처리하는 함수
	void HandleInput();

	// 현재 게임 상태 출력(플레이어맵, 남은턴, 공격 결과 등)
	void PrintGameState() const;

	// 게임 결과 출력
	void PrintGameResult() const;

	// 게임이 끝났는지만 체크(턴이 다 되거나 적이 모두 침몰)
	inline bool IsGameEnd() const { return TurnRemains <= 0 || EnemyFleet.IsAllSunk(); }

	// 배가 배치되는 맵(플레이어에게 안보임)
	HiddenMap GameHiddenMap;

	// 공격 결과가 저장되는 맵(플레이어가 보는 맵)
	PlayerMap GamePlayerMap;

	// 적 함선들을 관리하는 객체
	ShipManager EnemyFleet;

	// 남은 턴 수
	int TurnRemains = MaxTurns;

	// 테스트 모드 여부(히든맵을 보여준다)
	bool IsTestMode = true;
};


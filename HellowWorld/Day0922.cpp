#include "Day0922.h"
#include "Map.h"
#include "BattleShip.h"
#include <random>

void Day0922::TestBattleShip()
{
	//Map::IsValidPoition(10, 20);	// static 함수는 이렇게 사용 가능

	//srand(time(0));

	BattleShip Game;
	Game.Play();

}

#pragma once
#include "Map.h"
class PlayerMap : public Map
{
public:
	// 플레이어의 공격 결과를 맵과 함께 출력한다.
	virtual void PrintMap() const override;
};


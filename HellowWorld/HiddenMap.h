#pragma once
#include "Map.h"
class HiddenMap : public Map
{
public:
	// 게임에 패배했을 때만 사용. 적함선의 위치를 맵과 함께 출력한다.
	virtual void PrintMap() const override;
};


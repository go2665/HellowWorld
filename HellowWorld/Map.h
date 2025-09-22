#pragma once
#include <cstdint>
#include <cstdio>
//#include <stdint.h>
#include "Position.h"

using uint8 = uint8_t;

enum class CellType : uint8	// 맵에 배치되는 것들의 종류를 나타내는 enum. 8bit로 표시
{
	Empty = 0,	// 빈칸이다.
	Ship,		// 배가 배치되어 있다.
	Hit,		// 명중했다.
	Miss		// 빗나갔다.
};

class Map
{
public:
	static constexpr int MapSize = 10;	// 맵 크기. 게임 시작전부터 결정되어 있으니 이렇게 설정.

	Map()
	{
		for (int y = 0; y < MapSize; y++)
		{
			for (int x = 0; x < MapSize; x++)
			{
				Cells[y][x] = CellType::Empty;	// 일단은 전부 빈칸으로 설정
			}
		}
	}
	virtual ~Map() = default;

	// 맵을 출력하는 함수. 
	//	상속받은 클래스에서 반드시 구현해야한다.(출력내용이 다르니까)
	//	Map을 추상 클래스로 만들어서 인스턴스화 못시키게 한다(실제 게임에서는 없으니까)
	virtual void PrintMap() const = 0;

	//// 지정된 좌표의 셀값을 리턴하는 함수
	//inline CellType GetCellType(int InX, int InY) const
	//{
	//	if (IsValidPoition(InX, InY) == false)
	//	{
	//		return CellType::Empty;	// 맵 범위를 벗어나면 그냥 빈것으로 처리
	//	}
	//	return Cells[InY][InX];
	//}
	//inline CellType GetCellType(Position& InPosition) const
	//{
	//	return GetCellType(InPosition.x, InPosition.y);
	//}

	// 지정된 좌표의 셀이 비어있는지 확인하는 함수(캡슐화를 위해 최대한 데이터를 숨기기 위해 따로 만듬)
	inline bool IsCellEmpty(int InX, int InY) const 
	{ 
		if (IsValidPoition(InX, InY))
			return Cells[InY][InX] == CellType::Empty;
		return false;
	}

	// 지정된 좌표에 셀을 설정하는 함수
	inline void SetCellType(int InX, int inY, CellType InType)
	{
		if (IsValidPoition(InX, inY))
		{
			Cells[inY][InX] = InType;
		}
	}
	inline void SetCellType(Position InPosition, CellType InType)
	{
		SetCellType(InPosition.x, InPosition.y, InType);
	}

	// 좌표가 맵 범위 안인지 체크하는 함수
	//	런타입값이 필요 없기 때문에 static으로 하나만 존재하게 만든다.
	inline static bool IsValidPoition(int InX, int InY)
	{		
		return InX >= 0 && InX < MapSize && InY >= 0 && InY < MapSize;
	}

protected:
	// 셀의 상태
	CellType Cells[MapSize][MapSize];
};
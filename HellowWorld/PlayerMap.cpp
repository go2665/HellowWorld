#include "PlayerMap.h"

void PlayerMap::PrintMap() const
{
	// 상단 출력
	printf("   ");
	for (int i = 0; i < Map::MapSize; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");

	// 왼쪽 좌표 + 명중 여부 출력
	for (int y = 0; y < Map::MapSize; y++)
	{
		printf("%2d ", y);	// 왼쪽 좌표
		for (int x = 0; x < Map::MapSize; x++)
		{
			switch (Cells[y][x])
			{
			case CellType::Hit:
				printf(" X ");
				break;
			case CellType::Miss:
				printf(" O ");
				break;
			default: // Empty
				printf(" . ");
				break;
			}
		}
		printf("\n");
	}
}

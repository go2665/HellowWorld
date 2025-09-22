#include "PlayerMap.h"

void PlayerMap::PrintMap() const
{
	// »ó´Ü Ãâ·Â
	printf("   ");
	for (int i = 0; i < Map::MapSize; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");

	// ¿ÞÂÊ ÁÂÇ¥ + ¸íÁß ¿©ºÎ Ãâ·Â
	for (int y = 0; y < Map::MapSize; y++)
	{
		printf("%2d ", y);	// ¿ÞÂÊ ÁÂÇ¥
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

#include "ShipManager.h"
#include "Map.h"
#include <random>

void ShipManager::PlaceAllShips(HiddenMap& InMap)
{
    static constexpr int ShipSizes[ShipTypeCount] = { 5, 4, 3, 2 }; // 배의 크기

    // 배를 하나씩 배치하기 시작
    for (int i = 0; i < ShipTypeCount; i++)
    {
        bool IsPlaced = false;
        while (!IsPlaced) // 배치가 완료될 때까지 while 반복
        {
            int x = rand() % Map::MapSize;
            int y = rand() % Map::MapSize;
            bool IsHorizontal = rand() % 2 == 0;

            if (CanPlaceShip(x, y, ShipSizes[i], IsHorizontal, InMap))
            {
                // 배치할 수 있으면 배치 처리
                Position PlacePosition[Ship::MaxShipSize];
                for (int j = 0; j < ShipSizes[i]; j++)
                {
                    int NewX = x + (IsHorizontal ? j : 0);
                    int NewY = y + (IsHorizontal ? 0 : j);
                    InMap.SetCellType(NewX, NewY, CellType::Ship);  // 맵에 기록하고
                    PlacePosition[j] = Position(NewX, NewY);    // 배치 좌표 전부 기록한 다음
                }
                Ships[i].Place(PlacePosition, ShipSizes[i]);    // 실제 배치 처리
                IsPlaced = true;    // while 끝내라고 표시
            }
        }
    }
}

bool ShipManager::ProcessAttack(const Position& InAttackPos)
{
    ShipJustSunk = false;   // 새 공격이 시작되었으니 초기화
    for (int i = 0; i < ShipTypeCount; i++)
    {
        if (Ships[i].IsSunk())
        {
            continue; //가라앉은 배는 스킵
        }

        if (Ships[i].CheckAndProcessHit(InAttackPos))
        {
            // 배가 맞았다.
            if (Ships[i].IsSunk())
            {
                SunkShipCount++;        // 침몰 대수 증가
                ShipJustSunk = true;    // 가라앉았다고 출력하기 위해
            }
            return true;    // 맞았다.
        }
    }
    return false;   // 빗나갔다.
}

bool ShipManager::CanPlaceShip(int InX, int InY, int InSize, bool InHorizontal, const HiddenMap& InMap) const
{
    for (int i = 0; i < InSize; i++)
    {
        int NewX = InX + (InHorizontal ? i : 0);
        int NewY = InY + (InHorizontal ? 0 : i);
        if (!Map::IsValidPoition(NewX, NewY))
        {
            return false;   // 맵 안이 아니면 배치 불가
        }
        if (!InMap.IsCellEmpty(NewX, NewY))
        {
            return false;   // 해당 셀이 비어있지 않으면 배치 불가
        }
    }
    return true;    // 모든 칸이 확인이 끝났고 맵안이고 셀이 비어있다는게 확인이 됬으니 배치 가능
}

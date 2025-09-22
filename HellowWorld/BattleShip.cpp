#include "BattleShip.h"
#include <iostream>

BattleShip::BattleShip()
{
    // 나머지는 각자의 생성자에서 모두 초기화 됨
    EnemyFleet.PlaceAllShips(GameHiddenMap);    // 배들만 초기화
}

void BattleShip::Play()
{
    printf("게임을 시작합니다! 모든 적 함선을 %d턴 안에 침몰시키세요.\n", MaxTurns);

    while (!IsGameEnd())    // 게임이 끝이 안났으면 계속 반복
    {
        PrintGameState();   // 현재 게임 상태 출력하고
        HandleInput();      // 입력 처리하기
        TurnRemains--;      // 턴 감소
    }
    PrintGameResult();      // 게임이 끝났으면 결과 출력
}

bool BattleShip::Shoot(int InX, int InY)
{
    if (!Map::IsValidPoition(InX, InY))
    {
        printf("잘못된 좌표입니다.\n");
        return false;
    }

    if (!GamePlayerMap.IsCellEmpty(InX, InY))
    {
        printf("이미 공격한 좌표입니다.\n");
        return false;
    }

    Position AttackPos(InX, InY);
    if (EnemyFleet.ProcessAttack(AttackPos))
    {
        // 맞았다.
        GamePlayerMap.SetCellType(AttackPos, CellType::Hit);
        printf("명중!\n");
        if (EnemyFleet.WasShipJustSunk())
        {
            printf("배가 침몰했습니다!\n");
        }
    }
    else
    {
        // 빗나갔다.
        GamePlayerMap.SetCellType(AttackPos, CellType::Miss);
        printf("빗나갔습니다...\n");
    }

    return true;
}

void BattleShip::HandleInput()
{
    int x;
    int y;
    printf("공격 좌표를 입력하세요 (x y) : ");
    std::cin >> x >> y;
    Shoot(x, y);    // 입력받은 좌표 공격
}

void BattleShip::PrintGameState() const
{
    if (IsTestMode)
    {
        GameHiddenMap.PrintMap();
    }
    GamePlayerMap.PrintMap();
    printf("남은 턴 수 : %d\n", TurnRemains);
    printf("남은 적 함선의 수 : %d\n", EnemyFleet.GetAliveShipCount());
}

void BattleShip::PrintGameResult() const
{
    if (EnemyFleet.IsAllSunk())
    {
        printf("승리!\n");
    }
    else
    {
        printf("패배...\n");
        GameHiddenMap.PrintMap();
    }
}

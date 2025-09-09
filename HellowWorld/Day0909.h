#pragma once

void Day0909();
void Day0909_ArrayAndPointer();
void Day0909_DynamicAllocation();
void Day0909_Example();

/// <summary>
/// 주사위 굴리는 함수
/// </summary>
/// <param name="FaceNumber">주사위의 면 수. 기본값은 6</param>
/// <returns>랜덤으로 나온 주사위 값</returns>
int RollDice(int FaceNumber = 6);
void Day0908_Practice1();
void Day0908_Practice2();
void Day0908_Practice3();
void Day0908_MazeEscape();

enum MazeTile
{
    Path    = 0,
    Wall    = 1,
    Start   = 2,
    End     = 3
};

enum MoveDirection
{
    DirNone     = 0,
    DirUp       = 1 << 0,
    DirDown     = 1 << 1,
    DirLeft     = 1 << 2,
    DirRight    = 1 << 3   
};

const int MazeWidth = 20;
const int MazeHeight = 10;

const int Maze[MazeHeight][MazeWidth] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
    {1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
    {1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
    {1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
    {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

/// <summary>
/// 미로를 출력하는 함수
/// </summary>
/// <param name="PlayerX">플레이어의 현재 위치(X)</param>
/// <param name="PlayerY">플레이어의 현재 위치(Y)</param>
void PrintMaze(int PlayerX, int PlayerY);

/// <summary>
/// 플레이어의 시작위치를 받아오는 함수
/// </summary>
/// <param name="OutStartX">플레이어의 시작위치(X) 출력용파라메터</param>
/// <param name="OutStartY">플레이어의 시작위치(Y) 출력용파라메터</param>
void FindStartPosition(int& OutStartX, int& OutStartY);

/// <summary>
/// 플레이어의 현재 위치에서 가능한 이동 경로를 출력하고 모든 경로를 합친 비트 플래그를 반환합니다.
/// </summary>
/// <param name="PlayerX">플레이어의 현재 X 좌표입니다.</param>
/// <param name="PlayerY">플레이어의 현재 Y 좌표입니다.</param>
/// <returns>플레이어가 이동할 수 있는 경로를 합친 비트 플래그를 반환합니다.</returns>
int PrintAvailableMoves(int PlayerX, int PlayerY);

/// <summary>
/// 해당 위치가 벽인지 확인하는 함수
/// </summary>
/// <param name="X">확인할 위치(X)</param>
/// <param name="Y">확인할 위치(Y)</param>
/// <returns>벽이면 true, 아니면 false</returns>
bool IsWall(int X, int Y);

/// <summary>
/// 해당 위치가 도착점인지 확인하는 함수
/// </summary>
/// <param name="X">확인할 위치(X)</param>
/// <param name="Y">확인할 위치(Y)</param>
/// <returns>도착점이면 true, 아니면 false</returns>
bool IsEnd(int X, int Y);

/// <summary>
/// 입력처리를 하는 함수. 최종적으로 결정된 이동 방향 리턴
/// </summary>
/// <param name="MoveFlags">이동가능한 모든 경로의 비트플래그 합</param>
/// <returns>결정된 방향</returns>
MoveDirection GetMoveInput(int MoveFlags);
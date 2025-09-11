#pragma once

// extern : 다른 cpp에 이 변수나 함수가 있다고 알려주는 용도.
extern int MazeWidth;
extern int MazeHeight;
extern int** Maze;



/// <summary>
/// 맵 파일을 읽는 함수
/// </summary>
/// <param name="MapFileName">맵 파일 이름</param>
/// <param name="OutDataString">출력용. 파일에서 읽은 텍스트를 돌려준다.</param>
/// <returns>파일을 읽는데 성공하면 true, 실패하면 false</returns>
bool ReadMapFile(const char* MapFileName, std::string& OutDataString);

/// <summary>
/// string을 받아서 Maze를 체우는데 필요한 데이터를 파싱하는 함수
/// </summary>
/// <param name="DataString">소스용 문자열</param>
/// <returns>true : 파싱성공, false : 맵 데이터(DataString)가 잘못된 경우</returns>
bool ParseMapData(std::string& DataString);

/// <summary>
/// Source에서 발견된 첫줄을 리턴하는 함수
/// </summary>
/// <param name="InOutSource">줄(\n)을 찾을 원본 데이터</param>
/// <returns>Source에서 첫줄의 주소</returns>
char* GetLine(char** InOutSource);

/// <summary>
/// 문자열 한줄을 파싱하는 함수
/// </summary>
/// <param name="LineData">파싱할 문자열</param>
/// <param name="ArraySize">결과가 저장될 배열의 크기</param>
/// <param name="OutArray">결과가 저장될 배열</param>
void ParseLineData(const char* LineData, int ArraySize, int* OutArray );

/// <summary>
/// 미로 게임을 초기화 하는 함수
/// </summary>
void InitializeMaze();

/// <summary>
/// 미로 게임을 정리하는 함수(할당된 메모리를 해제하는 함수)
/// </summary>
void ClearMaze();

void Day0911();
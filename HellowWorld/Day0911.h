#pragma once

// extern : �ٸ� cpp�� �� ������ �Լ��� �ִٰ� �˷��ִ� �뵵.
extern int MazeWidth;
extern int MazeHeight;
extern int** Maze;

const char* DirectoryName = ".\\Data\\";

/// <summary>
/// �� ������ �д� �Լ�
/// </summary>
/// <param name="MapFileName">�� ���� �̸�</param>
/// <param name="OutDataString">��¿�. ���Ͽ��� ���� �ؽ�Ʈ�� �����ش�.</param>
/// <returns>������ �дµ� �����ϸ� true, �����ϸ� false</returns>
bool ReadMapFile(const char* MapFileName, std::string& OutDataString);

/// <summary>
/// string�� �޾Ƽ� Maze�� ü��µ� �ʿ��� �����͸� �Ľ��ϴ� �Լ�
/// </summary>
/// <param name="DataString">�ҽ��� ���ڿ�</param>
/// <returns>true : �Ľ̼���, false : �� ������(DataString)�� �߸��� ���</returns>
bool ParseMapData(std::string& DataString);

/// <summary>
/// Source���� �߰ߵǴ� \n ���� ��ġ�� �����ϴ� �Լ�
/// </summary>
/// <param name="Source">\n�� ã�� ���� ������</param>
/// <returns>\n ���� �ּ�</returns>
char* GetNextLine(char* Source);


void Day0911();
#pragma once

void Day0910_String();

/// <summary>
/// TargetString에서 TargetCharacter가 몇번째 있는지 찾아주는 함수
/// </summary>
/// <param name="TargetString">찾아질 문자열</param>
/// <param name="TargetCharacter">찾을 글자</param>
/// <returns>-1이면 못찾음, 그 외는 TargetCharacter의 인덱스</returns>
int FindCharIndex(const char* TargetString, const char TargetCharacter);

int MyStringLength(const char* Target);
void MyStringCopy(const char* Source, char* Destination);
void MyStringCat(char* Source, const char* Destination);
int MyStringCompare(const char* String1, const char* string2);
int MyAtoI(const char* Source);
float MyAtoF(const char* Source);
void SimpleParser(char* Source, const char Delimiter);
void ReadFile();
void TestString();

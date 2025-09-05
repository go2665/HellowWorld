#include <stdio.h>
#include <iostream>
#include "header.h"

// 정의부 : 선언된 내용이 실제 어떻게 동작하는 가를 구현해놓은 곳

void TestClass::TestFunc()
{
	// 동작 구현
}

void OldTales()
{
	//printf("Hello\tWorld!\n");		// C언어의 출력 방법
	//printf("\"고병조\"\t");			// ""안에 \n이 있으면 줄을 바꾸라는 의미(
	//printf("82년생입니다.┌─┐▣□\n");

	//// 이스케이프 시퀀스
	//// \n : 줄바꾸기(개행문자)
	//// \t : 탭 넣기
	//// \" : 쌍따옴표 한개
	//// \\ : \찍기
	//// \r : 캐리지 리턴(윈도우에서는 중요하지 않음. 리눅스에서는 중요함)
	//	
	////std::cout << "Hello World!\n";	// C++ 출력 방법

	//// number라는 이름을 가진 int(인티저)변수를 선언하고 거기에 0을 대입한다.
	//int number;	// 변수 선언.
	//number = 0;	// 변수에 값을 대입.

	//// int : 정수형(소수점이 없는 숫자, 5, 10, -2, 0, 66 ...)
	//number = 5.3; // number에는 5가 저장된다.
	//number = 5 / 2;	// number에는 2가 저장된다.

	////

	//scanf("%d", &number);	// 숫자를 하나 입력 받기(C)
	//printf("입력한 숫자는(C) : %d\n", number);

	//std::cin >> number;		// 숫자를 하나 입력 받기(C++)
	//printf("입력한 숫자는(C++) : %d\n", number);

	// /*프로그램을 실행했을 때 나이를 물어보고 입력받은 숫자를 그대로 출력해보기

	// 추가추가추가추가추가추가추가추가추가

	// 추가추가추가추가추가추가추가추가추가2

	// 실습실습
	// 실습실습*/

	//int number1 = 0;
	//int number2 = 0;
	//printf("숫자 1을 입력하시오 : ");
	//std::cin >> number1;
	//printf("숫자 2를 입력하시오 : ");
	//std::cin >> number2;
	//int number3 = number1 + number2;
	//printf("두 숫자의 합은 %d입니다.", number3);

	//float number1 = 10.0f;	// 10이라는 float 타입의 값을 float인 numnber1에 넣기
	//float number2 = 15.0;	// 15라는 double 타입의 값을 float인 number2에 넣기

	//std::cin >> number1 >> number2;
	//printf("number1 : %f\nnumber2 : %.2f", number1, number2);

	//// 간단실습 : 원의 반지름을 입력 받고 넓이 구하기
	//const float Pi = 3.141592f;	// 상수를 선언하고 정의
	//float radius = 0.0f;
	//printf("원의 반지름을 입력하세요 : ");
	//std::cin >> radius;
	//printf("원의 넓이는 [%f]입니다.\n", radius * radius * Pi);


	//int square = 0;
	//printf("정사각형의 한변의 길이를 입력하세요 : ");
	//std::cin >> square;
	//printf("정사각형의 넓이는 [%d]입니다.", square * square);
	//// 오버플로우 발생할 수 있음

	//float a = 123.0f;
	//float b = 0.0f;
	//std::cin >> b;
	//b = b * 123.0f;

	//bool result = a == b;	// F9 : 브레이크 포인트 설정/해제

	//float 타입을 ==로 비교할 때 반드시 아래와 같이 진행해야함.
	//float epsilon = 0.001f;
	//a < (b + epsilon);
	//a > (b - epsilon);

	// if : 소괄호 안이 true면 중괄호 안의 코드를 실행하라.
	//		내가 특정 조건을 만족할 때만 어떤 코드를 실행하고 싶을 때 사용.

	//int a = 10;
	//int b = 0;
	//printf("a는 10\nb를 입력하세요 : ");
	//std::cin >> b;

	//if (a > b)
	//{
	//	printf("if가 성공했다.\n");
	//	printf("b가 %d라서 a가 더 크다\n", b);
	//}

	//if (a <= b)
	//{
	//	printf("b가 %d라서 a가 더 작거나같다\n", b);
	//}

	//// if-else : 이거 아니면 저거일때 사용.
	//if (a > b)
	//{
	//	printf("a가 b보다 크다.\n");
	//}
	//else
	//{
	//	printf("a가 b보다 작거나 같다.\n");
	//}

	// (a != b) : a와 b가 다르다.

	//if (b < 60)
	//{
	//	//F
	//}
	//else if (b < 70)
	//{
	//	//D
	//}
	//else if(b < 80)
	//{
	//	//C
	//}
	//else if (b < 90)
	//{
	//	//B
	//}
	//else
	//{
	//	//A
	//}

	//int a = 0;
	//std::cin >> a;
	//switch (a)
	//{
	//case 1:
	//	printf("1이다.\n");
	//	break;
	//case 3:
	//	printf("3이다.\n");
	//	break;
	//case 5:
	//	printf("5이다.\n");
	//	break;
	//default:
	//	printf("1,3,5가 아니다.\n");
	//	break;
	//}

	//int a = 10;
	//int b = 20;
	//int c = 0;
	//if (a > b)
	//{
	//	c = a * 2 + b;
	//}
	//else
	//{
	//	c = a + b * 2;
	//}
	//c = (a > b) ? (a * 2 + b) : (a + b * 2); // 삼항연산자

	//int a = 10;
	//if (a > 5 && !(10 > a))
	//{
	//	// 성공
	//}
	//else
	//{
	//	// 실패
	//}

	////1. 숫자를 입력받아 양수인지 음수인지 0인지 출력하기
	//int InputNumber = 0;	
	//printf("숫자를 입력하세요 : ");
	//std::cin >> InputNumber;
	//if (InputNumber > 0)
	//{
	//	printf("입력한 숫자는 양수입니다.\n");
	//}
	//else if(InputNumber < 0)
	//{
	//	printf("입력한 숫자는 음수입니다.\n");
	//}
	//else
	//{
	//	printf("입력한 숫자는 0입니다.\n");
	//}
	//// if는 범위가 큰것이 먼저 체크되게 하기
	//// 변수는 사용하기 직전에 선언하기
	//
	////2. 숫자를 입력받아 홀수인지 짝수인지 출력하기
	//printf("홀짝을 판별하기 위한 숫자를 입력하세요 : ");
	//std::cin >> InputNumber;
	//if (InputNumber % 2 == 0)
	//{
	//	printf("짝수를 입력했습니다.\n");
	//}
	//else
	//{
	//	printf("홀수를 입력했습니다.\n");
	//}
	//
	////3. 두 수를 입력 받아 더 큰 수를 출력하기.같을 경우는 같다고 출력.
	//int Number1 = 0;
	//int Number2 = 0;
	//printf("더 큰수를 확인하기 위해 숫자 두개를 입력하세요 : ");
	//std::cin >> Number1 >> Number2;
	//if (Number1 > Number2)
	//{
	//	printf("첫번째 숫자가 더 큽니다.\n");
	//}
	//else if (Number2 > Number1)
	//{
	//	printf("두번째 숫자가 더 큽니다.\n");
	//}
	//else
	//{
	//	printf("두 수는 같은 수입니다.\n");
	//}

	////4. 나이와 키를 입력 받아, 6세 이상, 120cm 이상일 때
	////		롤러코스터 탑승 가능, 그 외에는 불가능으로 출력
	//const unsigned int LimitAge = 5;
	//const float LimitHeight = 120.0f;
	//unsigned int Age = 0;
	//float Height = 0;	// 암시적 변환(대충 변환해주는거, 보통 표현범위가 큰쪽으로 변경됨)
	//printf("나이를 입력하세요 : ");
	//std::cin >> Age;
	//printf("키를 입력하세요 : ");
	//std::cin >> Height;
	//if (Age > LimitAge && Height >= LimitHeight)
	//{
	//	printf("롤러코스터 탑승 가능!\n");
	//}
	//else
	//{
	//	printf("롤러코스터 탑승 불가능!\n");
	//}
	//
	////5. 점수를 입력 받아 90점 이상은 A, 80점 이상은 B, 70점 이상은 C, 
	////		60점 이상은 D, 그 이하는 F라고 출력하기
	//
	////6. 세 과목의 점수를 입력받아, 세 과목 평균이 60점 이상이면 
	////		"합격", 아니면 "불합격"을 출력
	////		, 단 한과목이라도 40점 미만이면 불합격 출력하기
	//int Point1 = 0;
	//int Point2 = 0;
	//int Point3 = 0;
	//printf("시험 점수를 3개 입력해 주세요 : ");
	//std::cin >> Point1 >> Point2 >> Point3;
	//const int AverageLimit = 60;
	//const int FailLimit = 40;
	//float Avergage = (Point1 + Point2 + Point3) / 3.0f;
	//if ((Avergage >= AverageLimit) &&
	//	(Point1 >= FailLimit && Point2 >= FailLimit && Point3 >= FailLimit))
	//{
	//	printf("합격\n");
	//}
	//else
	//{
	//	printf("불합격\n");
	//}

	//int flag = 0b1010;	
	//// 0b0001	= 왼쪽 키가 눌려졌다.
	//// 0b0010	= 오른쪽 키가 눌려졌다.
	//// 0b0100	= 위쪽 키가 눌려졌다.
	//// 0b1000	= 아래쪽 키가 눌려졌다.

	//if ((flag & 0b0010) != 0b0000)
	//{
	//	// 오른쪽 키가 눌려져 있다.
	//}
	//else
	//{
	//	// 오른쪽 키가 눌려져 있지 않다.
	//}

	////int flag = 0b1010;	
	//flag = flag | 0b0001;	// 결과는 flag = 0b1011;

	////int flag =        0b1010;
	//int result = flag ^ 0b0001; // 결과 = 0b1011;
	//result = 0b1011 ^ 0b0001;	// 결과 = 0b1010;

	//flag = 0b1010;
	//int test = 0b0001;
	//test = ~test;	// 왼쪽 키를 제외한 나머지 모두 세팅

	//// enum : 상수들에게 사람이 알아보기 좋은 이름을 붙여 놓은 것
	//enum Key
	//{
	//	Up		= 1 << 0,	// 0b0001
	//	Down	= 1 << 1,	// 0b0010
	//	Left	= 1 << 2,	// 0b0100
	//	Right	= 1 << 3	// 0b1000
	//};

	//if ((flag & Up) != 0)
	//{
	//	// Up버튼이 눌러져있다.
	//}

	//// 간단 실습 : 양수를 하나 입력받고 홀수인지 짝수인지 출력하기(%사용금지)
	//int InputNumber = 0;
	//printf("테스트할 수를 입력하세요 : ");
	//std::cin >> InputNumber;
	//if ((InputNumber & 1) != 0)
	//{
	//	printf("홀수를 입력했습니다.\n");
	//}
	//else
	//{
	//	printf("짝수를 입력했습니다.\n");
	//}

	////헬로 월드 10번찍기(for)
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("Hello World For: %d\n", i);
	//}

	//int Count = 1;
	//while ((Count % 3) != 0)	// while()의 조건이 참이면 코드 블럭 실행
	//{
	//	printf("Hello World While: %d\n", Count);
	//	Count++;
	//}

	//Count = 1;
	//do
	//{
	//	printf("Hello World While: %d\n", Count);
	//	Count++;
	//} while ((Count % 3) != 0);	// 일단 한번 실행하고 while()의 조건이 참이면 코드 블럭 실행

	// 간단 실습
	// 1. 0을 입력받을 때까지 입력을 계속 받고, 0이 입력되면 입력받은 숫자의 합을 출력하기
	//		while이랑 do-while모두 해보기	
	//int InputNumer = -1;
	//int Sum = 0;
	//while (true)	
	//{
	//	std::cin >> InputNumer;		
	//	Sum += InputNumer;	//Sum = Sum + InputNumer;

	//	if (InputNumer == 0)
	//		break;
	//}
	//printf("입력받은 숫자의 합 = %d", Sum);

	// 2. 입력받은 숫자의, 구구단 출력해보기
	//int InputNumber = 0;
	//printf("구구단 단수를 입력하세요 : ");
	//std::cin >> InputNumber;
	//for (int i = 1; i < 10; i++)
	//{
	//	printf("%d * %d = %d\n", InputNumber, i, InputNumber * i);
	//}

	// 3. 숫자를 하나 입력 받고, 0부터 입력받은 수까지 있는 숫자 중, 홀수만 출력하기
	//int InputNumber = 0;
	//printf("최대치를 입력하세요 : ");
	//std::cin >> InputNumber;
	//InputNumber++;	// for문에서 조건에 <=를 쓰기 싫어서 1 더함.
	//for (int i = 0; i < InputNumber; i++)
	//{
	//	if ((i % 2) == 0)
	//	{
	//		continue;
	//	}
	//	printf("%d는 홀수입니다.\n", i);
	//}

	// 4. 1~100사이의 숫자 중에 7의 배수만 출력하기
	//const int MinNumber = 1;
	//const int MaxNumber = 100;
	//for (int i = 1; i <= MaxNumber; i++)
	//{
	//	if ((i % 7) == 0)
	//	{
	//		printf("%d는 7의 배수입니다.\n", i);
	//	}
	//}

	// 5. 입력받은 숫자만큼의 층을 가진 피라미드 그리기
	//		3을 입력받았으면 아래와 같이 출력하기
	//			  *
	//			 ***
	//			*****
	// 5-1. 입력을 받아야 한다.(InputNumber)
	// 5-2. *표가 첫번째 층에서는 1개 두번째 층에서는 3개.. 이런식으로 이어지니
	//		각층별로 (층수*2 + 1)만큼의 *을 찍어야 한다.
	// 5-3. 각 층별로 " "을 (총층수-(현재 층수+1))만큼 추가해야 한다.
	//int InputNumber = 0;
	//printf("피라미드 층수를 입력하세요 : ");
	//std::cin >> InputNumber;

	//for (int i = 0; i < InputNumber; i++)
	//{
	//	for (int j = 0; j < (InputNumber - (i + 1)); j++)
	//	{
	//		printf(" ");
	//	}
	//	for (int k = 0; k < (i * 2 + 1); k++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}

	//// C 스타일의 랜덤 사용법
	////srand(time(0));
	//srand(0);
	//for (int i = 0; i < 10; i++)
	//{
	//	int RandomNumber = rand();
	//	printf("랜덤한 숫자 : %d\n", RandomNumber);
	//}

	//// 0~5까지의 숫자를 랜덤으로 구하고 싶다.
	//int RandomNumber1 = rand() % 6;

	//// 1~6까지의 숫자를 랜덤으로 구하고 싶다.
	//int RandomNumber2 = rand() % 6 + 1;

	//// C++ 스타일
	//std::random_device RandomDivece;
	//std::mt19937 Generate(RandomDivece());

	//printf("균등분포 : ");
	//std::uniform_int_distribution<> uniformDis(1, 100);
	//for (int i = 0; i < 10; i++)
	//{
	//	int Number = uniformDis(Generate);
	//	printf("%d", Number);
	//	if (i < 9)
	//	{
	//		printf(", ");
	//	}
	//}
	//printf("\n");

	//printf("정규분포 : ");
	//std::normal_distribution<> normalDis(80, 10);
	//for (int i = 0; i < 10; i++)
	//{
	//	float fNumber = normalDis(Generate);
	//	printf("%.2f", fNumber);
	//	if (i < 9)
	//	{
	//		printf(", ");
	//	}
	//}
	//printf("\n");


	////4번

	//enum Item
	//{
	//	KeyRed = 1,		// 1 << 0
	//	KeyGreen = 2,	// 1 << 1
	//	KeyBlue = 4		// 1 << 2
	//};
	//int Inventory = 0;
	//
	//// 인벤토리 내용 출력하기(Inventory의 비트내용에 따라 출력)
	//// 1번 : 아이템 추가, 2번 : 아이템 버리기, 3번 : 종료
	//// 이미 있는 아이템을 추가하려고하면 "이미 있는 아이템입니다" 출력
	//// 없는 아이템을 버리려고하면 "없는 아이템입니다." 출력

	
}

void Day0905()
{
	/*
		1. 주사위(1~6)를, 100만번 돌려서, 6이 몇번 나왔는지, 카운팅해서, 출력하기
	*/
	const int TestCount = 1000000;
	int HitCount = 0;
	for (int i = 0; i < TestCount; i++)	// 100만번 돌려서
	{
		int dice = rand() % 6 + 1;	// 주사위(1~6)를
		if (dice == 6)	// 6이 몇번 나왔는지
		{
			HitCount++;	// 카운팅해서
		}
	}
	printf("6이 나온 회수 = %d", HitCount);	// 출력하기

	/*
		2. 가위, 바위, 보 게임 만들기
			3선승제
			enum 활용

			가위 바위 보
			 - 두명의 플레이어가 가위,바위,보 중 하나를 선택한다.
			 - 선택의 결과에 따라 승과 패가 나뉜다.
			 - 가위는 보를 이긴다.
			 - 바위는 가위를 이긴다.
			 - 보는 바위를 이긴다.
	*/
	enum RockPaperScissors
	{
		Scissors,
		Rock,
		Paper,
		NumOfRps
	};
	const int WinGoal = 3;
	int PlayerWinCount = 0;
	int ComWinCount = 0;

	while (PlayerWinCount < WinGoal && ComWinCount < WinGoal)
	{
		int PlayerSelect = -1;
		while (true)	// 플레이어 선택
		{
			printf("선택하세요. [0:가위, 1:바위, 2:보] : ");
			std::cin >> PlayerSelect;

			if (PlayerSelect == Scissors
				|| PlayerSelect == Rock
				|| PlayerSelect == Paper)
			{
				break;
			}

			printf("잘못된 입력입니다. 다시 입력하세요\n");
		}
		int ComSelect = rand() % NumOfRps;	// 컴퓨터 선택

		switch (PlayerSelect)	// 승패 결정
		{
		case Scissors:
			if (ComSelect == Scissors)
			{
				printf("당신은 [가위]를 선택했고 컴퓨터는 [가위]를 선택했습니다.\n");
				printf("비겼습니다.\n");
			}
			else if (ComSelect == Rock)
			{
				printf("당신은 [가위]를 선택했고 컴퓨터는 [바위]를 선택했습니다.\n");
				printf("당신이 졌습니다.\n");
				ComWinCount++;
			}
			else if (ComSelect == Paper)
			{
				printf("당신은 [가위]를 선택했고 컴퓨터는 [보]를 선택했습니다.\n");
				printf("당신이 이겼습니다.\n");
				PlayerWinCount++;
			}
			else
			{
				printf("ERROR!!!!! 예상외의 사건이 발생함!\n");
			}
			break;
		case Rock:
			if (ComSelect == Scissors)
			{
				printf("당신은 [바위]를 선택했고 컴퓨터는 [가위]를 선택했습니다.\n");
				printf("당신이 이겼습니다.\n");
				PlayerWinCount++;
			}
			else if (ComSelect == Rock)
			{
				printf("당신은 [바위]를 선택했고 컴퓨터는 [바위]를 선택했습니다.\n");
				printf("비겼습니다.\n");
			}
			else if (ComSelect == Paper)
			{
				printf("당신은 [바위]를 선택했고 컴퓨터는 [보]를 선택했습니다.\n");
				printf("당신이 졌습니다.\n");
				ComWinCount++;
			}
			else
			{
				printf("ERROR!!!!! 예상외의 사건이 발생함!\n");
			}
			break;
		case Paper:
			if (ComSelect == Scissors)
			{
				printf("당신은 [보]를 선택했고 컴퓨터는 [가위]를 선택했습니다.\n");
				printf("당신이 졌습니다.\n");
				ComWinCount++;
			}
			else if (ComSelect == Rock)
			{
				printf("당신은 [보]를 선택했고 컴퓨터는 [바위]를 선택했습니다.\n");
				printf("당신이 이겼습니다.\n");
				PlayerWinCount++;
			}
			else if (ComSelect == Paper)
			{
				printf("당신은 [보]를 선택했고 컴퓨터는 [보]를 선택했습니다.\n");
				printf("비겼습니다.\n");
			}
			else
			{
				printf("ERROR!!!!! 예상외의 사건이 발생함!\n");
			}
			break;
		default:
			printf("ERROR!!!!! 예상외의 사건이 발생함!\n");
			break;
		}

		printf("Player = [%d], COM = [%d]\n", PlayerWinCount, ComWinCount);
	}

	if (PlayerWinCount >= WinGoal)
	{
		printf("당신이 컴퓨터를 이겼습니다!\n");
	}
	else
	{
		printf("당신이 컴퓨터에게 졌습니다...\n");
	}


	/*
		3. 하이 로우
			컴퓨터가 1~100 사이의 임의의 숫자를 선택하고,
			사용자가 맞출 때까지 입력을 받아 "더 높게", "더 낮게" 등의 힌트를 제공하는 게임
			5번안에 맞춰야 승리
	*/
	int RandomNumber = rand() % 100 + 1;
	int PlayerNumber = 0;
	int CountDown = 5;

	while (CountDown > 0)
	{
		printf("1~100 사이의 숫자를 예상해 보세요 : ");
		std::cin >> PlayerNumber;
	
		if (PlayerNumber < RandomNumber)
		{
			printf("더 큰 수를 찍어보세요\n");
		}
		else if (PlayerNumber > RandomNumber)
		{
			printf("더 작은 수를 찍어보세요\n");
		}
		else
		{
			printf("정답입니다!\n찾는 수는 %d였습니다.\n", RandomNumber);
			break;
		}
		CountDown--;
		printf("남은 회수는 %d번 입니다.\n", CountDown);
	}
	if (CountDown <= 0)
	{
		printf("실패했습니다.\n");
	}
	getchar();
	getchar();


	/*
		4. 공포 게임의 인벤토리를 비트플래그로 표현하기
			아이템 종류를 나타내는 enum을 만들고
			특정 아이템을 추가하고 삭제하는 예시 보여주기
	*/
	enum Item
	{
		Key		= 1 << 0,
		Fuse	= 1 << 1,
		Book	= 1 << 2,
		Note	= 1 << 3,		
	};

	const int ItemCount = 4;
	int Inventory = 0;
	//Inventory = 0b1111;	// 테스트 코드

	int PlayerSelect = -1;

	while (PlayerSelect != 3)
	{
		printf("어떤 일을 할까요 [1:아이템추가, 2:아이템삭제, 3:종료]: ");
		std::cin >> PlayerSelect;

		switch (PlayerSelect)
		{
		case 1:
		{
			printf("어떤 아이템을 추가할까요? [0:열쇠, 1:퓨즈, 2:책, 3:쪽지]: ");
			int AddItem = 0;
			std::cin >> AddItem;
			Inventory |= (1 << AddItem);
		}
		break;
		case 2:
		{
			printf("어떤 아이템을 제거할까요? [0:열쇠, 1:퓨즈, 2:책, 3:쪽지]: ");
			int RemoveItem = 0;
			std::cin >> RemoveItem;
			Inventory &= (~(1 << RemoveItem));
		}
		break;
		case 3:
			continue;
		default:
			// 에러 출력하기
			break;
		}

		printf("인벤토리 : ");
		if ((Inventory & Key) != 0)
		{
			printf("열쇠 ");
		}
		if ((Inventory & Fuse) != 0)
		{
			printf("퓨즈 ");
		}
		if ((Inventory & Book) != 0)
		{
			printf("책 ");
		}
		if ((Inventory & Note) != 0)
		{
			printf("쪽지 ");
		}
		printf("\n");
	}

	getchar();
	getchar();
}

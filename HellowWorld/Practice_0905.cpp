#include "Practice_0905.h"
#include <iostream>
#include <stdio.h>
#include <random>


void Practice0905_01_05()
{
	// 탬플릿 함수로 Clamp 함수 구현하기

	int Value = -120;
	int Min = 10;
	int Max = 50;
	Value = Clamp(Value, Min, Max);

	float ValueF = 5.0f;
	float MinF = 10.0f;
	float MaxF = 50.0f;
	ValueF = Clamp(ValueF, MinF, MaxF);

	Clamp(10.0, 50.0, 90.0);

}

void Practice0905_02_05()
{
	/*
	시작 금액 10000
	한판에 무조건 최소 100 배팅해야 함. 만약 소지금액이 100 이하일 경우 게임 종료.
	딜러는 A~K까지의 트럼프 카드 중 2장을 중복없이 선택하고 조커 카드가 추가된다.
	플레이어는 딜러의 카드 중 한장을 선택한다.
	만약 플레이어가 조커를 뽑있다면 플레이어의 승리. 배팅 금액의 2배를 받는다.
	플레이어가 조커를 뽑지 못했다면 다음 게임을 시작하거나 배팅 금액의 2배를 추가로 지불하고 한번 더 선택할 수 있다.
	*/

	enum Card
	{
		CardA = 0,
		Card2,
		Card3,
		Card4,
		Card5,
		Card6,
		Card7,
		Card8,
		Card9,
		Card10,
		CardJ,
		CardQ,
		CardK,
		CardJoker,
		NumOfCards
	};

	int Money = 10000;
	const int MinimumBet = 100;

	while (Money >= MinimumBet)
	{
		int CurrentBet = MinimumBet;
		
		printf("배팅을 해주세요 (100~%d) : ", Money);
		std::cin >> CurrentBet;
		printf("%d원을 배팅했습니다.\n", CurrentBet);

		Money -= CurrentBet;

		// 배팅을 안하고 있다.

		int Dealer1 = rand() % CardJoker;
		int Dealer2 = -1;
		do
		{
			Dealer2 = rand() % CardJoker;
		} while (Dealer2 == Dealer1);
		int Dealer3 = -1;
		do
		{
			Dealer3 = rand() % CardJoker;
		} while (Dealer3 == Dealer1 || Dealer3 == Dealer2);

		int JokerIndex = rand() % 3;
		switch (JokerIndex)
		{
		case 0:
			Dealer1 = CardJoker;
			break;
		case 1:
			Dealer2 = CardJoker;
			break;
		case 2:
			Dealer3 = CardJoker;
			break;
		default:
			// 절대 들어오면 안된다.
			break;
		}

		printf("카드를 선택하세요 (0, 1, 2) : ");
		int PlayerInput = 0;
		std::cin >> PlayerInput;

		bool PlayerWin = false;
		printf("플레이어는 %d를 선택했습니다.\n", PlayerInput);
		switch (PlayerInput)
		{
		case 0:
			if (Dealer1 == CardJoker)
			{
				// 발견함
				PlayerWin = true;
			}
			break;
		case 1:
			if (Dealer2 == CardJoker)
			{
				// 발견함
				PlayerWin = true;
			}
			break;
		case 2:
			if (Dealer3 == CardJoker)
			{
				// 발견함
				PlayerWin = true;
			}
			break;
		default:
			// 절대 들어오면 안된다.
			break;
		}

		if (PlayerWin)
		{
			Money += CurrentBet * 2;
			printf("조커를 뽑았습니다. 당신의 현재 금액은 %d입니다.\n", Money);
		}
		else
		{
			printf("당신이 뽑은 카드는 조커가 아닙니다.\n");

			if (Money >= CurrentBet * 2)
			{
				printf("추가 도전 하시겠습니까 ? (0:yes, 1 : no) : ");
				int Select = -1;
				std::cin >> Select;
				if (Select == 0)
				{
					Money -= CurrentBet * 2;
					CurrentBet *= 3;
					int PlayerSecondInput = -1;
					switch (PlayerInput)
					{
					case 0:
					{
						do
						{
							printf("남은 카드 중 하나를 선택하세요 (1,2) : ");
							std::cin >> PlayerSecondInput;
						} //while (!(PlayerSecondInput == 1 || PlayerSecondInput == 2));
						while (PlayerSecondInput != 1 && PlayerSecondInput != 2);
					}
					break;
					case 1:
					{
						do
						{
							printf("남은 카드 중 하나를 선택하세요 (0,2) : ");
							std::cin >> PlayerSecondInput;
						} while (PlayerSecondInput != 0 && PlayerSecondInput != 2);
					}
					break;
					case 2:
					{
						do
						{
							printf("남은 카드 중 하나를 선택하세요 (0,1) : ");
							std::cin >> PlayerSecondInput;
						} while (PlayerSecondInput != 0 && PlayerSecondInput != 1);
					}
					break;
					default:
						// 절대 들어오면 안된다.
						break;
					}

					printf("플레이어는 두번째로 %d를 선택했습니다.\n", PlayerSecondInput);
					switch (PlayerSecondInput)
					{
					case 0:
						if (Dealer1 == CardJoker)
						{
							// 발견함
							PlayerWin = true;
						}
						break;
					case 1:
						if (Dealer2 == CardJoker)
						{
							// 발견함
							PlayerWin = true;
						}
						break;
					case 2:
						if (Dealer3 == CardJoker)
						{
							// 발견함
							PlayerWin = true;
						}
						break;
					default:
						// 절대 들어오면 안된다.
						break;
					}

					if (PlayerWin)
					{
						Money += CurrentBet * 2;
						printf("조커를 뽑았습니다. 당신의 현재 금액은 %d입니다.\n", Money);
					}
					else
					{
						printf("당신의 패배입니다.\n");
					}
				}
				else
				{
					printf("당신의 패배입니다.\n");
				}
			}
			else
			{
				printf("당신의 패배입니다.\n");
			}			
		}
	}
}

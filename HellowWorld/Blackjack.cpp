#include "Blackjack.h"
#include <random>
#include <iostream>

const int MaxHand = 12; // 1*4, 2*4, 3*4

void PlayBlackjack()
{
	Card Deck[52];
	int DeckTop = 0;
	InitializeDeck(Deck);	// 덱 생성
	ShuffleDeck(Deck);		// 덱 섞기

	// 플레이어와 딜러가 카드 2장씩 받음
	Card DealerHand[MaxHand];
	int DealerCount = 0;
	Card PlayerHand[MaxHand];
	int PlayerCount = 0;
	AddCardToHand(PlayerHand, PlayerCount, DrawCard(Deck, DeckTop));	
	AddCardToHand(DealerHand, DealerCount, DrawCard(Deck, DeckTop));
	AddCardToHand(PlayerHand, PlayerCount, DrawCard(Deck, DeckTop));
	AddCardToHand(DealerHand, DealerCount, DrawCard(Deck, DeckTop));

	// 플레이어와 딜러가 받은 카드 출력(딜러는 한장은 숨긴다)
	PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, false);

	// 블랙잭이면 끝이니까 블랙잭이 있는지 먼저 확인
	bool IsPlayerBlackjack = IsBlackjack(PlayerHand, PlayerCount);
	bool IsDealerBlackjack = IsBlackjack(DealerHand, DealerCount);
	if (IsPlayerBlackjack && IsDealerBlackjack)
	{
		printf("둘 다 블랙잭! 무승부!\n");
		PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, true);
	}
	else if (IsPlayerBlackjack)
	{
		printf("플레이어가 블랙잭입니다! 승리!\n");
		PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, true);
	}
	else if (IsDealerBlackjack)
	{
		printf("딜러가 블랙잭입니다. 패배...\n");
		PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, true);
	}
	else
	{
		// 실제 게임 시작. 플레이어 턴 시작.
		bool IsPlayerStand = false;
		while (!IsPlayerStand && !IsBust(PlayerHand, PlayerCount)) // 스탠드 안했고 버스트 안하면 계속
		{
			printf("플레이어 점수 : %d\n", GetBestScore(PlayerHand, PlayerCount));
			printf("Hit(1) / Stand(2)? :");
			int Input = 0;
			std::cin >> Input;
			if (Input == 1)
			{
				AddCardToHand(PlayerHand, PlayerCount, DrawCard(Deck, DeckTop));
				PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, false);
				if (IsBust(PlayerHand, PlayerCount))
				{
					printf("플레이어 버스트! 패배!\n");
					PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, true);
					return;	// 게임 종료
				}
			}
			else
			{
				IsPlayerStand = true;
			}
		}

		// 딜러 턴 시작
		printf("딜러 턴 시작....\n");
		PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, true);
		while (GetBestScore(DealerHand, DealerCount) < 17)
		{
			if (IsSoft17(DealerHand, DealerCount))
				break;
			AddCardToHand(DealerHand, DealerCount, DrawCard(Deck, DeckTop));
			printf("딜러 카드 : ");
			PrintDealerHand(DealerHand, DealerCount, true);
			printf("\n");

			if (IsBust(DealerHand, DealerCount))
			{
				printf("딜러 버스트! 플레이어 승리!\n");
				return;
			}
		}

		// 점수 확인
		int PlayerScore = GetBestScore(PlayerHand, PlayerCount);
		int DealerScore = GetBestScore(DealerHand, DealerCount);
		PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, true);
		printf("플레이어 점수: %d, 딜러 점수:%d\n", PlayerScore, DealerScore);
		if (PlayerScore > DealerScore)
		{
			printf("플레이어 승리!\n");
		}
		else if (PlayerScore < DealerScore)
		{
			printf("딜러 승리!\n");
		}
		else
		{
			printf("무승부!\n");
		}
	}
}

void InitializeDeck(Card* Deck)
{
	const char SuitShape[4] = {'S', 'H', 'D', 'C'};
	int Index = 0;
	for (int Value = 0; Value < 13; Value++)
	{
		for (int Suit = 0; Suit < 4; Suit++)
		{
			//Deck[Index] = { Value + 1, SuitShape[Suit] };
			Deck[Index].Value = Value + 1;
			Deck[Index].Suit = SuitShape[Suit];
			Index++;
		}
	}
}

void ShuffleDeck(Card* Deck)
{
	for(int i = 51; i>0;i--)
	{
		int j = rand() % (i + 1);
		Card Temp = Deck[i];
		Deck[i] = Deck[j];
		Deck[j] = Temp;
	}
}

const Card& DrawCard(Card* InDeck, int& InTop)
{
	if (InTop >= 52)
	{
		ShuffleDeck(InDeck);
		InTop = 0;
	}
	return InDeck[InTop++];
}

void AddCardToHand(Card* InHand, int& InCount, const Card& InCard)
{
	if (InCount < MaxHand)
	{
		InHand[InCount] = InCard;
		InCount++;
	}
}

void PrintHands(const Card* InPlayerHand, int InPlayerCount, const Card* InDealerHand, int InDealerCount, bool InRevealHole)
{
	printf("플레이어 카드 : ");
	PrintPlayerHand(InPlayerHand, InPlayerCount);
	printf("\n딜러 카드 : ");
	PrintDealerHand(InDealerHand, InDealerCount, InRevealHole);
	printf("\n");
}

void PrintCard(const Card& InCard)
{
	const char* ValueStrs[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	printf("%c%s", InCard.Suit, ValueStrs[InCard.Value - 1]);
}

void PrintPlayerHand(const Card* InHand, int InCount)
{
	for (int i = 0; i < InCount; i++)
	{
		PrintCard(InHand[i]);
		printf(" ");
	}
}

void PrintDealerHand(const Card* InHand, int InCount, bool InRevealHole)
{
	for (int i = 0; i < InCount; i++)
	{
		if (i == 1 && !InRevealHole)
		{
			printf("??");
		}
		else
		{
			PrintCard(InHand[i]);
		}
		printf(" ");
	}
}

bool IsBlackjack(const Card* InHand, int InCount)
{
	// A + 10(10, J, Q, K)이 조합일 때만 블랙잭
	bool Result = false;
	if (InCount == 2)	// 일단 두장
	{
		//if (InHand[0].Value == 1 || InHand[1].Value == 1)	// Ace가 있어야 함
		//{
		//	if (GetCardValue(InHand[0]) == 10 || GetCardValue(InHand[1]) == 10) // 10이 있어야 함
		//	{
		//		Result = true;
		//	}
		//}

		if (InHand[0].Value == 1 && GetCardValue(InHand[1]) == 10		// 하나가 Ace고 나머지가 10이다.
			|| InHand[1].Value == 1 && GetCardValue(InHand[0]) == 10)
		{
			Result = true;
		}
	}

	return Result;
}

int GetCardValue(const Card& InCard)
{
	int Value = InCard.Value;	// 일단 Ace는 1로 처리
	if (Value > 10)
	{
		Value = 10; // J,Q,K = 10
	}
	
	return Value;
}

bool IsBust(Card* InHand, int InCount)
{
	return GetBestScore(InHand, InCount) > 21;
}

int GetBestScore(Card* InHand, int InCount)
{
	int Sum = 0;
	int AceCount = 0;
	for (int i = 0; i < InCount; i++)
	{
		Sum += GetCardValue(InHand[i]);
		if (InHand[i].IsAce())
		{
			AceCount++;
		}
	}

	// AceCount가 남아있고 10을 증가시켜도 버스트가 안되면 Ace하나를 11로 취급하기
	while ((AceCount > 0) && ((Sum + 10) <= 21))
	//while ((AceCount > 0) && (Sum < 12))
	{
		Sum += 10;
		AceCount--;
	}
	return Sum;
}

bool IsSoft17(Card* InHand, int InCount)
{
	int Sum = 0;
	for (int i = 0; i < InCount; i++)
	{
		Sum += GetCardValue(InHand[i]);
		if (InHand[i].IsAce())
		{
			Sum += 10;
		}
	}
	return Sum >= 17;
}

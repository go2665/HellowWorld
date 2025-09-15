#pragma once

struct Card
{
	int Value = 0;
	char Suit = 0;

	// 구조체안에 있는 함수는 순수하게 자신의 데이터만 사용하는 경우에만 만드는 것이 좋다.
	bool IsAce() { return Value == 1; }
	int GetCardValue() { return Value > 10 ? 10 : Value; }
};

void PlayBlackjack();

void InitializeDeck(Card* InDeck);
void ShuffleDeck(Card* InDeck);

const Card& DrawCard(Card* InDeck, int& InTop);
void AddCardToHand(Card* InHand, int& InCount, const Card& InCard);

void PrintHands(
	const Card* InPlayerHand, int InPlayerCount, 
	const Card* InDealerHand, int InDealerCount, bool InRevealHole);
void PrintCard(const Card& InCard);
void PrintPlayerHand(const Card* InHand, int InCount);
void PrintDealerHand(const Card* InHand, int InCount, bool InRevealHole);

bool IsBlackjack(const Card* InHand, int InCount);
int GetCardValue(const Card& InCard);

bool IsBust(Card* InHand, int InCount);
int GetBestScore(Card* InHand, int InCount);
bool IsSoft17(Card* InHand, int InCount);
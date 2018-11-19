#include "CardDeck.h"



CardDeck::CardDeck()
{
}

vector < pair<string, int>> CardDeck::Cards()
{
	string Colors[4] = { "Spades","Hearts","Diamonds" ,"Clubs" };
	vector < pair<string, int>> Cards;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j <= 14; j++)
		{
			Cards.push_back({ Colors[i], j });
		}
	}
	return Cards;

}

void CardDeck::Distribute(vector < vector < pair<string, int>>> &Players, vector < pair<string, int>> DeckOfCards)
{
	int c = 0;
	for (int i = 0; i < 4; i++)
	{
		int b = 0;
		for (int j = c; b < 13; j++, b++)
		{
			Players[i].push_back(DeckOfCards[j]);
		}
		c += 13;
	}
}

CardDeck::~CardDeck()
{
}

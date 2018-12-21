#include "CardDeck.h"



CardDeck::CardDeck()
{
}

vector < pair<int, string>> CardDeck::Cards()
{
	string Colors[4] = { "Spades","Hearts","Diamonds" ,"EClubs" };
	vector < pair<int, string>> Cards;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j <= 14; j++)
		{
			Cards.push_back({ j, Colors[i] });
		}
	}
	return Cards;

}

void CardDeck::Distribute(vector < vector < pair<int, string>>> &Players, vector < pair<int, string>> DeckOfCards)
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
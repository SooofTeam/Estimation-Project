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
CardDeck::~CardDeck()
{
}

#pragma once
#include "Includes.h"
class CardDeck
{
	
public:
	CardDeck();
	vector < pair<string, int>> Cards();
	void Distribute(vector < vector < pair<string, int>>> &Players, vector < pair<string, int>> DeckOfCards);
	~CardDeck();
};


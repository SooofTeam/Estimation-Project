#pragma once
#include "Includes.h"
class CardDeck
{

public:
	CardDeck();
	vector < pair<int, string>> Cards();
	void Distribute(vector < vector < pair<int, string>>> &Players, vector < pair<int, string>> DeckOfCards);
	~CardDeck();
};
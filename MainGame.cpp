#include "AiPlayer.h"
#include "CardDeck.h"



	int main()
	{
		AiPlayer Ai;
		CardDeck Deck;

		vector < vector < pair<string, int>>> Players(4);
	
		vector < pair<string, int>> DeckOfCards = Deck.Cards();

		random_shuffle(DeckOfCards.begin(), DeckOfCards.end());
		
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

	


		vector<pair<int, string >> Bids;

		for (int i = 0; i < 3; i++)
		{
			Bids.push_back(Ai.Bid(Players[i]));
		}

	}

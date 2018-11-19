

#include "Includes.h"




	int main()
	{
		GUI gui;
		AiPlayer Ai;
		CardDeck Deck;

		RenderWindow window(VideoMode(1000, 550), "Estimation", Style::Close | Style::Resize);
		interactiveButton Card[14];
		Texture Background,Spades[15],Hearts[15],Diamonds[15],Clubs[15];
		Sprite BackGround;

		gui.SetTextures(Spades, Hearts, Diamonds, Clubs, Background);




		vector < vector < pair<string, int>>> Players(4);
		vector < pair<string, int>> DeckOfCards = Deck.Cards();

		srand(time(0));
		random_shuffle(DeckOfCards.begin(), DeckOfCards.end());
		
		Deck.Distribute(Players, DeckOfCards);

		sort(Players[3].rbegin(), Players[3].rend());


		vector<pair<int, string >> Bids;

		for (int i = 0; i < 3; i++)
		{
			Bids.push_back(Ai.Bid(Players[i]));
		}

		gui.PlayerCardsSetup(Players[3], Card, Spades, Hearts, Diamonds, Clubs);
		BackGround.setTexture(Background);
		gui.ProgramRun(window, Card, BackGround);

	}

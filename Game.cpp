#include "Includes.h"
bool sortbysec(const pair<int, string> &a,const pair<int, string> &b)
{
	return (a.second < b.second);
}



	int main()
{
		GUI gui;
		AiPlayer Ai;
		CardDeck Deck;
		RenderWindow GameWindow(VideoMode(1000, 550), "Estimation", Style::Close | Style::Resize);
		interactiveButton Card[14];
		interactiveButton CurrentRound;
		Texture Background,Spades[15],Hearts[15],Diamonds[15],Clubs[15],Cardsholder;
		Sprite BackGround, CardsHolder;
		gui.SetTextures(Spades, Hearts, Diamonds, Clubs, Background,Cardsholder);
		vector < vector < pair<int, string>>> Players(4);
		vector < pair<int, string>> DeckOfCards = Deck.Cards();
		srand(time(0));
		random_shuffle(DeckOfCards.begin(), DeckOfCards.end());

		Deck.Distribute(Players, DeckOfCards);
		sort(Players[3].rbegin(), Players[3].rend());
		sort(Players[3].rbegin(), Players[3].rend(),sortbysec);

		vector<pair<int, string >> Bids;
		for (int i = 0; i < 3; i++)
		{
		Bids.push_back(Ai.MainCall(Ai.BidCall(Players[i]), Players[i]));
		}

		sort(Bids.rbegin(), Bids.rend(), sortbysec);
		sort(Bids.rbegin(), Bids.rend());
	
		gui.PlayerCardsSetup(Players[3], Card, Spades, Hearts, Diamonds, Clubs);
		BackGround.setTexture(Background);
		CardsHolder.setTexture(Cardsholder);
		gui.ProgramRun(GameWindow, Card, BackGround, CurrentRound,CardsHolder,Bids);
}
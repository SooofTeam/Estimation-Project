#include "Includes.h"




int main()
{

	GUI gui;
	AiPlayer Ai;
	CardDeck Deck;
	RenderWindow GameWindow(VideoMode(1000, 550), "Estimation", Style::Close | Style::Resize);
	interactiveButton UserCards[14];
	interactiveButton AiPlayer_0_Cards[14];
	interactiveButton AiPlayer_1_Cards[14];
	interactiveButton AiPlayer_2_Cards[14];

	Texture Background, Spades[15], Hearts[15], Diamonds[15], Clubs[15], Cardsholder;
	Sprite BackGround, CardsHolder;
	gui.SetTextures(Spades, Hearts, Diamonds, Clubs, Background, Cardsholder);
	vector < vector < pair<int, string>>> Players(4);



	vector<pair<int, string >> Bids;

	BackGround.setTexture(Background);
	CardsHolder.setTexture(Cardsholder);

	gui.ProgramRun(GameWindow, UserCards, AiPlayer_0_Cards, AiPlayer_1_Cards, AiPlayer_2_Cards, BackGround, CardsHolder, Bids, Players, Spades, Diamonds, Hearts, Clubs);
}

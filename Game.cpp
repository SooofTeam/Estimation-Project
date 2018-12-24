#include "Includes.h"




int main()
{

	GUI gui;
	AiPlayer Ai;
	CardDeck Deck;
	
	bool namewritten = false;

	RenderWindow GameWindow(VideoMode(1000, 550), "Estimation", Style::Close | Style::Resize);
	RenderWindow MainMenu(VideoMode(1000, 550), "Estimation", Style::Close | Style::Resize);
	interactiveButton UserCards[14];
	interactiveButton AiPlayer_0_Cards[14];
	interactiveButton AiPlayer_1_Cards[14];
	interactiveButton AiPlayer_2_Cards[14];

	Texture Background, Spades[15], Hearts[15], Diamonds[15], Clubs[15], Cardsholder, MainMenuBackgroundT;
	MainMenuBackgroundT.loadFromFile("CardsTextures/MainMenu.jpg");
	Sprite BackGround, CardsHolder ,MainMenuBackground;
	gui.SetTextures(Spades, Hearts, Diamonds, Clubs, Background, Cardsholder);
	vector < vector < pair<int, string>>> Players(4);

	Font font;
	font.loadFromFile("ObelixPro-cyr.ttf");
	Text text;
	text.setFont(font);
	text.setPosition(450,400);
	text.Bold;
	text.setCharacterSize(50);
	text.setFillColor(Color::White);
	vector<pair<int, string >> Bids;

	BackGround.setTexture(Background);
	CardsHolder.setTexture(Cardsholder);
	MainMenuBackground.setTexture(MainMenuBackgroundT);
	MainMenuBackground.setPosition(0, 0);
	string name;
	while (MainMenu.isOpen())
	{
		Event E;
		while (MainMenu.pollEvent(E))
		{
			switch (E.type)
			{
			case Event::Closed:
				MainMenu.close();
				break;
			case Event::TextEntered:
				if ((E.text.unicode < 128 && name.size() <14 ) || E.text.unicode == 8)
				{
					name = text.getString();
					if (E.text.unicode == 13 && name.size() != 0)
					{
						namewritten = true;
						MainMenu.close();
					}
					else if (E.text.unicode == 8)
					{
						if (name.size() > 0)name.resize(name.size() - 1);
					}
					else if(E.text.unicode != 13)
					{
						name += static_cast<char>(E.text.unicode);
					}
					text.setString(name);
					break;
				}
			default:
				break;
			}
		}


		MainMenu.clear();
		MainMenu.draw(MainMenuBackground);
		MainMenu.draw(text);
		MainMenu.display();

	}
	if(namewritten)
	gui.ProgramRun(GameWindow, UserCards, AiPlayer_0_Cards, AiPlayer_1_Cards, AiPlayer_2_Cards, BackGround, CardsHolder, Bids, Players, Spades, Diamonds, Hearts, Clubs,name);

}

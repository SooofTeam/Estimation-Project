#include "GUI.h"



GUI::GUI()
{
}

void GUI::SetTextures(Texture Spades[15], Texture Hearts[15], Texture Diamonds[15], Texture Clubs[15], Texture &Background)
{
	///////////////////////Spades Textures////////////////////
	Spades[2].loadFromFile("CardsTextures/2_of_spades.jpg");
	Spades[3].loadFromFile("CardsTextures/3_of_spades.jpg");
	Spades[4].loadFromFile("CardsTextures/4_of_spades.jpg");
	Spades[5].loadFromFile("CardsTextures/5_of_spades.jpg");
	Spades[6].loadFromFile("CardsTextures/6_of_spades.jpg");
	Spades[7].loadFromFile("CardsTextures/7_of_spades.jpg");
	Spades[8].loadFromFile("CardsTextures/8_of_spades.jpg");
	Spades[9].loadFromFile("CardsTextures/9_of_spades.jpg");
	Spades[10].loadFromFile("CardsTextures/10_of_spades.jpg");
	Spades[11].loadFromFile("CardsTextures/jack_of_spades2.jpg");
	Spades[12].loadFromFile("CardsTextures/queen_of_spades2.jpg");
	Spades[13].loadFromFile("CardsTextures/king_of_spades2.jpg");
	Spades[14].loadFromFile("CardsTextures/ace_of_spades.jpg");
	///////////////////////Hearts Textures//////////////////////
	Hearts[2].loadFromFile("CardsTextures/2_of_hearts.jpg");
	Hearts[3].loadFromFile("CardsTextures/3_of_hearts.jpg");
	Hearts[4].loadFromFile("CardsTextures/4_of_hearts.jpg");
	Hearts[5].loadFromFile("CardsTextures/5_of_hearts.jpg");
	Hearts[6].loadFromFile("CardsTextures/6_of_hearts.jpg");
	Hearts[7].loadFromFile("CardsTextures/7_of_hearts.jpg");
	Hearts[8].loadFromFile("CardsTextures/8_of_hearts.jpg");
	Hearts[9].loadFromFile("CardsTextures/9_of_hearts.jpg");
	Hearts[10].loadFromFile("CardsTextures/10_of_hearts.jpg");
	Hearts[11].loadFromFile("CardsTextures/jack_of_hearts2.jpg");
	Hearts[12].loadFromFile("CardsTextures/queen_of_hearts2.jpg");
	Hearts[13].loadFromFile("CardsTextures/king_of_hearts2.jpg");
	Hearts[14].loadFromFile("CardsTextures/ace_of_hearts.jpg");
	//////////////////////Diamonds Textures/////////////////////
	Diamonds[2].loadFromFile("CardsTextures/2_of_diamonds.jpg");
	Diamonds[3].loadFromFile("CardsTextures/3_of_diamonds.jpg");
	Diamonds[4].loadFromFile("CardsTextures/4_of_diamonds.jpg");
	Diamonds[5].loadFromFile("CardsTextures/5_of_diamonds.jpg");
	Diamonds[6].loadFromFile("CardsTextures/6_of_diamonds.jpg");
	Diamonds[7].loadFromFile("CardsTextures/7_of_diamonds.jpg");
	Diamonds[8].loadFromFile("CardsTextures/8_of_diamonds.jpg");
	Diamonds[9].loadFromFile("CardsTextures/9_of_diamonds.jpg");
	Diamonds[10].loadFromFile("CardsTextures/10_of_diamonds.jpg");
	Diamonds[11].loadFromFile("CardsTextures/jack_of_diamonds2.jpg");
	Diamonds[12].loadFromFile("CardsTextures/queen_of_diamonds2.jpg");
	Diamonds[13].loadFromFile("CardsTextures/king_of_diamonds2.jpg");
	Diamonds[14].loadFromFile("CardsTextures/ace_of_diamonds.jpg");
	//////////////////////////Clubs Textures/////////////////////////
	Clubs[2].loadFromFile("CardsTextures/2_of_clubs.jpg");
	Clubs[3].loadFromFile("CardsTextures/3_of_clubs.jpg");
	Clubs[4].loadFromFile("CardsTextures/4_of_clubs.jpg");
	Clubs[5].loadFromFile("CardsTextures/5_of_clubs.jpg");
	Clubs[6].loadFromFile("CardsTextures/6_of_clubs.jpg");
	Clubs[7].loadFromFile("CardsTextures/7_of_clubs.jpg");
	Clubs[8].loadFromFile("CardsTextures/8_of_clubs.jpg");
	Clubs[9].loadFromFile("CardsTextures/9_of_clubs.jpg");
	Clubs[10].loadFromFile("CardsTextures/10_of_clubs.jpg");
	Clubs[11].loadFromFile("CardsTextures/jack_of_clubs2.jpg");
	Clubs[12].loadFromFile("CardsTextures/queen_of_clubs2.jpg");
	Clubs[13].loadFromFile("CardsTextures/king_of_clubs2.jpg");
	Clubs[14].loadFromFile("CardsTextures/ace_of_clubs.jpg");
	///////////////////////////////////////////////////////////////
	Background.loadFromFile("CardsTextures/BackGround.jpg");
}
void GUI::PlayerCardsSetup(vector < pair<int, string>> Players, interactiveButton Card[14], Texture Spades[15], Texture Hearts[15], Texture Diamonds[15], Texture Clubs[15])
{
	int j = 0;
	while (j != 13)
	{
		if (Players[j].second == "Spades")
		{
			Card[j].normal = Spades[Players[j].first];
			Card[j].shape.setPosition(1580, 1000);
			Card[j].TypeAndValue.first = "Spades";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		else if (Players[j].second == "Hearts")
		{
			Card[j].normal = Hearts[Players[j].first];
			Card[j].shape.setPosition(1580, 1000);
			Card[j].TypeAndValue.first = "Hearts";
			Card[j].TypeAndValue.second = Players[j].first;

		}
		else if (Players[j].second == "Diamonds")
		{
			Card[j].normal = Diamonds[Players[j].first];
			Card[j].shape.setPosition(1580, 1000);
			Card[j].TypeAndValue.first = "Diamonds";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		else if (Players[j].second == "EClubs")
		{
			Card[j].normal = Clubs[Players[j].first];
			Card[j].shape.setPosition(1580, 1000);
			Card[j].TypeAndValue.first = "EClubs";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		normalize(Card[j]);
		j++;
	}
}
void GUI::ProgramRun(RenderWindow &window,interactiveButton Card[14], Sprite BackGround,interactiveButton RoundDone)
{
	interactiveButton tmp;
	tmp.shape.setSize(Vector2f(25, 25));
	RoundDone.shape.setSize(Vector2f(75,108));
	RoundDone.shape.setPosition(Vector2f(550, 268));
	RoundDone.shape.setFillColor(Color::Red);
	RectButtonAssign(RoundDone);
	RoundDone.shape.rotate(180.0f);
	bool firstround = false;
	stack<interactiveButton>LastRound;
	stack<interactiveButton>OnGround;
	LastRound.push(tmp);
	OnGround.push(tmp);
	for (int i = 0; i < 13; i++)
		{
		Card[i].shape.setSize(Vector2f(75, 108));
		}

	float factor = 75;
	int i = 0;
	int h = 0;
	Vector2f destination = Vector2f(250, 500);
	int check[13] = {};
	memset(check, 0, 13);
	while (window.isOpen())
	{
		Event E;
		while (window.pollEvent(E))
		{
			switch (E.type)
			{
			case Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		if (i != 13)
		{
			if (Card[i].shape.getPosition().y >= destination.y)
			{
				Card[i].shape.rotate(180.0f);
				Card[i].shape.move(-500, -170);
			}
			else
			{
				i++;
				Card[i].shape.move(factor, 0);
				factor += 75;
			}
		}

		if (h != 1 && i == 13)
		{
			for (int f = 0; f < 13; f++)
			{
				RectButtonAssign(Card[f]);
			}
			h++;
		}




		for (int p = 0; p<13; p++)
			if (ibuttonAutoHover(Card[p], window))
			{
				check[p] = 1;
				OnGround.push(Card[p]);
				Card[p].Reset();
				hang();
			}

		if (ibuttonAutoHover(RoundDone,window))
		{
			for (int p = 0; p < 13; p++)
			{
				if (check[p]==1)
				{
					OnGround.top().shape.setPosition(979, 181);
					RectButtonAssign(OnGround.top());
					LastRound.push(OnGround.top());
					check[p] = 2;
				}
			}
		}

		window.clear();
		window.draw(BackGround);
		window.draw(RoundDone.shape);
		for (int i = 0; i < 13; i++)
		{
			if (check[i] == 0)
			{
				window.draw(Card[i].shape);
			}
			else if (check[i] == 1)
			{
				OnGround.top().shape.setPosition(487, 268);
				RectButtonAssign(OnGround.top());
				window.draw(OnGround.top().shape);
			 }
			else if (check[i] == 2)
			{
				window.draw(LastRound.top().shape);
			}

		}

		window.display();
	}

}
void GUI::normalize(interactiveButton &ib)
{
	ib.shape.setTexture(&ib.normal);
}
void GUI::RectButtonAssign(interactiveButton &ib)
{
	ib.button.lowerLimit = ib.shape.getPosition();
	ib.button.upperLimit.x = ib.button.lowerLimit.x - ib.shape.getSize().x - 1;
	ib.button.upperLimit.y = ib.button.lowerLimit.y - ib.shape.getSize().y - 1;
}
bool GUI::LMB()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return 1;
	else
		return 0;
}
bool GUI::isButtonHovered(interactiveButton ib, RenderWindow &window)
{
	Button AButton = ib.button;
	sf::Vector2i original = sf::Mouse::getPosition(window);
	if (original.x>AButton.upperLimit.x&& original.x<AButton.lowerLimit.x && original.y>AButton.upperLimit.y && original.y<AButton.lowerLimit.y)
	{
		return 1;
	}

	return 0;
}
bool GUI::ibuttonAutoHover(interactiveButton &ib, sf::RenderWindow &window)
{
	if (isButtonHovered(ib, window))
	{
		if (LMB())
			return 1;
	}
	else
		normalize(ib);
	return 0;
}
void GUI::hang()
{
	while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		continue;
}

GUI::~GUI()
{
}

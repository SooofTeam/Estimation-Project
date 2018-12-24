#include "GUI.h"
bool sortbysec(const pair<int, string> &a, const pair<int, string> &b)
{
	return (a.second < b.second);
}


GUI::GUI()
{
}

void GUI::SetTextures(Texture Spades[15], Texture Hearts[15], Texture Diamonds[15], Texture Clubs[15], Texture &Background, Texture &CardsHolder)
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
	CardsHolder.loadFromFile("CardsTextures/CardsHolder.jpg");
}
void GUI::PlayerCardsSetup(vector < pair<int, string>> Players, interactiveButton Card[14], Texture Spades[15], Texture Diamonds[15], Texture Hearts[15], Texture Clubs[15])
{
	int j = 0;
	while (j != 13)
	{
		if (Players[j].second == "Spades")
		{
			Card[j].normal = Spades[Players[j].first];
			Card[j].shape.setPosition(120, 570);
			Card[j].TypeAndValue.first = "Spades";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		else if (Players[j].second == "Hearts")
		{
			Card[j].normal = Hearts[Players[j].first];
			Card[j].shape.setPosition(120, 570);
			Card[j].TypeAndValue.first = "Hearts";
			Card[j].TypeAndValue.second = Players[j].first;

		}
		else if (Players[j].second == "Diamonds")
		{
			Card[j].normal = Diamonds[Players[j].first];
			Card[j].shape.setPosition(120, 570);
			Card[j].TypeAndValue.first = "Diamonds";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		else if (Players[j].second == "EClubs")
		{
			Card[j].normal = Clubs[Players[j].first];
			Card[j].shape.setPosition(120, 570);
			Card[j].TypeAndValue.first = "EClubs";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		normalize(Card[j]);
		j++;
	}
}
void GUI::Ai_0_CardsSetup(vector < pair<int, string>> Players, interactiveButton Card[14], Texture Spades[15], Texture Diamonds[15], Texture Hearts[15], Texture Clubs[15])
{
	int j = 0;
	while (j != 13)
	{
		if (Players[j].second == "Spades")
		{
			Card[j].normal = Spades[Players[j].first];
			Card[j].shape.setPosition(855, 230);
			Card[j].TypeAndValue.first = "Spades";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		else if (Players[j].second == "Hearts")
		{
			Card[j].normal = Hearts[Players[j].first];
			Card[j].shape.setPosition(855, 230);
			Card[j].TypeAndValue.first = "Hearts";
			Card[j].TypeAndValue.second = Players[j].first;

		}
		else if (Players[j].second == "Diamonds")
		{
			Card[j].normal = Diamonds[Players[j].first];
			Card[j].shape.setPosition(855, 230);
			Card[j].TypeAndValue.first = "Diamonds";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		else if (Players[j].second == "EClubs")
		{
			Card[j].normal = Clubs[Players[j].first];
			Card[j].shape.setPosition(855, 230);
			Card[j].TypeAndValue.first = "EClubs";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		normalize(Card[j]);
		j++;
	}
}
void GUI::Ai_1_CardsSetup(vector < pair<int, string>> Players, interactiveButton Card[14], Texture Spades[15], Texture Diamonds[15], Texture Hearts[15], Texture Clubs[15])
{
	int j = 0;
	while (j != 13)
	{
		if (Players[j].second == "Spades")
		{
			Card[j].normal = Spades[Players[j].first];
			Card[j].shape.setPosition(475, 90);
			Card[j].TypeAndValue.first = "Spades";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		else if (Players[j].second == "Hearts")
		{
			Card[j].normal = Hearts[Players[j].first];
			Card[j].shape.setPosition(475, 90);
			Card[j].TypeAndValue.first = "Hearts";
			Card[j].TypeAndValue.second = Players[j].first;

		}
		else if (Players[j].second == "Diamonds")
		{
			Card[j].normal = Diamonds[Players[j].first];
			Card[j].shape.setPosition(475, 90);
			Card[j].TypeAndValue.first = "Diamonds";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		else if (Players[j].second == "EClubs")
		{
			Card[j].normal = Clubs[Players[j].first];
			Card[j].shape.setPosition(475, 90);
			Card[j].TypeAndValue.first = "EClubs";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		normalize(Card[j]);
		j++;
	}
}
void GUI::Ai_2_CardsSetup(vector < pair<int, string>> Players, interactiveButton Card[14], Texture Spades[15], Texture Diamonds[15], Texture Hearts[15], Texture Clubs[15])
{
	int j = 0;
	while (j != 13)
	{
		if (Players[j].second == "Spades")
		{
			Card[j].normal = Spades[Players[j].first];
			Card[j].shape.setPosition(145, 230);
			Card[j].TypeAndValue.first = "Spades";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		else if (Players[j].second == "Hearts")
		{
			Card[j].normal = Hearts[Players[j].first];
			Card[j].shape.setPosition(145, 230);
			Card[j].TypeAndValue.first = "Hearts";
			Card[j].TypeAndValue.second = Players[j].first;

		}
		else if (Players[j].second == "Diamonds")
		{
			Card[j].normal = Diamonds[Players[j].first];
			Card[j].shape.setPosition(145, 230);
			Card[j].TypeAndValue.first = "Diamonds";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		else if (Players[j].second == "EClubs")
		{
			Card[j].normal = Clubs[Players[j].first];
			Card[j].shape.setPosition(145, 230);
			Card[j].TypeAndValue.first = "EClubs";
			Card[j].TypeAndValue.second = Players[j].first;
		}
		normalize(Card[j]);
		j++;
	}
}
void GUI::GameDesignSetUp(Texture &avatar1, Sprite &Avatar1, Texture &avatar2, Sprite &Avatar2, Texture &avatar3, Sprite &Avatar3, Texture &SHDC, Sprite &shdc, Texture &CallingWindow, Sprite &callingwindow, Sprite &callingwindow2, interactiveButton CallNumber[14], interactiveButton CallColor[4], interactiveButton Choice[2])
{
	int factor = 12;
	avatar1.loadFromFile("CardsTextures/Avatar1.jpg");
	Avatar1.setTexture(avatar1);

	avatar2.loadFromFile("CardsTextures/Avatar2.jpg");
	Avatar2.setTexture(avatar2);

	avatar3.loadFromFile("CardsTextures/Avatar3.jpg");
	Avatar3.setTexture(avatar3);

	SHDC.loadFromFile("CardsTextures/SHDC.png");
	shdc.setTexture(SHDC);

	CallingWindow.loadFromFile("CardsTextures/CallingWindow.jpg");
	callingwindow.setTexture(CallingWindow);
	callingwindow2.setTexture(CallingWindow);

	CallNumber[0].normal.loadFromFile("CardsTextures/0.jpg");
	CallNumber[1].normal.loadFromFile("CardsTextures/1.jpg");
	CallNumber[2].normal.loadFromFile("CardsTextures/2.jpg");
	CallNumber[3].normal.loadFromFile("CardsTextures/3.jpg");
	CallNumber[4].normal.loadFromFile("CardsTextures/4.jpg");
	CallNumber[5].normal.loadFromFile("CardsTextures/5.jpg");
	CallNumber[6].normal.loadFromFile("CardsTextures/6.jpg");
	CallNumber[7].normal.loadFromFile("CardsTextures/7.jpg");
	CallNumber[8].normal.loadFromFile("CardsTextures/8.jpg");
	CallNumber[9].normal.loadFromFile("CardsTextures/9.jpg");
	CallNumber[10].normal.loadFromFile("CardsTextures/10.jpg");
	CallNumber[11].normal.loadFromFile("CardsTextures/11.jpg");
	CallNumber[12].normal.loadFromFile("CardsTextures/12.jpg");
	CallNumber[13].normal.loadFromFile("CardsTextures/13.jpg");

	CallNumber[0].clicked.loadFromFile("CardsTextures/0Clicked.jpg");
	CallNumber[1].clicked.loadFromFile("CardsTextures/1Clicked.jpg");
	CallNumber[2].clicked.loadFromFile("CardsTextures/2Clicked.jpg");
	CallNumber[3].clicked.loadFromFile("CardsTextures/3Clicked.jpg");
	CallNumber[4].clicked.loadFromFile("CardsTextures/4Clicked.jpg");
	CallNumber[5].clicked.loadFromFile("CardsTextures/5Clicked.jpg");
	CallNumber[6].clicked.loadFromFile("CardsTextures/6Clicked.jpg");
	CallNumber[7].clicked.loadFromFile("CardsTextures/7Clicked.jpg");
	CallNumber[8].clicked.loadFromFile("CardsTextures/8Clicked.jpg");
	CallNumber[9].clicked.loadFromFile("CardsTextures/9Clicked.jpg");
	CallNumber[10].clicked.loadFromFile("CardsTextures/10Clicked.jpg");
	CallNumber[11].clicked.loadFromFile("CardsTextures/11Clicked.jpg");
	CallNumber[12].clicked.loadFromFile("CardsTextures/12Clicked.jpg");
	CallNumber[13].clicked.loadFromFile("CardsTextures/13Clicked.jpg");

	CallColor[0].normal.loadFromFile("CardsTextures/Spade.png");
	CallColor[1].normal.loadFromFile("CardsTextures/Heart.png");
	CallColor[2].normal.loadFromFile("CardsTextures/Diamond.png");
	CallColor[3].normal.loadFromFile("CardsTextures/Club.png");

	CallColor[0].clicked.loadFromFile("CardsTextures/SpadeClicked.jpg");
	CallColor[1].clicked.loadFromFile("CardsTextures/HeartClicked.jpg");
	CallColor[2].clicked.loadFromFile("CardsTextures/DiamondClicked.jpg");
	CallColor[3].clicked.loadFromFile("CardsTextures/ClubClicked.jpg");

	Choice[0].normal.loadFromFile("CardsTextures/Pass.jpg");
	Choice[1].normal.loadFromFile("CardsTextures/Call.jpg");

	for (int i = 0; i < 2; i++)
	{
		normalize(Choice[i]);
		Choice[i].shape.setSize(Vector2f(100.0f, 29.0f));
		if (i == 0)
			Choice[i].shape.setPosition(12, 270.0f);
		else if (i == 1)
			Choice[i].shape.setPosition(300, 270.0f);
		RectButtonAssign(Choice[i]);
		Choice[i].TypeAndValue.second = i;
	}
	factor = 12;
	for (int i = 0; i <= 6; i++)
	{
		normalize(CallNumber[i]);
		CallNumber[i].shape.setSize(Vector2f(67.0f, 50.0f));
		CallNumber[i].shape.setPosition(factor, 100.0f);
		RectButtonAssign(CallNumber[i]);
		CallNumber[i].TypeAndValue.second = i;
		factor += 67;
	}

	factor = 12;

	for (int i = 7; i <= 13; i++)
	{
		if (i <= 9)
		{
			normalize(CallNumber[i]);
			CallNumber[i].shape.setSize(Vector2f(67.0f, 50.0f));
			CallNumber[i].shape.setPosition(factor, 155.0f);
			RectButtonAssign(CallNumber[i]);
			CallNumber[i].TypeAndValue.second = i;
			factor += 67;
		}
		else
		{
			normalize(CallNumber[i]);
			CallNumber[i].shape.setSize(Vector2f(67.0f, 50.0f));
			CallNumber[i].shape.setPosition(factor, 155.0f);
			RectButtonAssign(CallNumber[i]);
			CallNumber[i].TypeAndValue.second = i;
			factor += 67;
		}
	}

	factor = 12;

	for (int i = 0; i <= 3; i++)
	{
		normalize(CallColor[i]);
		CallColor[i].shape.setSize(Vector2f(67.0f, 50.0f));
		CallColor[i].shape.setPosition(factor, 210.0f);
		RectButtonAssign(CallColor[i]);
		CallColor[i].TypeAndValue.second = i;
		factor += 112.5;
	}



	Avatar1.setPosition(90, 230);
	Avatar2.setPosition(480, 43);
	Avatar3.setPosition(817, 230);
	shdc.setPosition(480, 230);
	callingwindow.setPosition(275, 125);
	callingwindow2.setPosition(275, 125);


}
string GUI::TrumpDes(vector<pair<int, string>> Bids, int &Caller, pair<int, string>UserBid)
{
	pair<int, string> max = Bids[0];
	Caller = 0;
	for (int i = 1; i < 3; i++)
	{
		if (Bids[i].first > max.first)
		{
			Caller = i;
			max = Bids[i];
		}
		else if (Bids[i].first == max.first)
		{
			if (Bids[i].second > max.second)
			{
				Caller = i;
				max = Bids[i];
			}
		}
	}

	if (UserBid.first > max.first)
	{
		Caller = 3;
		max = UserBid;
	}


	return max.second;
}

void GUI::ProgramRun(RenderWindow &window, interactiveButton Card[14], interactiveButton Ai_0_Card[14], interactiveButton Ai_1_Card[14], interactiveButton Ai_2_Card[14], Sprite BackGround, Sprite CardsHolder, vector<pair<int, string >> &Bids, vector < vector < pair<int, string>>> Players, Texture Spades[15], Texture Hearts[15], Texture Diamonds[15], Texture Clubs[15],string UserName)
{
	ifstream x;
	x.open("Scores.txt", std::ofstream::out | std::ofstream::trunc);
	x.close();
	AiPlayer Ai;
	CardDeck Deck;
	vector<bool> inHand(4), InHand(4);
	//vector <pair<int, string>> CardsOnGround;
	vector<vector<pair<int, int>>> Halemm(4);
	int KolElLammat[4] = {};
	memset(KolElLammat, 0, 4);
	string status;
	int Scores[4] = { 0,0,0,0 };
	int temppos[4];

	int TotalLammat = 0;
	string Trump;
	pair<int, string> UserBid;

	interactiveButton GroundCards[4];
	for (int i = 0; i < 4; i++)
	{
		GroundCards[i].shape.setSize(Vector2f(75, 108));
	}

	interactiveButton CallNumber[14];
	interactiveButton CallColor[4];
	interactiveButton Choice[2];
	interactiveButton ScoreBoardWindow;


	Texture avatar1;
	Sprite Avatar1;
	Texture avatar2;
	Sprite Avatar2;
	Texture avatar3;
	Sprite Avatar3;
	Texture SHDC;
	Sprite shdc;
	Texture CallingWindow;
	Texture ScoreBoardWindowT;
	Texture TrumpPhotoT[4];
	TrumpPhotoT[0].loadFromFile("CardsTextures/TrumpS.png");
	TrumpPhotoT[1].loadFromFile("CardsTextures/TrumpH.png");
	TrumpPhotoT[2].loadFromFile("CardsTextures/TrumpD.png");
	TrumpPhotoT[3].loadFromFile("CardsTextures/TrumpC.png");
	Sprite callingwindow;
	Sprite callingwindow2;
	Sprite TrumpPhoto[4];
	for (int i = 0; i < 4; i++)
	{
		TrumpPhoto[i].setTexture(TrumpPhotoT[i]);
		TrumpPhoto[i].setPosition(800, 30);
	}

	GameDesignSetUp(avatar1, Avatar1, avatar2, Avatar2, avatar3, Avatar3, SHDC, shdc, CallingWindow, callingwindow, callingwindow2, CallNumber, CallColor, Choice);

	ScoreBoardWindowT.loadFromFile("CardsTextures/SBbutton.jpg");


	ScoreBoardWindow.normal = ScoreBoardWindowT;
	normalize(ScoreBoardWindow);
	ScoreBoardWindow.shape.setSize(Vector2f( 100,100 ));
	ScoreBoardWindow.shape.setPosition(Vector2f(900, 0));
	RectButtonAssign2(ScoreBoardWindow);

	Text text;
	Font font;
	Text currentCalls[4];
	Text LammetKam[4];
	Text StatusWriter;
	pair<string, string> HighestBid;

	int maximum;

	pair<int, string> wara2a;
	Vector2f destination = Vector2f(1000, 550);
	string mode = "RoundSetup";
	vector<pair <int, string>> OnGround;
	float factorx = 60;
	bool roundstarted = true;
	int i = 0, i2 = 0;
	int h = 0;
	int m = -1;
	vector<int> Lammat(4);
	vector<int>Calls(4);
	bool finalcall = false;
	bool UserTurn = false, Player0Turn = false, Player1Turn = false, Player2Turn = false;
	vector<vector<pair<int, string>>> DecksOfCards(4);
	for (int i = 0; i < 3; i++)
	{
		DecksOfCards[i] = Deck.Cards();
	}
	bool checkCallNumber[14] = {};
	memset(checkCallNumber, 0, 14);
	bool checkCallColor[4] = {};
	memset(checkCallColor, 0, 4);
	bool ishovered[13] = {};
	memset(ishovered, 0, 13);

	int PlaysCounter = 1;
	int RoundsCounter = 1;

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


		if (mode == "RoundSetup")
		{
			system("CLS");
			TotalLammat = 0;
			HighestBid.first = "";
			HighestBid.second = "";
			Bids.clear();
			status = "";
			DecksOfCards[3].clear();
			OnGround.clear();
			for (int i = 0; i < 4; i++)
			{
				InHand[i] = 0;
				inHand[i] = 0;
				Lammat[i] = 0;
			}
			vector < pair<int, string>> DeckOfCards = Deck.Cards();
			//srand(time(0));
			for(int jb=0;jb<833;jb++)
			random_shuffle(DeckOfCards.begin(), DeckOfCards.end());

			Deck.Distribute(Players, DeckOfCards);
			sort(Players[3].rbegin(), Players[3].rend());
			sort(Players[3].rbegin(), Players[3].rend(), sortbysec);

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < Players[i].size(); j++)
				{
					cout << Players[i][j].first << " " << Players[i][j].second << endl;
				}
				cout << endl;
				cout << endl;
			}

			for (int i = 0; i < 3; i++)
			{
				Bids.push_back(Ai.MainCall(Ai.BidCall(Players[i]), Players[i]));
			}
			UserBid.first = 0;
			UserBid.second = "";

			for (int i = 0; i < 3; i++)
			{
				cout << Bids[i].first << " " << Bids[i].second << endl;
			}

			Ai_0_CardsSetup(Players[0], Ai_0_Card, Spades, Hearts, Diamonds, Clubs);

			Ai_1_CardsSetup(Players[1], Ai_1_Card, Spades, Hearts, Diamonds, Clubs);

			Ai_2_CardsSetup(Players[2], Ai_2_Card, Spades, Hearts, Diamonds, Clubs);

			PlayerCardsSetup(Players[3], Card, Spades, Hearts, Diamonds, Clubs);

			maximum = Bids[0].first;

			for (int i = 0; i < Bids.size(); i++)
			{
				if (Bids[i].first >= maximum)
				{
					HighestBid.first = to_string(Bids[i].first);
					HighestBid.second = Bids[i].second;
					maximum = Bids[i].first;
				}
			}


			font.loadFromFile("ObelixPro-cyr.ttf");
			text.setFont(font);
			text.setString("The Highest Bid Till now is : " + HighestBid.first + " Of " + HighestBid.second);
			text.setPosition(290, 180);
			text.setCharacterSize(15);
			text.setFillColor(Color::Black);
			text.Bold;

			currentCalls[0].setPosition(880, 341);
			LammetKam[0].setPosition(850, 341);
			currentCalls[1].setPosition(640, 71);
			LammetKam[1].setPosition(610, 71);
			currentCalls[2].setPosition(150, 187);
			LammetKam[2].setPosition(120, 187);
			currentCalls[3].setPosition(100, 38);
			LammetKam[3].setPosition(70, 38);

			StatusWriter.setPosition(800, 80);
			StatusWriter.setFont(font);
			StatusWriter.setCharacterSize(25);
			StatusWriter.Bold;
			StatusWriter.setFillColor(Color::Black);
			for (int t = 0; t < 4; t++)
			{
				currentCalls[t].setFont(font);
				currentCalls[t].setCharacterSize(30);
				currentCalls[t].setFillColor(Color::White);
				currentCalls[t].Bold;
				LammetKam[t].setFont(font);
				LammetKam[t].setCharacterSize(30);
				LammetKam[t].setFillColor(Color::White);
				LammetKam[t].Bold;
			}

			CardsHolder.setPosition(95, 460);




			for (int i = 0; i < 13; i++)
			{
				Card[i].shape.setSize(Vector2f(75, 108));
				//Ai_0_Card[i].shape.setSize(Vector2f(75, 108));
				//Ai_1_Card[i].shape.setSize(Vector2f(75, 108));
				//Ai_2_Card[i].shape.setSize(Vector2f(75, 108));
			}
			factorx = 60;
			roundstarted = true;
			i = 0, i2 = 0;
			h = 0;
			m = -1;
			finalcall = false;
			UserTurn = false; Player0Turn = false; Player1Turn = false; Player2Turn = false;
			for (int i = 0; i < 3; i++)
			{
				DecksOfCards[i] = Deck.Cards();
			}
			memset(checkCallNumber, 0, 14);
			memset(checkCallColor, 0, 4);
			memset(ishovered, 0, 13);
			GameDesignSetUp(avatar1, Avatar1, avatar2, Avatar2, avatar3, Avatar3, SHDC, shdc, CallingWindow, callingwindow, callingwindow2, CallNumber, CallColor, Choice);


			mode = "RoundSetupAnimation";

		}

		if (mode == "RoundSetupAnimation")
		{


			if (i != 13)
			{

				if (Card[i].shape.getPosition().y >= destination.y)
				{
					Card[i].shape.move(0, -100);
				}
				else
				{
					i++;
					Card[i].shape.move(factorx, 0);
					factorx += 60;
				}
			}
			else
			{
				mode = "UserCalling";
			}

		}

		if (mode == "UserCalling")
		{
			RenderWindow CallingWindow1(VideoMode(502, 325), "Estimation", Style::Close | Style::Resize);
			//here
			callingwindow.setPosition(0, 0);
			text.setPosition(9, 53);
			while (CallingWindow1.isOpen())
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



				for (int c = 4; c <= 13; c++)
				{
					if (ibuttonAutoHover(CallNumber[c], CallingWindow1))
					{
						memset(checkCallNumber, 0, 14);
						checkCallNumber[c] = 1;
					}
				}
				for (int c = 4; c <= 13; c++)
				{
					if (checkCallNumber[c])
					{
						CallNumber[c].shape.setTexture(&CallNumber[c].clicked);
						UserBid.first = CallNumber[c].TypeAndValue.second;
					}
				}


				for (int c = 0; c <= 3; c++)
				{
					if (ibuttonAutoHover(CallColor[c], CallingWindow1))
					{
						memset(checkCallColor, 0, 4);
						checkCallColor[c] = 1;
					}
				}
				for (int c = 0; c <= 3; c++)
				{
					if (checkCallColor[c])
					{
						CallColor[c].shape.setTexture(&CallColor[c].clicked);

						if (CallColor[c].TypeAndValue.second == 0)
							UserBid.second = "Spades";
						else if (CallColor[c].TypeAndValue.second == 1)
							UserBid.second = "Hearts";
						else if (CallColor[c].TypeAndValue.second == 2)
							UserBid.second = "Diamonds";
						else if (CallColor[c].TypeAndValue.second == 3)
							UserBid.second = "EClubs";
					}
				}

				for (int c = 0; c <= 1; c++)
				{
					if (ibuttonAutoHover(Choice[c], CallingWindow1))
					{
						if (Choice[c].TypeAndValue.second)
						{
							mode = "BeforeFinalCalling";
							Bids.push_back(UserBid);
							Trump = TrumpDes(Bids, Caller, UserBid);
							//Hena Code el Sewar
							//
							//
							//
							//Hena Code el Sewar
							if (maximum < UserBid.first)
								maximum = UserBid.first;
							CallingWindow1.close();
							roundstarted = false;
						}
						else
						{
							UserBid.first = 0;
							UserBid.second = "0";
							mode = "BeforeFinalCalling";
							Bids.push_back(UserBid);
							Trump = TrumpDes(Bids, Caller, UserBid);
							//Hena Code el Sewar
							//
							//
							//
							//Hena Code el Sewar
							if (maximum < UserBid.first)
								maximum = UserBid.first;
							CallingWindow1.close();
							roundstarted = false;

						}
					}
				}



				CallingWindow1.clear();
				CallingWindow1.draw(callingwindow);
				CallingWindow1.draw(text);
				for (int c = 4; c <= 13; c++)
				{
					CallingWindow1.draw(CallNumber[c].shape);
				}
				for (int c = 0; c <= 3; c++)
				{
					CallingWindow1.draw(CallColor[c].shape);
				}
				for (int c = 0; c <= 1; c++)
				{
					CallingWindow1.draw(Choice[c].shape);
				}

				CallingWindow1.display();

			}
		}
		
		if (mode == "ScoreCalculation")
		{
			bool riskDa = 0,withDa=0;
			int winners = 0;
			for (int b = 0; b < 4; b++) {
				if (Lammat[b] == Calls[b]) {
					winners++;
				}
			}
			for (int b = Caller, v = 0; v < 4; v++) {
				riskDa = 0; withDa = 0;
				if (v == 0) {
					Scores[b] += Ai.score(Calls[b], Lammat[b], false, false, true, false, status, winners, 4 - winners); b = (b + 1) % 4; continue;
					}
				if (Lammat[b] == Lammat[Caller]) { withDa = 1; }
				if (v == 3) {
					if (abs(13 - TotalLammat) >= 2) { riskDa = 1; }
				}
				
					Scores[b]+=Ai.score(Calls[b], Lammat[b], riskDa, false, false, withDa, status, winners, 4 - winners);
					b = (b + 1) % 4;

			}
			ofstream writing;
			writing.open("Scores.txt",ios::app);
			for (int b = 0; b < 4; b++) {
				writing << Scores[b] << " ";
			}
			writing << endl;
			writing.close();
			mode = "RoundSetup";

		}
	
		if (mode == "BeforeFinalCalling")
		{
			int v;
			if (Trump == "Spades")v = 0;
			if (Trump == "Hearts")v = 1;
			if (Trump == "Diamonds")v = 2;
			if (Trump == "EClubs")v = 3;


			normalize(CallNumber[UserBid.first]);
			for (int x = 0; x < 4; x++)
			{
				if (CallColor[x].TypeAndValue.second == v)
				{
					CallColor[v].shape.setTexture(&CallColor[v].clicked);
				}
				else
				{
					CallColor[x].Reset();
					CallColor[x].shape.setSize(Vector2f(0, 0));
				}
			}
			Choice[0].Reset();
			Choice[0].shape.setSize(Vector2f(0, 0));
			text.setString("Choose your Finall Call , Trump is : " + Trump);
			mode = "FinalCalling";

		}

		if (mode == "FinalCalling")
		{
			bool wasal = false;
			RenderWindow CallingWindow2(VideoMode(502, 325), "Estimation", Style::Close | Style::Resize);

			for (int gh = 0, b = Caller; gh < 4; gh++)
			{
				cout << "(GH) : " << gh << " " << "(B) :"<<b << endl;
				
				int temp = 0;

				if (b == 3 && !wasal)//User Final Call
				{
					wasal = true;
					cout << "wasal lel User Call , wel (gh) = " << gh << endl;
					while (CallingWindow2.isOpen())
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

						if (Caller == 3)
						{
							for (int c = maximum; c <= 13; c++)
							{
								if (ibuttonAutoHover(CallNumber[c], CallingWindow2))
								{
									finalcall = true;
									memset(checkCallNumber, 0, 14);
									checkCallNumber[c] = 1;
								}
							}

							for (int c = maximum; c <= 13; c++)
							{
								if (checkCallNumber[c])
								{
									CallNumber[c].shape.setTexture(&CallNumber[c].clicked);
									UserBid.first = CallNumber[c].TypeAndValue.second;
								}
							}
						}
						else
						{
							for (int c = 0; c <= maximum; c++)
							{
								if (ibuttonAutoHover(CallNumber[c], CallingWindow2))
								{
									finalcall = true;
									memset(checkCallNumber, 0, 14);
									checkCallNumber[c] = 1;
								}
							}

							for (int c = 0; c <= maximum; c++)
							{
								if (checkCallNumber[c])
								{
									CallNumber[c].shape.setTexture(&CallNumber[c].clicked);
									UserBid.first = CallNumber[c].TypeAndValue.second;
								}
							}
						}
						if (ibuttonAutoHover(Choice[1], CallingWindow2) && finalcall)
						{
							TotalLammat += UserBid.first;
							Calls[b] = UserBid.first;
							
							if (gh != 3 && b == 3)
							{
								b = (b + 1) % 4;
							}
							else
							{
								(TotalLammat > 13) ? status = "Over" : status = "Under";
								cout << "Status :" << status << endl;
							}
							CallingWindow2.close();
							if (Caller == 0) { mode = "Player0Turn"; inHand[0] = 1; InHand[0] = 1; }
							else if (Caller == 1) { mode = "Player1Turn"; inHand[1] = 1; InHand[1] = 1; }
							else if (Caller == 2) { mode = "Player2Turn"; inHand[2] = 1; InHand[2] = 1; }
							else if (Caller == 3) { mode = "UserTurn"; inHand[3] = 1; InHand[3] = 1; }

							currentCalls[3].setString("/" + to_string(UserBid.first));

							for (int i = 0; i < 4; i++)
							{
								LammetKam[i].setString("0");
							}
							break;
						}

						CallingWindow2.clear();
						CallingWindow2.draw(callingwindow);
						CallingWindow2.draw(text);
						if (Caller == 3)
						{

							for (int c = maximum; c <= 13; c++)
							{
								
								CallingWindow2.draw(CallNumber[c].shape);
							}

							for (int c = 0; c <= 3; c++)
							{
								CallingWindow2.draw(CallColor[c].shape);
							}
						}
						else
						{
							for (int c = 0; c <= maximum; c++)
							{
								if (abs(TotalLammat - 13) == c)
									continue;
								CallingWindow2.draw(CallNumber[c].shape);
							}

							for (int c = 0; c <= 3; c++)
							{
								CallingWindow2.draw(CallColor[c].shape);
							}

						}

						CallingWindow2.draw(Choice[1].shape);

						CallingWindow2.display();

					}
					continue;
				}
				
				
				if (gh == 3 && b != 3)
				{
					cout << "Wasal le a5er caller , wel (gh) =" << gh << endl;
					temp = Ai.FinalCall(Trump, Players[b], -1, TotalLammat, Halemm[b]);
					TotalLammat += temp;
					Calls[b] = temp;

					cout <<"TEMP : " << temp << endl;
					
					currentCalls[b].setString(" / "+to_string(temp));
					
					(TotalLammat > 13) ? status = "Over" : status = "Under";
					cout << "Status :" << status << endl;


					for (int i = 0; i < 4; i++)
					{
						LammetKam[i].setString("0");
					}
					
					if (finalcall)
					{
						if (Caller == 0) { mode = "Player0Turn"; inHand[0] = 1; InHand[0] = 1; }
						else if (Caller == 1) { mode = "Player1Turn"; inHand[1] = 1; InHand[1] = 1; }
						else if (Caller == 2) { mode = "Player2Turn"; inHand[2] = 1; InHand[2] = 1; }
						else if (Caller == 3) { mode = "UserTurn"; inHand[3] = 1; InHand[3] = 1; }	
					}

					break;
				}
				else if (b != 3 )
				{
					temp = Ai.FinalCall(Trump, Players[b], b, TotalLammat, Halemm[b]);
					Calls[b] = temp;
					currentCalls[b].setString("/" + to_string(temp));
					TotalLammat += temp;

					b = (b + 1) % 4;
				}
			}
		}

		if (mode == "PlayEnding")
		{
			for (int i = 0; i < 4; i++)
			{
				if (GroundCards[i].TypeAndValue.first == "Spades")
				{
					GroundCards[i].normal = Spades[GroundCards[i].TypeAndValue.second];
				}
				else if (GroundCards[i].TypeAndValue.first == "Diamonds")
				{
					GroundCards[i].normal = Hearts[GroundCards[i].TypeAndValue.second];
				}
				else if (GroundCards[i].TypeAndValue.first == "Hearts")
				{
					GroundCards[i].normal = Diamonds[GroundCards[i].TypeAndValue.second];
				}
				else if (GroundCards[i].TypeAndValue.first == "EClubs")
				{
					GroundCards[i].normal = Clubs[GroundCards[i].TypeAndValue.second];
				}
				normalize(GroundCards[i]);
			}

			Ai.PlayGround(OnGround, Trump, Calls, InHand, Lammat);
			LammetKam[0].setString(to_string(Lammat[0]));
			LammetKam[1].setString(to_string(Lammat[1]));
			LammetKam[2].setString(to_string(Lammat[2]));
			LammetKam[3].setString(to_string(Lammat[3]));
			for (int gf = 0; gf < OnGround.size(); gf++)
				DecksOfCards[3].push_back(OnGround[gf]);

			mode = "PlayEndingAnimation";
		}

		if (mode == "PlayEndingAnimation")
		{
			Ai_0_Card[temppos[0]].shape.setSize(Vector2f(0, 0));
			Ai_1_Card[temppos[1]].shape.setSize(Vector2f(0, 0));
			Ai_2_Card[temppos[2]].shape.setSize(Vector2f(0, 0));
			Card[temppos[3]].shape.setSize(Vector2f(0, 0));
			if (InHand[0])
			{
				if (GroundCards[0].shape.getPosition().x < 855)
				{
					GroundCards[0].shape.move(5, 0);
				}
				if (GroundCards[1].shape.getPosition().x < 855)
				{
					GroundCards[1].shape.move(5, 0);
				}
				if (GroundCards[2].shape.getPosition().x < 855)
				{
					GroundCards[2].shape.move(5, 0);
				}
				if (GroundCards[3].shape.getPosition().x < 855)
				{
					GroundCards[3].shape.move(5, 0);
				}
				else
				{
					if (Players[0].size() == 0)
						mode = "ScoreCalculation";
					else
						mode = "NextPlay";
				}
			}
			if (InHand[1])
			{
				if (GroundCards[0].shape.getPosition().y > 90)
				{
					GroundCards[0].shape.move(0, -5);
				}
				if (GroundCards[1].shape.getPosition().y > 90)
				{
					GroundCards[1].shape.move(0, -5);
				}
				if (GroundCards[2].shape.getPosition().y > 90)
				{
					GroundCards[2].shape.move(0, -5);
				}
				if (GroundCards[3].shape.getPosition().y > 90)
				{
					GroundCards[3].shape.move(0, -5);
				}
				else
				{
					if (Players[0].size() == 0)
						mode = "ScoreCalculation";
					else
						mode = "NextPlay";

				}

			}
			if (InHand[2])
			{

				if (GroundCards[0].shape.getPosition().x > 145)
				{
					GroundCards[0].shape.move(-5, 0);
				}
				if (GroundCards[1].shape.getPosition().x > 145)
				{
					GroundCards[1].shape.move(-5, 0);
				}
				if (GroundCards[2].shape.getPosition().x > 145)
				{
					GroundCards[2].shape.move(-5, 0);
				}
				if (GroundCards[3].shape.getPosition().x > 145)
				{
					GroundCards[3].shape.move(-5, 0);
				}
				else
				{
					if (Players[0].size() == 0)
						mode = "ScoreCalculation";
					else
						mode = "NextPlay";

				}

			}
			if (InHand[3])
			{

				if (GroundCards[0].shape.getPosition().y < 550)
				{
					GroundCards[0].shape.move(0, 5);
				}
				if (GroundCards[1].shape.getPosition().y < 550)
				{
					GroundCards[1].shape.move(0, 5);
				}
				if (GroundCards[2].shape.getPosition().y < 550)
				{
					GroundCards[2].shape.move(0, 5);
				}
				if (GroundCards[3].shape.getPosition().y < 550)
				{
					GroundCards[3].shape.move(0, 5);
				}
				else
				{
					if (Players[0].size() == 0)
						mode = "ScoreCalculation";
					else
						mode = "NextPlay";
				}

			}

		}

		if (mode == "UserTurn" && inHand[3])
		{

			int tempo;

			vector <vector <int>> Shapes(4);
			for (auto i : Players[3])
			{

				if (i.second == "Spades")
				{
					Shapes[0].push_back(i.first);
				}
				if (i.second == "Hearts")
				{
					Shapes[1].push_back(i.first);
				}
				if (i.second == "Diamonds")
				{
					Shapes[2].push_back(i.first);
				}

				if (i.second == "EClubs")
				{
					Shapes[3].push_back(i.first);
				}
			}
			if (!OnGround.empty())
				tempo = Ai.switchString(OnGround[0].second);

			for (int f = 0; f < 13; f++)
			{
				if (!OnGround.empty() && Shapes[tempo].size() != 0)
				{
					if (Card[f].TypeAndValue.first == OnGround[0].second)
						RectButtonAssign(Card[f]);
				}
				else
				{
					RectButtonAssign(Card[f]);
				}
			}
			for (int p = 0; p < 13; p++)
			{

				if (!OnGround.empty() && Shapes[tempo].size() != 0)
				{
					if (Card[p].TypeAndValue.first == OnGround[0].second && isButtonHovered(Card[p], window))
					{
						if (ishovered[p] == 0)
						{
							ishovered[p] = 1;
							Card[p].shape.move(0, -20);
						}
					}
					else
					{
						if (ishovered[p] == 1)
						{
							ishovered[p] = 0;
							Card[p].shape.move(0, 20);
						}

					}
				}
				else
				{
					if (isButtonHovered(Card[p], window))
					{
						if (ishovered[p] == 0)
						{
							ishovered[p] = 1;
							Card[p].shape.move(0, -20);
						}
					}
					else
					{
						if (ishovered[p] == 1)
						{
							ishovered[p] = 0;
							Card[p].shape.move(0, 20);
						}

					}
				}
			}

			for (int p = 0; p < 13; p++)
			{
				if (!OnGround.empty() && Shapes[tempo].size() != 0)
				{
					if (Card[p].TypeAndValue.first == OnGround[0].second && ibuttonAutoHover(Card[p], window))
					{
						pair <int, string> temp;
						temp.first = Card[p].TypeAndValue.second;
						temp.second = Card[p].TypeAndValue.first;
						wara2a = temp;
						OnGround.push_back(wara2a);
						for (int i = 0; i < Players[3].size(); i++)
						{
							if (Players[3][i].first == wara2a.first &&Players[3][i].second == wara2a.second)
							{
								Players[3].erase(Players[3].begin() + i);
							}
						}
						GroundCards[OnGround.size() - 1].TypeAndValue.first = wara2a.second;
						GroundCards[OnGround.size() - 1].TypeAndValue.second = wara2a.first;
						m = p;
						Card[p].Reset();
						hang();
						mode = "UserPlaying";
						Card[m].shape.setPosition(Vector2f(477, 447));
						break;
					}
				}
				else
				{
					if (ibuttonAutoHover(Card[p], window))
					{
						pair <int, string> temp;
						temp.first = Card[p].TypeAndValue.second;
						temp.second = Card[p].TypeAndValue.first;
						wara2a = temp;
						OnGround.push_back(wara2a);
						for (int i = 0; i < Players[3].size(); i++)
						{
							if (Players[3][i].first == wara2a.first &&Players[3][i].second == wara2a.second)
							{
								Players[3].erase(Players[3].begin() + i);
							}
						}
						GroundCards[OnGround.size() - 1].TypeAndValue.first = wara2a.second;
						GroundCards[OnGround.size() - 1].TypeAndValue.second = wara2a.first;
						m = p;
						Card[p].Reset();
						hang();
						mode = "UserPlaying";
						Card[m].shape.setPosition(Vector2f(477, 447));
						break;
					}

				}
			}

		}

		if (mode == "UserPlaying")
		{
			if (Card[m].shape.getPosition().y > 290)
			{
				Card[m].shape.move(0, -1);
			}
			else
			{
				GroundCards[OnGround.size() - 1].shape.setPosition(Card[m].shape.getPosition());
				mode = "Player0Turn";
				inHand[0] = true;
				temppos[3] = m;
				m = -1;
				if (OnGround.size() == 4)
				{
					mode = "PlayEnding";
				}
			}
		}

		if (mode == "Player0Turn" && inHand[0])
		{
			cout << "Player 0 , elMafrood Yelem :  " << Calls[0] << " Lammet : " << Lammat[0] << endl;
			wara2a = Ai.CardDes(DecksOfCards[0], DecksOfCards[3], OnGround, Trump, Players[0], status, Lammat[0], Calls[0], Halemm[0]);
			OnGround.push_back(wara2a);

			GroundCards[OnGround.size() - 1].TypeAndValue.first = wara2a.second;
			GroundCards[OnGround.size() - 1].TypeAndValue.second = wara2a.first;
			cout << "Player 0 Hayel3ab : " << wara2a.first << " " << wara2a.second << endl;
			for (int v = 0; v < 13; v++)
			{
				if (Ai_0_Card[v].TypeAndValue.first == wara2a.second && Ai_0_Card[v].TypeAndValue.second == wara2a.first)
				{
					m = v;
					break;
				}
			}
			mode = "Player0Playing";
		}

		if (mode == "Player0Playing")
		{
			Ai_0_Card[m].shape.setSize(Vector2f(75, 108));
			if (Ai_0_Card[m].shape.getPosition().x > 550)
			{
				Ai_0_Card[m].shape.move(-1, 0);
			}
			else
			{
				GroundCards[OnGround.size() - 1].shape.setPosition(Ai_0_Card[m].shape.getPosition());
				mode = "Player1Turn";
				inHand[1] = true;
				temppos[0] = m;
				m = -1;
				if (OnGround.size() == 4)
					mode = "PlayEnding";
			}
		}

		if (mode == "Player1Turn" && inHand[1])
		{
			cout << "Player 1 , elMafrood Yelem :  " << Calls[1] << " Lammet : " << Lammat[1] << endl;
			wara2a = Ai.CardDes(DecksOfCards[1], DecksOfCards[3], OnGround, Trump, Players[1], status, Lammat[1], Calls[1], Halemm[1]);
			OnGround.push_back(wara2a);
			GroundCards[OnGround.size() - 1].TypeAndValue.first = wara2a.second;
			GroundCards[OnGround.size() - 1].TypeAndValue.second = wara2a.first;
			cout << "Player 1 Hayel3ab : " << wara2a.first << " " << wara2a.second << endl;
			for (int v = 0; v < 13; v++)
			{
				if (Ai_1_Card[v].TypeAndValue.first == wara2a.second && Ai_1_Card[v].TypeAndValue.second == wara2a.first)
				{
					m = v;
					break;
				}
			}
			mode = "Player1Playing";
		}

		if (mode == "Player1Playing")
		{
			Ai_1_Card[m].shape.setSize(Vector2f(75, 108));
			if (Ai_1_Card[m].shape.getPosition().y < 180)
			{
				Ai_1_Card[m].shape.move(0, 1);
			}
			else
			{
				GroundCards[OnGround.size() - 1].shape.setPosition(Ai_1_Card[m].shape.getPosition());
				mode = "Player2Turn";
				inHand[2] = true;
				temppos[1] = m;
				m = -1;
				if (OnGround.size() == 4)
					mode = "PlayEnding";
			}
		}

		if (mode == "Player2Turn" && inHand[2])
		{
			cout << "Player 2 , elMafrood Yelem :  " << Calls[2] << " Lammet : " << Lammat[2] << endl;

			wara2a = Ai.CardDes(DecksOfCards[2], DecksOfCards[3], OnGround, Trump, Players[2], status, Lammat[2], Calls[2], Halemm[2]);
			OnGround.push_back(wara2a);
			GroundCards[OnGround.size() - 1].TypeAndValue.first = wara2a.second;
			GroundCards[OnGround.size() - 1].TypeAndValue.second = wara2a.first;
			cout << "Player 2 Hayel3ab : " << wara2a.first << " " << wara2a.second << endl;
			for (int v = 0; v < 13; v++)
			{
				if (Ai_2_Card[v].TypeAndValue.first == wara2a.second && Ai_2_Card[v].TypeAndValue.second == wara2a.first)
				{
					m = v;
					break;
				}
			}
			mode = "Player2Playing";
		}

		if (mode == "Player2Playing")
		{
			Ai_2_Card[m].shape.setSize(Vector2f(75, 108));
			if (Ai_2_Card[m].shape.getPosition().x < 400)
			{
				Ai_2_Card[m].shape.move(1, 0);
			}
			else
			{
				GroundCards[OnGround.size() - 1].shape.setPosition(Ai_2_Card[m].shape.getPosition());
				mode = "UserTurn";
				inHand[3] = true;
				temppos[2] = m;
				m = -1;
				if (OnGround.size() == 4)
				{
					mode = "PlayEnding";
				}
			}


		}

		if (mode == "NextPlay")
		{
			for (int i = 0; i < 4; i++)
			{
				inHand[i] = InHand[i];
			}

			if (inHand[0])
			{
				mode = "Player0Turn";
			}
			if (inHand[1])
			{
				mode = "Player1Turn";
			}
			if (inHand[2])
			{
				mode = "Player2Turn";
			}
			if (inHand[3])
			{
				mode = "UserTurn";
			}
			OnGround.clear();

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < Players[i].size(); j++)
				{
					cout << Players[i][j].first << " " << Players[i][j].second << endl;
				}
				cout << endl;
				cout << endl;
			}

		}


		
		if (ibuttonAutoHover(ScoreBoardWindow,window))
		{
			Text username;
			username.Bold;
			username.setFont(font);
			username.setFillColor(Color::White);
			username.setCharacterSize(15);
			username.setPosition(40, 50);
			username.setString(UserName);
			vector<vector<string>> ScoreSheet;
			RenderWindow ScoreBoard(VideoMode(700,600), "Estimation", Style::Close);
			Sprite BackGroundSB;
			Texture SBbase;
			SBbase.loadFromFile("CardsTextures/ScoreBoard.jpg");
			BackGroundSB.setTexture(SBbase);
			BackGroundSB.setPosition(0, 0);
				ifstream x("Scores.txt");
				
				vector<Text> ToBeWritten;
				while (x.peek() != -1)
				{
					vector<string> y;
					string z;
					while (getline(x, z, ' '))
					{
						y.push_back(z);

					}
					ScoreSheet.push_back(y);
				}
				x.close();

				for (int i = 0; i < ScoreSheet.size(); i++)
				{
					string temp="";
					Text x;
					x.setFont(font);
					x.setCharacterSize(20);
					for (int j = 0; j < ScoreSheet[i].size(); j++)
					{
						temp += ScoreSheet[i][j];
						temp += "                      ";
					}
					x.setString(temp);
					x.setFillColor(Color::White);
					ToBeWritten.push_back(x);

				}
				int Xpos = 46,Ypos=75;
				for (int i = 0; i < ToBeWritten.size(); i++)
				{
					ToBeWritten[i].setPosition(Vector2f(46, Ypos+(i*20)));
				}

			while (ScoreBoard.isOpen())
			{
				Event E;
				while (ScoreBoard.pollEvent(E))
				{
					switch (E.type)
					{
					case Event::Closed:
						ScoreBoard.close();
						break;
					default:
						break;
					}
				}

				
				if (LMB())
				{
					cout << Mouse::getPosition(ScoreBoard).x << " " << Mouse::getPosition(ScoreBoard).y << endl;
					hang();
				}
				

				ScoreBoard.clear();
				ScoreBoard.draw(BackGroundSB);
				ScoreBoard.draw(username);
				for (int i = 0; i < ToBeWritten.size(); i++)
					ScoreBoard.draw(ToBeWritten[i]);
				ScoreBoard.display();


			}
		}



		window.clear();
		window.draw(BackGround);
		window.draw(CardsHolder);
		window.draw(Avatar1);
		window.draw(Avatar2);
		window.draw(Avatar3);
		window.draw(shdc);
		window.draw(ScoreBoardWindow.shape);
		if (Trump != "")
		{
		int x = Ai.switchString(Trump);
		window.draw(TrumpPhoto[x]);
		}
		if (status != "")
		{
			if (status == "Over")
				StatusWriter.setString(" + " + to_string(abs(TotalLammat - 13)));
			else
				StatusWriter.setString(" - " + to_string(abs(TotalLammat - 13)));

			window.draw(StatusWriter);
		}
		for (int i = 0; i < 4; i++)
		{

			window.draw(currentCalls[i]);
			window.draw(LammetKam[i]);
		}
		if (mode == "PlayEndingAnimation")
		{
			for (int i = 0; i < OnGround.size(); i++)
			{
				window.draw(GroundCards[i].shape);
			}
			for (int i = 0; i < 13; i++)
				window.draw(Card[i].shape);
		}
		else
		{

			for (int i = 0; i < 13; i++)
			{
				window.draw(Card[i].shape);
				window.draw(Ai_0_Card[i].shape);
				window.draw(Ai_1_Card[i].shape);
				window.draw(Ai_2_Card[i].shape);
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
	ib.button.upperLimit.x = ib.button.lowerLimit.x + ib.shape.getSize().x - 15;
	ib.button.upperLimit.y = ib.button.lowerLimit.y + ib.shape.getSize().y;
}
void GUI::RectButtonAssign2(interactiveButton &ib)
{
	ib.button.lowerLimit = ib.shape.getPosition();
	ib.button.upperLimit.x = ib.button.lowerLimit.x + ib.shape.getSize().x;
	ib.button.upperLimit.y = ib.button.lowerLimit.y + ib.shape.getSize().y;
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
	if (original.x<AButton.upperLimit.x&& original.x>AButton.lowerLimit.x && original.y<AButton.upperLimit.y && original.y>AButton.lowerLimit.y)
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

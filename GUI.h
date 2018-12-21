#pragma once
#include "Includes.h"
class Button
{
public:
	Vector2f upperLimit, lowerLimit;
};
class interactiveButton
{
public:
	RectangleShape shape;
	Texture normal;
	Texture clicked;
	Button button;
	pair<string, int> TypeAndValue;
	void Reset()
	{
		button.lowerLimit = Vector2f(0, 0);
		button.upperLimit = Vector2f(0, 0);
	}
};
class GUI
{
public:
	int Caller = -1;
	GUI();
	void ProgramRun(RenderWindow &window, interactiveButton Card[14], interactiveButton Ai_0_Card[14], interactiveButton Ai_1_Card[14], interactiveButton Ai_2_Card[14], Sprite BackGround, Sprite CardsHolder, vector<pair<int, string >> &Bids, vector < vector < pair<int, string>>> Players, Texture Spades[15], Texture Hearts[15], Texture Diamonds[15], Texture Clubs[15]);
	void SetTextures(Texture Spades[15], Texture Hearts[15], Texture Diamonds[15], Texture Clubs[15], Texture &Background, Texture &CardsHolder);
	void PlayerCardsSetup(vector < pair<int, string>> Players, interactiveButton Card[14], Texture Spades[15], Texture Hearts[15], Texture Diamonds[15], Texture Clubs[15]);
	void normalize(interactiveButton &ib);
	void RectButtonAssign(interactiveButton &ib);
	bool isButtonHovered(interactiveButton ib, RenderWindow &window);
	bool LMB();
	bool ibuttonAutoHover(interactiveButton &ib, sf::RenderWindow &window);
	void GameDesignSetUp(Texture &avatar1, Sprite &Avatar1, Texture &avatar2, Sprite &Avatar2, Texture &avatar3, Sprite &Avatar3, Texture &SHDC, Sprite &shdc, Texture &CallingWindow, Sprite &callingwindow, Sprite &callingwindow2, interactiveButton CallNumber[14], interactiveButton CallColor[4], interactiveButton Choice[2]);
	void Ai_0_CardsSetup(vector < pair<int, string>> Players, interactiveButton Card[14], Texture Spades[15], Texture Hearts[15], Texture Diamonds[15], Texture Clubs[15]);
	void Ai_1_CardsSetup(vector < pair<int, string>> Players, interactiveButton Card[14], Texture Spades[15], Texture Hearts[15], Texture Diamonds[15], Texture Clubs[15]);
	void Ai_2_CardsSetup(vector < pair<int, string>> Players, interactiveButton Card[14], Texture Spades[15], Texture Hearts[15], Texture Diamonds[15], Texture Clubs[15]);
	string TrumpDes(vector<pair<int, string>> Bids, int &Caller, pair<int, string>UserBid);

	void hang();

	~GUI();
};


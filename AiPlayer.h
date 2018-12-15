#pragma once
#include "Includes.h"
using namespace std;
class AiPlayer
{

public:

	AiPlayer();

	pair<int, string> BidCall(vector < pair<int, string>> pc);
	pair<int, string> MainCall(pair<int, string> &Bidcall, vector < pair<int, string>> &pc);
	int FinalCall(string trump, vector<pair<int, string>> pc, int Caller, int TotalLammat, vector<pair<int, int>> &Lammat);
	pair<int, string> CardDes(vector < pair<int, string>> &CardDeck, vector < pair<int, string>> GlobalDeck, vector<pair<int, string>> CardsOnGround, string Trump, vector < pair<int, string>>&pc, string Status, int &Lammat, int FinalCall, vector<pair<int, int>>&lammaty);
	void PlayGround(vector<pair<int, string>> &CardOnGround, string Trump, vector<int> &KolElLammat,vector<bool>&inHand, vector<int> &lammat);
	//bool  dashCall(vector < pair<int, string>> pc);
	~AiPlayer();
};

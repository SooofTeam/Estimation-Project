#pragma once
#include "Includes.h"
using namespace std;
class AiPlayer
{
	
public:

	AiPlayer();
	
	pair<int, string> BidCall(vector < pair<int, string>> pc);
	pair<int, string> MainCall(pair<int, string> &Bidcall, vector < pair<int, string>> &pc);
	int FinalCall(string trump, vector<pair<int, string>> pc,int Caller,int TotalLammat, vector<pair<int, int>> &Lammat);
	pair<int, string> CardDes(vector < pair<int, string>> CardDeck , pair<int,string> CurrentGround , string Trump , vector < pair<int, string>>pc , string Status , int Lammat , int FinalCall);
	void PlayGround(vector<pair<int, string>> CardOnGround, string Trump,vector<int> &KolElLammat);
	~AiPlayer();
};


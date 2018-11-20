#pragma once
#include "Includes.h"
using namespace std;
class AiPlayer
{
	
public:
	AiPlayer();
	pair<int, string> BidCall(vector < pair<int, string>> pc);
	pair<int, string> MainCall(pair<int, string> &Bidcall, vector < pair<int, string>> &pc);


	~AiPlayer();
};


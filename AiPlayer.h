#pragma once
#include "Includes.h"
using namespace std;
class AiPlayer
{
	
public:
	AiPlayer();
	pair<int, string> Bid(vector < pair<string, int>> pc);
	~AiPlayer();
};


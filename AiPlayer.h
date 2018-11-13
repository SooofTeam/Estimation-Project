#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
class AiPlayer
{
	
public:
	AiPlayer();
	pair<int, string> Bid(vector < pair<string, int>> pc);
	~AiPlayer();
};


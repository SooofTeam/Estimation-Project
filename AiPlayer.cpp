
#include "AiPlayer.h"


AiPlayer::AiPlayer()
{
}

pair<int, string>AiPlayer::Bid(vector < pair<string, int>> pc)
{
	vector<int>comp;
	vector<pair<int, string>>Counter;
	
	

	for (int i = 14; i >= 2; i--)
		comp.push_back(i);

	vector <vector <int>> Shapes(4);
	
	for (auto i : pc) {

		if (i.first == "Spades")
		{
			Shapes[0].push_back(i.second);
		}
		if (i.first == "Hearts")
		{
			Shapes[1].push_back(i.second);
		}
		if (i.first == "Diamonds")
		{
			Shapes[2].push_back(i.second);
		}

		if (i.first == "Clubs")
		{
			Shapes[3].push_back(i.second);
		}
	}
	int c = 0;
	for (auto &i : Shapes) {
		
		priority_queue<int> des;
		priority_queue<int, vector<int>, greater<int>> asc;

		bool ary[15] = {};
		memset(ary, 0, sizeof(ary));
		for (auto j : i)
		{
			asc.push(j);
			ary[j] = 1;
		}

		for (int h = 2; h <= 14; h++)
		{
			if (!ary[h])
				des.push(h);
		}


		while (!asc.empty())
		{
			if (asc.top() < des.top())
			{
				des.pop();
				asc.pop();
			}
			else
			{
				break;
			}

		}
		string a;
		if (c == 0)
			a = "Spades";
		else if (c == 1)
			a = "Hearts";
		else if (c == 2)
			a = "Diamonds";
		else
			a = "Clubs";
		Counter.push_back({ asc.size(),a });
		c++;
	}
	sort(Counter.begin(), Counter.end());



	return Counter.back();
}

AiPlayer::~AiPlayer()
{
}

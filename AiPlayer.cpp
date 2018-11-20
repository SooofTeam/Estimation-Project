
#include "AiPlayer.h"


AiPlayer::AiPlayer()
{
}

pair<int, string> AiPlayer::BidCall(vector < pair<int,string>> pc)
{
	vector<int>comp;
	vector<pair<int, string>>Counter;
	
	

	for (int i = 14; i >= 2; i--)
		comp.push_back(i);

	vector <vector <int>> Shapes(4);
	
	for (auto i : pc) {

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
			a = "EClubs";

		Counter.push_back({ asc.size(),a });
		c++;
	}

	sort(Counter.begin(), Counter.end());


	return Counter.back();
}
pair<int, string> AiPlayer::MainCall(pair<int ,string> &Bidcall, vector < pair<int, string>> &pc)
{
	vector<int>comp;
	int Counter=0;

	vector <vector <int>> Shapes(4);

	for (auto i : pc) 
	{
		if (i.second == Bidcall.second)
			continue;

		if (i.second == "Spades")
		{
			Shapes[0].push_back(i.first);
		}
		if (i.second== "Hearts")
		{
			Shapes[1].push_back(i.first);
		}
		if (i.second== "Diamonds")
		{
			Shapes[2].push_back(i.first);
		}

		if (i.second == "EClubs")
		{
			Shapes[3].push_back(i.first);
		}
	}

	for (auto &i : Shapes)
		sort(i.rbegin(), i.rend());


	for (auto &i:Shapes)
	{
		
	int counter = 0;

		if (i.size() >= 3)
		{

			if (i[0] == 14 && i[1]==13)
				counter+=2;
			else if (i[0] == 14)
				counter++;
			else if (i[0] == 13)
				counter++;
		}
		else if (i.size() == 2)
		{
			if (i[0] == 14 && i[1] == 13)
				counter += 2;
			else if (i[0] == 14)
				counter++;
			else if (i[0] == 13)
				counter++;
		}
		else if (i.size() == 1)
		{
			if (i[0] == 14)
				counter++;
		}

		Counter+=counter;
	}
	pair<int, string> Call;
	Call.first = Counter+Bidcall.first;
	Call.second = Bidcall.second;
	return Call;


}


AiPlayer::~AiPlayer()
{
}

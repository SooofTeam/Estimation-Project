
#include "AiPlayer.h"



int main()
{

		string Colors[4] = { "Spades","Hearts","Diamonds" ,"Clubs" };
		vector < pair<string, int>> Cards;
		vector < vector < pair<string, int>>> Players(4);


		for (int i = 0; i < 4; i++)
		{
			for (int j = 2; j <= 14; j++)
			{
				Cards.push_back({ Colors[i], j });
			}
		}

		random_shuffle(Cards.begin(), Cards.end());

		int c = 0;
		for (int i = 0; i < 4; i++)
		{
			int b = 0;
			for (int j = c; b < 13; j++, b++)
			{
				Players[i].push_back(Cards[j]);
			}
			c += 13;
		}

		for (auto i : Players)
		{
			for (auto j : i)
				cout << j.first << " " << j.second << endl;
			cout << endl;

		}


		AiPlayer Ai;
		vector<pair<int, string >> Bids;

		for (int i = 0; i < 3; i++)
		{
			Bids.push_back(Ai.Bid(Players[i]));
		}

		for (auto i : Bids)
		{
			cout << i.first << " " << i.second << endl;
		}
		system("pause");
		return 0;
}


#include "AiPlayer.h"


AiPlayer::AiPlayer()
{
}

int AiPlayer::FinalCall(string trump, vector<pair<int, string>> pc, int Caller, int TotalLammat, vector<pair<int, int>> &Lammat)
{
	int Counter = 0;
	int col;
	if (trump == "Spades")col = 0;
	if (trump == "Hearts")col = 1;
	if (trump == "Diamonds")col = 2;
	if (trump == "EClubs")col = 3;

	vector <vector <int>> Shapes(4);
	for (auto i : pc)
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

	for (auto &i : Shapes)
		sort(i.rbegin(), i.rend());

	int ck = 0;
	for (auto &i : Shapes)
	{

		int counter = 0;
		if (i == Shapes[col]) {
			if (i.size() >= 3)
			{

				if (i[0] == 14 && i[1] == 13 && i[2] == 12)
				{
					counter += i.size();
					for (int b = 0; b < i.size(); b++)
					{

						Lammat.push_back(make_pair(i[b], ck));
					}

				}

				else if (i.size() >= 5)
				{
					counter += i.size() - 4;
					Lammat.push_back(make_pair(i[i.size() - 1], ck));
					                                        


					for (auto j : i)
					{
						if (j >= 11)
						{
							Lammat.push_back(make_pair(j, ck));
							counter++;
						}
					}
				}
			}
			else if (i.size() == 2)
			{
				if (i[0] == 14 && (i[1] == 13 || i[1] == 12)) {
					Lammat.push_back(make_pair(14, ck));
					Lammat.push_back(make_pair(i[1], ck));
					counter += 2;
				}

				else if (i[0] >= 12) {
					Lammat.push_back(make_pair(i[0], ck));
					counter++;
				}
			}
				else if (i.size() == 1)
				{
					if (i[0] == 14) {
						Lammat.push_back(make_pair(14, ck));
						counter++;
					}
				}
			
			Counter += counter;
			ck++;
			continue;
		}


		//ghghghghhggghghgh

		if (i.size() >= 3)
		{

			if (i[0] == 14 && i[1] == 13) {
				Lammat.push_back(make_pair(14, ck));
				Lammat.push_back(make_pair(13, ck));
				counter += 2;
			}
			else if (i[0] == 14 || i[0] == 13) {
				Lammat.push_back(make_pair(i[0], ck));
				counter++;
			}
		}
			else if (i.size() == 2)
			{
				if (i[0] == 14 && i[1] == 13)
				{
					Lammat.push_back(make_pair(14, ck));
					Lammat.push_back(make_pair(13, ck));
					counter += 2;
				}
				else if (i[0] == 14 || i[0] == 13) {
					Lammat.push_back(make_pair(i[0], ck));
					counter++;
				}
			}
				else if (i.size() == 1)
				{
					if (i[0] == 14) {
						Lammat.push_back(make_pair(14, ck));
						counter++;
					}
				}

				Counter += counter;
				ck++;

			if (Caller == -1)
			{
				if (Counter + TotalLammat == 13)
					Counter--;
			}



	}

	/*	cout << "Lamamty : " << endl;
	for (int v = 0; v < Lammat.size(); v++)
	{
		cout << v << " ";

		if (Lammat[v].second == 0)
			cout << Lammat[v].first << " " << "Spades" << endl;
		if (Lammat[v].second == 1)
			cout << Lammat[v].first << " " << "Hearts" << endl;
		if (Lammat[v].second == 2)
			cout << Lammat[v].first << " " << "Diamonds" << endl;
		if (Lammat[v].second == 3)
			cout << Lammat[v].first << " " << "Clubs" << endl;
		cout << endl;

	}*/
			return Counter;
}
void AiPlayer::PlayGround(vector<pair<int, string>> CardOnGround, string Trump, vector<int> &KolElLammat)
{
	
}

pair<int, string> AiPlayer::CardDes(vector < pair<int, string>> CardDeck, pair<int, string> CurrentGround, string Trump, vector < pair<int, string>>pc, string Status, int Lammat, int FinalCall)
{

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
	for(auto &i:Shapes)
		sort(i.rbegin(), i.rend());
	
	/*int c = 0;
	for (auto &i : Shapes)
	{
		if (c == 0)cout << "Spades:" << endl;
		if (c == 1)cout << "Hearts:" << endl;
		if (c == 2)cout << "Diamonds:" << endl;
		if (c == 3)cout << "Clubs:" << endl;
		for (auto j : i)
		{
			cout << j << " ";
		}
		c++;
	}*/

	if (Status == "Over")
	{

	}


		


	
	return pc[0];
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
			a = "Clubs";

		Counter.push_back({ asc.size(),a });
		c++;
	}

	sort(Counter.begin(), Counter.end());

	
	return Counter.back();
}
pair<int, string> AiPlayer::MainCall(pair<int ,string> &Bidcall,vector < pair<int, string>> &pc)
{
	vector<int>comp;
	int Counter=0;

	vector <vector <int>> Shapes(4);
	if (Bidcall.second == "Clubs")
		Bidcall.second = "EClubs";

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

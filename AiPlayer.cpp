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



					for (auto j : i)
					{
						if (j >= 11)
						{
							Lammat.push_back(make_pair(j, ck));
							counter++;
						}
					}
					Lammat.push_back(make_pair(i[i.size() - 1], ck));
				}
				else
				{
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


	}


	if (Caller == -1)
	{
		if (Counter + TotalLammat == 13)
			Counter--;
	}

	/*cout << "Lamamty : " << endl;
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

pair<int, string> AiPlayer::CardDes(vector < pair<int, string>> &CardDeck, vector<pair<int, string>> CardsOnGround, string Trump, vector < pair<int, string>>pc, string Status, int &Lammat, int FinalCall, vector<pair<int, int>>&lammaty)
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
	for (auto &i : Shapes)
		sort(i.begin(), i.end());

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
	pair<int, string> wara2a;
	for (int i = 0; i < Shapes.size(); i++) {
		for (int j = 0; j < Shapes[i].size(); j++) {
			CardDeck[(i * 13) + Shapes[i][j] - 2].first = -2;
		}
	}

	if (Status == "Over")
	{
		cout << "OVER ";
		if (Lammat != FinalCall)
		{

			if (CardsOnGround.empty()) {
				cout << "8alat";
				bool LammatFelTrump = true, Hal3abDy = true;
				int tuna;
				string tunas, sushi;
				if (Trump == "Spades") { tuna = 0; tunas = "Spades"; }
				if (Trump == "Hearts") { tuna = 1; tunas = "Hearts"; }
				if (Trump == "Diamonds") { tuna = 2; tunas = "Diamonds"; }
				if (Trump == "EClubs") { tuna = 3; tunas = "EClubs"; }
				for (int i = 0; i < lammaty.size(); i++) {
					if (lammaty[i].second != tuna) {
						LammatFelTrump = false;
						if (lammaty[i].second == 0)sushi = "Spades";
						if (lammaty[i].second == 1)sushi = "Hearts";
						if (lammaty[i].second == 2)sushi = "Diamonds";
						if (lammaty[i].second == 3)sushi = "EClubs";
						if (lammaty[i].first == 14) {
							wara2a.first = 14;
							wara2a.second = sushi;
							for (int jk = 0; jk < Shapes[lammaty[i].second].size(); jk++) {
								if (Shapes[lammaty[i].second][jk] == wara2a.first) {
									Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin() + jk); break;
								}
							}
							lammaty.erase(lammaty.begin() + i);
							return wara2a;
						}

					}
				}
				for (int i = 0; i < lammaty.size(); i++) {
					if (lammaty[i].second != tuna) {
						LammatFelTrump = false;
						if (lammaty[i].second == 0)sushi = "Spades";
						if (lammaty[i].second == 1)sushi = "Hearts";
						if (lammaty[i].second == 2)sushi = "Diamonds";
						if (lammaty[i].second == 3)sushi = "EClubs";
						if (lammaty[i].first == 13) {
							if (CardDeck[((lammaty[i].second + 1) * 13) - 1].first == 14) {
								if (Shapes[lammaty[i].second].size() > 2) {
									wara2a.first = Shapes[lammaty[i].second][Shapes[lammaty[i].second].size() / 2];
									wara2a.second = sushi;
									Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin() + Shapes[lammaty[i].second].size() / 2);
								}
								else {
									wara2a.first = Shapes[lammaty[i].second][0];
									wara2a.second = sushi;
									Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin());
								}
							}
							else {
								wara2a.first = 13;
								wara2a.second = sushi;
								for (int jk = 0; jk < Shapes[lammaty[i].second].size(); jk++) {
									if (Shapes[lammaty[i].second][jk] == wara2a.first) {
										Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin() + jk); break;
									}
								}
								lammaty.erase(lammaty.begin() + i);
							}
							return wara2a;
						}
					}
				}
				for (int i = 0; (i < lammaty.size()) && LammatFelTrump; i++)
				{
					if (Trump == "Spades") { tuna = 0; tunas = "Spades"; }
					if (Trump == "Hearts") { tuna = 1; tunas = "Hearts"; }
					if (Trump == "Diamonds") { tuna = 2; tunas = "Diamonds"; }
					if (Trump == "EClubs") { tuna = 3; tunas = "EClubs"; }

					for (int ik = ((tuna + 1) * 13) - 1; ik > (((tuna + 1) * 13) - 1) - 13; ik--)
					{
						if (lammaty[i].first < CardDeck[ik].first)
						{
							Hal3abDy = false;
							break;
						}
					}

					if (!Hal3abDy)
					{
						if (Shapes[lammaty[i].second].size() > 2) {
							for (int kk = 0; kk < lammaty.size(); kk++) {
								if (lammaty[i].first == Shapes[lammaty[i].second][Shapes[lammaty[i].second].size() / 2]) {
									wara2a.first = Shapes[lammaty[i].second][Shapes[lammaty[i].second].size() - 1];
									Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin());
									break;
								}
								else if (kk == lammaty.size() - 1) {
									wara2a.first = Shapes[lammaty[i].second][Shapes[lammaty[i].second].size() / 2];
									Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin() + Shapes[lammaty[i].second].size() / 2);
								}
							}
							wara2a.second = tunas;
						}
						else {
							wara2a.first = Shapes[lammaty[i].second][0];
							wara2a.second = tunas;
							Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin());
						}
					}
					else
					{
						wara2a.first = lammaty[i].first;
						wara2a.second = tunas;
						Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin() + Shapes[tuna].size() - 1);
						lammaty.erase(lammaty.begin() + i);
					}

				}

			}

			else if (!CardsOnGround.empty()) {

				for (int j = 0; j < CardsOnGround.size(); j++) {
					for (int p = 0; p < CardDeck.size(); p++) {
						if (CardsOnGround[j] == CardDeck[p]) {
							CardDeck[p].first = -1;
						}
					}
				}
				int gro;
				string gros;

				if (CardsOnGround[0].second == "Spades") {
					gro = 0; gros = "Spades";
				}
				if (CardsOnGround[0].second == "Hearts") {
					gro = 1; gros = "Hearts";
				}
				if (CardsOnGround[0].second == "Diamonds") {
					gro = 2; gros = "Diamonds";
				}
				if (CardsOnGround[0].second == "EClubs") {
					gro = 3; gros = "EClubs";
				}
				int maxi = -1;
				bool haseb = 0;
				for (int kl = 1; kl < CardsOnGround.size(); kl++) {
					if (CardsOnGround[kl].second == Trump && CardsOnGround[kl].second != CardsOnGround[0].second &&CardsOnGround[kl].first > maxi) {
						maxi = CardsOnGround[kl].first;
						haseb = 1;
					}
				}
				bool biggeT = 0;
				if (Shapes[gro].size() != 0) {
					for (int i = 0; i < Shapes[gro].size(); i++) {
						for (int x = 0; x < lammaty.size(); x++) {
							if (gro == lammaty[x].second) {
								for (int ik = ((gro + 1) * 13) - 1; ik >= gro * 13; ik--) {
									for (int hk = 0; hk < CardsOnGround.size(); hk++) {
										if (lammaty[x].first < CardsOnGround[hk].first) {
											biggeT = 1;
										}
									}
									if (biggeT) {

										wara2a.first = Shapes[gro][0];
										Shapes[gro].erase(Shapes[gro].begin() + 0);
										CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
										wara2a.second = gros;
										return wara2a;

									}
									else if (CardDeck[ik].second == gros && (CardDeck[ik].first > lammaty[x].first || haseb)) {

										if (Shapes[gro].size() > 2) {

											wara2a.first = Shapes[gro][Shapes[gro].size() / 2];
											Shapes[gro].erase(Shapes[gro].begin() + Shapes[gro].size() / 2);
											CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
											wara2a.second = gros;
											return wara2a;
										}
										else if (Shapes[gro].size() == 2) {

											wara2a.first = Shapes[gro][0];
											Shapes[gro].erase(Shapes[gro].begin() + 1);
											CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
											wara2a.second = gros;
											return wara2a;
										}
										else {

											wara2a.first = Shapes[gro][0];
											Shapes[gro].erase(Shapes[gro].begin());
											CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
											wara2a.second = gros;
											return wara2a;
										}

									}
									else {
										wara2a.first = lammaty[x].first;
										lammaty.erase(lammaty.begin() + x);
										CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
										//	Lammat++;
										for (int jk = 0; jk < Shapes[gro].size(); jk++) {
											if (Shapes[gro][jk] == wara2a.first) {
												Shapes[gro].erase(Shapes[gro].begin() + jk); break;
											}
											CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
											wara2a.second = gros;
											return wara2a;
										}
									}


								}
							}
							else if (x == lammaty.size() - 1) {
								wara2a.first = Shapes[gro][0];
								wara2a.second = gros;
								return wara2a;
							}
							else continue;

						}
					}

				}
				else {
					int tuna, index;
					bool el3ab = true;
					if (gros != Trump) {

						if (Trump == "Spades")tuna = 0;
						if (Trump == "Hearts")tuna = 1;
						if (Trump == "Diamonds")tuna = 2;
						if (Trump == "EClubs")tuna = 3;
						for (int i = 0; i < Shapes[tuna].size(); i++) {
							for (int ik = 0; ik < CardsOnGround.size(); ik++) {
								if (CardsOnGround[ik].second == Trump && Shapes[tuna][i] < CardsOnGround[ik].first) {
									el3ab = false;
									break;
								}
								else if (CardsOnGround[ik].second == Trump && Shapes[tuna][i] > CardsOnGround[ik].first) {
									el3ab = true;
									break;
								}
								if (el3ab&&ik == CardsOnGround.size() - 1) {
									index = -1;
								}


							}
							if (index == -1) { index = i; break; }
						}
						if (el3ab) {
							wara2a.first = Shapes[tuna][index];
							wara2a.second = Trump;
							Shapes[tuna].erase(Shapes[tuna].begin() + index);
							CardDeck[(tuna * 13) + wara2a.first - 2].first = -1;
							//	Lammat++;
						}
						else {
							int maxi = -1, indexi;
							for (int i = 0; i < Shapes.size(); i++) {
								if (i != gro && i != tuna) {
									if (maxi < Shapes[i].size()) {
										maxi = Shapes[i].size();
										indexi = i;
									}
								}
							}
							wara2a.first = Shapes[indexi][0];
							if (indexi == 0) { wara2a.second = "Spades"; }
							if (indexi == 1) { wara2a.second = "Hearts"; }
							if (indexi == 2) { wara2a.second = "Diamonds"; }
							if (indexi == 3) { wara2a.second = "EClubs"; }
							return wara2a;
							Shapes[indexi].erase(Shapes[indexi].begin() + 0);
							CardDeck[(indexi * 13) + wara2a.first - 2].first = -1;

						}
					}
				}
			}
		}
		else
		{
			if (CardsOnGround.empty())
			{
				vector<string>sushi(4);
				sushi[0] = "Spades";
				sushi[0] = "Hearts";
				sushi[0] = "Diamonds";
				sushi[0] = "EClubs";
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < Shapes[i].size(); j++) {
						for (int jk = ((i + 1) * 13) - 1; jk > i * 13; jk--) {
							if (CardDeck[jk].first > Shapes[i][j]) {
								wara2a.first = Shapes[i][j];
								wara2a.second = sushi[i];
								CardDeck[jk].first = -1;
								return wara2a;
							}
						}
					}
				}
			}

			else if (!CardsOnGround.empty())
			{
				for (int j = 0; j < CardsOnGround.size(); j++) {
					for (int p = 0; p < CardDeck.size(); p++) {
						if (CardsOnGround[j] == CardDeck[p]) {
							CardDeck[p].first = -1;
						}
					}
				}
				int gro;
				string gros;
				bool NotOnGround = true, NotInDeck = true;
				pair <int, int> mxOnGround;
				if (CardsOnGround[0].second == "Spades") {
					gro = 0; gros = "Spades";
				}
				if (CardsOnGround[0].second == "Hearts") {
					gro = 1; gros = "Hearts";
				}
				if (CardsOnGround[0].second == "Diamonds") {
					gro = 2; gros = "Diamonds";
				}
				if (CardsOnGround[0].second == "EClubs") {
					gro = 3; gros = "EClubs";
				}

				mxOnGround.first = CardsOnGround[0].first;
				mxOnGround.second = gro;

				for (int v = 1; v < CardsOnGround.size(); v++)
				{
					if (CardsOnGround[v].first > mxOnGround.first)
					{
						mxOnGround.first = CardsOnGround[v].first;
					}
				}

				for (int i = 0; i < Shapes[gro].size(); i++)
				{
					if (Shapes[gro][i] < mxOnGround.first)
					{
						wara2a.first = Shapes[gro][i];
						wara2a.second = gro;
						Shapes[gro].erase(Shapes[gro].begin() + i);
						NotOnGround = false;
					}
					else
						break;
				}
				if (!NotOnGround)return wara2a;
				else if (NotOnGround)
				{
					for (int i = 0; i < Shapes[gro].size(); i++)
					{
						for (int ik = ((gro + 1) * 13) - 1; i >= ((gro) * 13); ik--)
						{
							if (CardDeck[ik].second == gros && CardDeck[ik].first > Shapes[gro][i])
							{
								wara2a.first = Shapes[gro][i];
								wara2a.second = gro;
								Shapes[gro].erase(Shapes[gro].begin() + i);
								NotInDeck = false;
								break;
							}
						}
					}
				}
				if (!NotInDeck)return wara2a;
				else if (NotInDeck)
				{
					wara2a.first = Shapes[gro][0];
					wara2a.second = gros;
					Shapes[gro].erase(Shapes[gro].begin());
					return wara2a;
				}

			}
		}

	}
	else if (Status == "Under")
	{

	}

	return pc[0];
}

pair<int, string> AiPlayer::BidCall(vector < pair<int, string>> pc)
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
pair<int, string> AiPlayer::MainCall(pair<int, string> &Bidcall, vector < pair<int, string>> &pc)
{
	vector<int>comp;
	int Counter = 0;

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


	for (auto &i : Shapes)
	{

		int counter = 0;

		if (i.size() >= 3)
		{

			if (i[0] == 14 && i[1] == 13)
				counter += 2;
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

		Counter += counter;
	}
	pair<int, string> Call;
	Call.first = Counter + Bidcall.first;
	Call.second = Bidcall.second;

	return Call;




}

/*bool  AiPlayer::dashCall(vector < pair<int, string>> pc)
{
vector<int>comp;
vector<pair<int, string>>Counter;
//counters to know the number of cards of each type
int counterS = 0;
int counterH = 0;
int counterD = 0;
int counterE = 0;
//the counters to know the number of cards less than 4 points or between 5 && 8
int s = 0;
int h = 0;
int d = 0;
int e = 0;
bool dashcall = true;
for (int i = 14; i >= 2; i--)
comp.push_back(i);
vector <vector <int>> Shapes(4);
for (auto i : pc)
{
if (i.second == "Spades")
{
Shapes[0].push_back(i.first);
counterS++;
}
if (i.second == "Hearts")
{
Shapes[1].push_back(i.first);
counterH++;
}
if (i.second == "Diamonds")
{
Shapes[2].push_back(i.first);
counterD++;
}
if (i.second == "EClubs")
{
Shapes[3].push_back(i.first);
counterE++;
}
}
for (int j = 0; j < counterS; j++)
if ((Shapes[0][j] <= 4) || (Shapes[0][j] >= 5 && Shapes[0][j] <= 8))s++;
for (int j = 0; j < counterH; j++)
if ((Shapes[1][j] <= 4) || (Shapes[1][j] >= 5 && Shapes[1][j] <= 8))h++;
for (int j = 0; j < counterD; j++)
if ((Shapes[2][j] <= 4) || (Shapes[2][j] >= 5 && Shapes[2][j] <= 8))d++;
for (int j = 0; j < counterE; j++)
if ((Shapes[3][j] <= 4) || (Shapes[3][j] >= 5 && Shapes[3][j] <= 8))e++;
if (e >= 2 && d >= 2 && h >= 2 && s >= 2)
return dashcall;
else
return !dashcall;
}*/



AiPlayer::~AiPlayer()
{
}

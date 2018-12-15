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
void AiPlayer::PlayGround(vector<pair<int, string>> &CardOnGround, string Trump, vector<int> &KolElLammat, vector<bool>&inHand,vector<int> &lammat)
{
	int assign[4] = { -1,-1,-1,-1 };

	cout << endl;
	//int maxi = CardOnGround[0].first;
	bool c=1,t=0,m=1;
	int mod, it = 0,ity=0;
	//	for (int i = 0; i < 4; i++)cout << inHand[i] << " ";
	while (c) {
		if (ity == 3) {
			c = 0;
		}
		if (inHand[0])
		{
			for (int i = 0; i < 4; i++)
			{
				assign[i] = i;
			}
			break;
		}
		if (m) {
			if (inHand[it]) {
				mod = it;
				t = 1;
				m = 0;
			}
		}
		if (t) {
			assign[ity] = mod;
			ity++;
			mod = (mod + 1) % 4;
		}
			it++;
	}
	

	int maxi = CardOnGround[0].first,maxT=-1,iTrump=-1;
	it = 0;
	
	for (int i = 1; i < 4; i++) {
		if (CardOnGround[i].first > maxi&&CardOnGround[i].second==CardOnGround[0].second) {
			maxi = CardOnGround[i].first;
			it = i;
		}
	}

	for (int i = 1; i < 4; i++) {
		if (CardOnGround[i].second == Trump&&CardOnGround[i].first>maxT&&CardOnGround[i].second!=CardOnGround[0].second) {
			maxT = CardOnGround[i].first;
			iTrump = i;
		}
	}

	if (iTrump != -1) {
		inHand = { 0,0,0,0 };
		inHand[assign[iTrump]] = 1;
		lammat[assign[iTrump]]++;
	}
	else {
		//cout << it << endl;
		//cout << assign[it] << " " << endl;
		inHand = { 0,0,0,0 };
		inHand[assign[it]] = 1;
		lammat[assign[it]]++;
	}


}

pair<int, string> AiPlayer::CardDes(vector < pair<int, string>> &CardDeck, vector < pair<int, string>> GlobalDeck, vector<pair<int, string>> CardsOnGround, string Trump, vector < pair<int, string>>&pc, string Status, int &Lammat, int FinalCall, vector<pair<int, int>>&lammaty)
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
		//cout << "OVER ";
		if (Lammat < FinalCall)
		{
			if (CardsOnGround.empty()) {
				
				bool LammatFelTrump = true, Hal3abDy = true, bal7a2Nafsy = false, Hal3abElRisk = true, el3abElKing = true, okk2 = true;
				int tuna;
				string tunas, sushi;
				if (Trump == "Spades") { tuna = 0; tunas = "Spades"; }
				if (Trump == "Hearts") { tuna = 1; tunas = "Hearts"; }
				if (Trump == "Diamonds") { tuna = 2; tunas = "Diamonds"; }
				if (Trump == "EClubs") { tuna = 3; tunas = "EClubs"; }

				if (lammaty.size() == 0)
				{
					cout << "wasalt lel riskat";
					int iMaxinHandString;
					pair<int, int> maxinHand;
					if (pc[0].second == "Spades")iMaxinHandString = 0;
					if (pc[0].second == "Diamonds")iMaxinHandString = 1;
					if (pc[0].second == "Hearts")iMaxinHandString = 2;
					if (pc[0].second == "EClubs")iMaxinHandString = 3;
					maxinHand.first = pc[0].first;
					maxinHand.second = iMaxinHandString;
					for (int i = 0; i < pc.size(); i++)
					{
						if (maxinHand.first < pc[i].first && pc[i].second!=Trump)
						{
							maxinHand.first = pc[i].first;
							if (pc[i].second == "Spades")iMaxinHandString = 0;
							if (pc[i].second == "Hearts")iMaxinHandString = 1;
							if (pc[i].second == "Diamonds")iMaxinHandString = 2;
							if (pc[i].second == "EClubs")iMaxinHandString = 3;
							maxinHand.second = iMaxinHandString;
						}
					}
					for (int i = 0; i < pc.size(); i++)
					{
						if (pc[i].second == Trump)
						{
							maxinHand.first = pc[i].first;
							if (pc[i].second == "Spades")iMaxinHandString = 0;
							if (pc[i].second == "Hearts")iMaxinHandString = 1;
							if (pc[i].second == "Diamonds")iMaxinHandString = 2;
							if (pc[i].second == "EClubs")iMaxinHandString = 3;
							maxinHand.second = iMaxinHandString;
						}
					}
					bal7a2Nafsy = true;
					lammaty.push_back(maxinHand);
				}

				cout << "Lammaty Ahy : " << endl;
				for (int i = 0; i < lammaty.size(); i++)
				{
					cout << lammaty[i].first << " " << lammaty[i].second << endl;
				}


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
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second==wara2a.second ) {
					//				Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin() + jk); break;
									pc.erase(pc.begin() + jk); break;
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
							for (int gh = 0; gh < GlobalDeck.size(); gh++)
							{
								if (GlobalDeck[gh].first==14 && GlobalDeck[gh].second == sushi)
								{
									el3abElKing = true;
									CardDeck[((lammaty[i].second + 1) * 13) - 1].first = -1;
									break;
								}
								else
								{
									el3abElKing = false;
								}
							}
							 if (CardDeck[((lammaty[i].second + 1) * 13) - 1].first == 14 || !el3abElKing) {
								if (Shapes[lammaty[i].second].size() > 2) {
									wara2a.first = Shapes[lammaty[i].second][Shapes[lammaty[i].second].size() / 2];
									wara2a.second = sushi;
									for (int jk = 0; jk < pc.size(); jk++) {
										if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
											pc.erase(pc.begin() + jk); break;
										}
									}
						//			Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin() + Shapes[lammaty[i].second].size() / 2);
								}
								else {
									wara2a.first = Shapes[lammaty[i].second][0];
									wara2a.second = sushi;
									for (int jk = 0; jk < pc.size(); jk++) {
										if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
											pc.erase(pc.begin() + jk); break;
										}
									}
							//		Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin());
								}
							}
							else {
								wara2a.first = 13;
								wara2a.second = sushi;
								for (int jk = 0; jk < pc.size(); jk++) {
									if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
										pc.erase(pc.begin() + jk); break;
									}
								}
							//			Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin() + jk); break;
								lammaty.erase(lammaty.begin() + i);
							}
							return wara2a;
						}
					}
				}

				if (bal7a2Nafsy && lammaty[0].second != tuna)
				{
					LammatFelTrump = false;
					if (lammaty[0].second == 0)sushi = "Spades";
					if (lammaty[0].second == 1)sushi = "Hearts";
					if (lammaty[0].second == 2)sushi = "Diamonds";
					if (lammaty[0].second == 3)sushi = "EClubs";
					int Counter=0;
					for (int gh = 0; gh < GlobalDeck.size(); gh++)
					{
						if (GlobalDeck[gh].first > lammaty[0].first  && GlobalDeck[gh].second == sushi)
						{
								Counter++;
						}
					}
					if (Counter == 14 - lammaty[0].first)
					{
						for (int i = 1; i < Counter; i++)
						{
						CardDeck[((lammaty[0].second + 1) * 13) - i].first = -1;
						}
					}

					for (int ik = ((lammaty[0].second + 1) * 13) - 1; ik > (((lammaty[0].second + 1) * 13) - 1) - 13; ik--)
					{
						if (lammaty[0].first < CardDeck[ik].first)
						{
							Hal3abElRisk = false;
							break;
						}
					}
					
					if (Hal3abElRisk)
					{
					cout << "dy el moshkela"<< endl;
					wara2a.first = lammaty[0].first;
					if (lammaty[0].second == 0)sushi = "Spades";
					if (lammaty[0].second == 1)sushi = "Hearts";
					if (lammaty[0].second == 2)sushi = "Diamonds";
					if (lammaty[0].second == 3)sushi = "EClubs";
					wara2a.second = sushi;
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					lammaty.clear();
					return wara2a;
					}
					else
					{
						if (lammaty[0].second == 0)sushi = "Spades";
						if (lammaty[0].second == 1)sushi = "Hearts";
						if (lammaty[0].second == 2)sushi = "Diamonds";
						if (lammaty[0].second == 3)sushi = "EClubs";
						if (Shapes[lammaty[0].second].size() > 2) {
							wara2a.first = Shapes[lammaty[0].second][Shapes[lammaty[0].second].size() / 2];
							wara2a.second = sushi;
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							//			Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin() + Shapes[lammaty[i].second].size() / 2);
						}
						else {
							wara2a.first = Shapes[lammaty[0].second][0];
							wara2a.second = sushi;
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							//		Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin());
						}
						lammaty.clear();
						return wara2a;
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
						cout << "wasal le7ad hena , wel ik = " << ik << endl;
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
									for (int jk = 0; jk < pc.size(); jk++) {
										if (pc[jk].first == wara2a.first && pc[jk].second ==tunas) {
											pc.erase(pc.begin() + jk); break;
										}
									}
									//		Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin());
									break;
								}
								else if (kk == lammaty.size() - 1) {
									wara2a.first = Shapes[lammaty[i].second][Shapes[lammaty[i].second].size() / 2];
									for (int jk = 0; jk < pc.size(); jk++) {
										if (pc[jk].first == wara2a.first && pc[jk].second == tunas) {
											pc.erase(pc.begin() + jk); break;
										}
									}
									//		Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin() + Shapes[lammaty[i].second].size() / 2);
								}
							}
							wara2a.second = tunas;
						}
						else {
							wara2a.first = Shapes[lammaty[i].second][0];
							wara2a.second = tunas;
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							//Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin());
						}
					}
					else
					{
						wara2a.first = lammaty[i].first;
						wara2a.second = tunas;
						for (int jk = 0; jk < pc.size(); jk++) {
							if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
								pc.erase(pc.begin() + jk); break;
							}
						}
						//Shapes[lammaty[i].second].erase(Shapes[lammaty[i].second].begin() + Shapes[tuna].size() - 1);
						lammaty.erase(lammaty.begin() + i);
					}

					return wara2a;//Kanet Na2sa
				}

			}



			else if (!CardsOnGround.empty()) {
				//cout << "mashy eshta tmam " << endl;
				for (int j = 0; j < CardsOnGround.size(); j++) {
					for (int p = 0; p < CardDeck.size(); p++) {
						if (CardsOnGround[j] == CardDeck[p]) {
							CardDeck[p].first = -1;
						}
					}
				}
				for (int gg = 0; gg < CardDeck.size(); gg++)
				{
					for (int bg = 0; bg < GlobalDeck.size(); bg++)
					{
						if (CardDeck[gg].first == GlobalDeck[bg].first && CardDeck[gg].second == GlobalDeck[bg].second)
						{
							CardDeck[gg].first = -1;
							break;
						}
					}
				}

				int gro;
				string gros;

				cout << "Lammaty Ahy : " << endl;
				for (int i = 0; i < lammaty.size(); i++)
				{
					cout << lammaty[i].first << " " << lammaty[i].second << endl;
				}


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
			
				if (gros == Trump && Shapes[gro].size()==0)
				{
				int tuna;
				if (Trump == "Spades")tuna = 0;
				if (Trump == "Hearts")tuna = 1;
				if (Trump == "Diamonds")tuna = 2;
				if (Trump == "EClubs")tuna = 3;

				int maxi = pc[0].first;
				string maxiColor = pc[0].second;
				for (int f = 0; f < pc.size(); f++)
				{
					if (pc[f].first < maxi)
					{
						maxi = pc[f].first;
						maxiColor = pc[f].second;
					}
				
				wara2a.first = maxi;
				wara2a.second = maxiColor;
				}
				for (int jk = 0; jk < pc.size(); jk++) {
					if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
						pc.erase(pc.begin() + jk); break;
					}
				}
				int tempooo;
				if (wara2a.second == "Spades")tempooo = 0;
				if (wara2a.second == "Hearts")tempooo = 1;
				if (wara2a.second == "Diamonds")tempooo = 2;
				if (wara2a.second == "EClubs")tempooo = 3;
				for (int mj = 0; mj < lammaty.size(); mj++)
				{
					if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
					{
						lammaty.erase(lammaty.begin() + mj); break;
					}
				}
				return wara2a;

				}


				if (lammaty.size() == 0)
				{
					if (Shapes[gro].size() != 0)
					{
						wara2a.first = Shapes[gro][Shapes[gro].size() - 1];
						wara2a.second = gros;
					}
					else
					{
						int maxi = pc[0].first;
						string maxiColor=pc[0].second;
						for (int f = 0; f < pc.size(); f++)
						{
							if (pc[f].first < maxi)
							{
								maxi = pc[f].first;
								maxiColor = pc[f].second;
							}
						}
						wara2a.first = maxi;
						wara2a.second = maxiColor;
					}
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					int tempooo;
					if (wara2a.second == "Spades")tempooo = 0;
					if (wara2a.second == "Hearts")tempooo = 1;
					if (wara2a.second == "Diamonds")tempooo = 2;
					if (wara2a.second == "EClubs")tempooo = 3;
					for (int mj = 0; mj < lammaty.size(); mj++)
					{
						if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
						{
							lammaty.erase(lammaty.begin() + mj); break;
						}
					}
					return wara2a;
				}

				int maxi = -1;
				bool haseb = 0;
				
				for (int kl = 1; kl < CardsOnGround.size(); kl++) {
					//cout << CardsOnGround[kl].first << " " << CardsOnGround[kl].second << endl;
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
									
									if (haseb||biggeT) {
										wara2a.first = Shapes[gro][0];
								//Shapes[gro].erase(Shapes[gro].begin() + 0);
										CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
										wara2a.second = gros;
								for (int jk = 0; jk < pc.size(); jk++) {
									if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
										pc.erase(pc.begin() + jk); break;
									}
								}
								int tempooo;
								if (wara2a.second == "Spades")tempooo = 0;
								if (wara2a.second == "Hearts")tempooo = 1;
								if (wara2a.second == "Diamonds")tempooo = 2;
								if (wara2a.second == "EClubs")tempooo = 3;
								for (int mj = 0; mj < lammaty.size(); mj++)
								{
									if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
									{
										lammaty.erase(lammaty.begin() + mj); break;
									}
								}
								return wara2a;
									}
									else if (CardDeck[ik].second == gros && CardDeck[ik].first > lammaty[x].first ) {

										if (Shapes[gro].size() > 2) {

											wara2a.first = Shapes[gro][Shapes[gro].size() / 2];
					//						Shapes[gro].erase(Shapes[gro].begin() + Shapes[gro].size() / 2);
											CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
											wara2a.second = gros;
											for (int jk = 0; jk < pc.size(); jk++) {
												if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
													pc.erase(pc.begin() + jk); break;
												}
											}
											int tempooo;
											if (wara2a.second == "Spades")tempooo = 0;
											if (wara2a.second == "Hearts")tempooo = 1;
											if (wara2a.second == "Diamonds")tempooo = 2;
											if (wara2a.second == "EClubs")tempooo = 3;
											for (int mj = 0; mj < lammaty.size(); mj++)
											{
												if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
												{
													lammaty.erase(lammaty.begin() + mj); break;
												}
											}
											return wara2a;
										}
										else if (Shapes[gro].size() == 2) {

											wara2a.first = Shapes[gro][0];
						//					Shapes[gro].erase(Shapes[gro].begin() + 1);
											CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
											wara2a.second = gros;
											for (int jk = 0; jk < pc.size(); jk++) {
												if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
													pc.erase(pc.begin() + jk); break;
												}
											}
											int tempooo;
											if (wara2a.second == "Spades")tempooo = 0;
											if (wara2a.second == "Hearts")tempooo = 1;
											if (wara2a.second == "Diamonds")tempooo = 2;
											if (wara2a.second == "EClubs")tempooo = 3;
											for (int mj = 0; mj < lammaty.size(); mj++)
											{
												if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
												{
													lammaty.erase(lammaty.begin() + mj); break;
												}
											}
											return wara2a;
										}
										else {

											wara2a.first = Shapes[gro][0];
							//				Shapes[gro].erase(Shapes[gro].begin());
											CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
											wara2a.second = gros;
											for (int jk = 0; jk < pc.size(); jk++) {
												if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
													pc.erase(pc.begin() + jk); break;
												}
											}
											int tempooo;
											if (wara2a.second == "Spades")tempooo = 0;
											if (wara2a.second == "Hearts")tempooo = 1;
											if (wara2a.second == "Diamonds")tempooo = 2;
											if (wara2a.second == "EClubs")tempooo = 3;
											for (int mj = 0; mj < lammaty.size(); mj++)
											{
												if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
												{
													lammaty.erase(lammaty.begin() + mj); break;
												}
											}
											return wara2a;
										}

									}
									else {
										//cout << "da5al hena\n";
										wara2a.first = lammaty[x].first;
										lammaty.erase(lammaty.begin() + x);
										CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
										//	Lammat++;
										/*for (int jk = 0; jk < Shapes[gro].size(); jk++) {
											if (Shapes[gro][jk] == wara2a.first) {
				//								Shapes[gro].erase(Shapes[gro].begin() + jk); break;
											}
										}*/
											CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
											wara2a.second = gros;
											for (int jk = 0; jk < pc.size(); jk++) {
												if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
													pc.erase(pc.begin() + jk); break;
												}
											}
											int tempooo;
											if (wara2a.second == "Spades")tempooo = 0;
											if (wara2a.second == "Hearts")tempooo = 1;
											if (wara2a.second == "Diamonds")tempooo = 2;
											if (wara2a.second == "EClubs")tempooo = 3;
											for (int mj = 0; mj < lammaty.size(); mj++)
											{
												if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
												{
													lammaty.erase(lammaty.begin() + mj); break;
												}
											}
											return wara2a;
									}


								}
							}
							else if (x == lammaty.size() - 1) {
								wara2a.first = Shapes[gro][0];
								wara2a.second = gros;
								for (int jk = 0; jk < pc.size(); jk++) {
									if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
										pc.erase(pc.begin() + jk); break;
									}
								}
								int tempooo;
								if (wara2a.second == "Spades")tempooo = 0;
								if (wara2a.second == "Hearts")tempooo = 1;
								if (wara2a.second == "Diamonds")tempooo = 2;
								if (wara2a.second == "EClubs")tempooo = 3;
								for (int mj = 0; mj < lammaty.size(); mj++)
								{
									if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
									{
										lammaty.erase(lammaty.begin() + mj); break;
									}
								}
								return wara2a;
							}
							else continue;

						}
						if (Shapes[gro][i] > maxi)
						{
							wara2a.first = Shapes[gro][i];
							wara2a.second = gros;
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							int tempooo;
							if (wara2a.second == "Spades")tempooo = 0;
							if (wara2a.second == "Hearts")tempooo = 1;
							if (wara2a.second == "Diamonds")tempooo = 2;
							if (wara2a.second == "EClubs")tempooo = 3;
							for (int mj = 0; mj < lammaty.size(); mj++)
							{
								if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
								{
									lammaty.erase(lammaty.begin() + mj); break;
								}
							}
							return wara2a;
						}
						if (i == Shapes[gro].size() - 1)
						{
							wara2a.first = Shapes[gro][0];
							wara2a.second = gros;
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							int tempooo;
							if (wara2a.second == "Spades")tempooo = 0;
							if (wara2a.second == "Hearts")tempooo = 1;
							if (wara2a.second == "Diamonds")tempooo = 2;
							if (wara2a.second == "EClubs")tempooo = 3;
							for (int mj = 0; mj < lammaty.size(); mj++)
							{
								if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
								{
									lammaty.erase(lammaty.begin() + mj); break;
								}
							}
							return wara2a;
						}
						}

				}
				else {
					//cout << "AVOID"<<endl;
					int tuna, index;
					bool el3ab = true;
					if (gros != Trump) {
					//	cout << "Ground msh 2atoo3 " << endl;
						if (Trump == "Spades")tuna = 0;
						if (Trump == "Hearts")tuna = 1;
						if (Trump == "Diamonds")tuna = 2;
						if (Trump == "EClubs")tuna = 3;
						//cout << tuna << endl;
						if (Shapes[tuna].size() == 0)el3ab = false;
						for (int i = 0; i < Shapes[tuna].size(); i++) {
						//	cout << Shapes[tuna].size() << endl;
							for (int ik = 0; ik < CardsOnGround.size(); ik++) {
								if (CardsOnGround[ik].second == Trump && Shapes[tuna][i] < CardsOnGround[ik].first) {
							//	cout << "TMAMTMAMTMAM" << ik << endl;
									el3ab = false;
									break;
								}
								else if (CardsOnGround[ik].second == Trump && Shapes[tuna][i] > CardsOnGround[ik].first) {
									el3ab = true;
									//break;
								}
								if (el3ab&&ik == CardsOnGround.size() - 1) {
									index = -1;
								}


							}
							if (index == -1) { index = i;}
						}
						if (el3ab) {
							wara2a.first = Shapes[tuna][index];
							wara2a.second = Trump;
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							//Shapes[tuna].erase(Shapes[tuna].begin() + index);
							CardDeck[(tuna * 13) + wara2a.first - 2].first = -1;
							//	Lammat++;
							int tempooo;
							if (wara2a.second == "Spades")tempooo = 0;
							if (wara2a.second == "Hearts")tempooo = 1;
							if (wara2a.second == "Diamonds")tempooo = 2;
							if (wara2a.second == "EClubs")tempooo = 3;
							for (int mj = 0; mj < lammaty.size(); mj++)
							{
								if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
								{
									lammaty.erase(lammaty.begin() + mj); break;
								}
							}
							return wara2a;
						}
						else {
							int maxi = -1, indexi = -1;
							for (int i = 0; i < Shapes.size(); i++) {
								if (i != gro && i != tuna) {
									if (maxi < Shapes[i].size()) {
										maxi = Shapes[i].size();
										indexi = i;
									}
								}
								if (i == Shapes.size() - 1 && indexi==-1)
								{
									indexi = i;
								}
							}
							wara2a.first = Shapes[indexi][0];
							if (indexi == 0) { wara2a.second = "Spades"; }
							if (indexi == 1) { wara2a.second = "Hearts"; }
							if (indexi == 2) { wara2a.second = "Diamonds"; }
							if (indexi == 3) { wara2a.second = "EClubs"; }
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							//Shapes[indexi].erase(Shapes[indexi].begin() + 0);
							CardDeck[(indexi * 13) + wara2a.first - 2].first = -1;
							int tempooo;
							if (wara2a.second == "Spades")tempooo = 0;
							if (wara2a.second == "Hearts")tempooo = 1;
							if (wara2a.second == "Diamonds")tempooo = 2;
							if (wara2a.second == "EClubs")tempooo = 3;
							for (int mj = 0; mj < lammaty.size(); mj++)
							{
								if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
								{
									lammaty.erase(lammaty.begin() + mj); break;
								}
							}
							return wara2a;
						}
					}
				}
			}
		}



		else if(Lammat == FinalCall)
		{
			if (CardsOnGround.empty())
			{
				vector<string>sushi(4);
				sushi[0] = "Spades";
				sushi[1] = "Hearts";
				sushi[2] = "Diamonds";
				sushi[3] = "EClubs";
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < Shapes[i].size(); j++) {
						for (int jk = ((i + 1) * 13) - 1; jk > i * 13; jk--) {
							if (CardDeck[jk].first > Shapes[i][j]) {
								wara2a.first = Shapes[i][j];
								wara2a.second = sushi[i];
								CardDeck[jk].first = -1;
								for (int ck = 0; ck < pc.size(); ck++) {
									if (pc[ck].first == wara2a.first && pc[ck].second == wara2a.second) {
										pc.erase(pc.begin() + ck); break;
									}
								}
								int tempooo;
								if (wara2a.second == "Spades")tempooo = 0;
								if (wara2a.second == "Hearts")tempooo = 1;
								if (wara2a.second == "Diamonds")tempooo = 2;
								if (wara2a.second == "EClubs")tempooo = 3;
								for (int mj = 0; mj < lammaty.size(); mj++)
								{
									if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
									{
										lammaty.erase(lammaty.begin() + mj); break;
									}
								}
								return wara2a;
							}
						}
					}
				}
			}

			else if (!CardsOnGround.empty())
			{
				//cout << "tmam awel condition " << endl;
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
				//cout<<"m3ah :" <<Shapes[gro].size()<<endl;
				for (int v = 0; v < CardsOnGround.size(); v++)
				{
					if (CardsOnGround[v].first > mxOnGround.first)
					{
						mxOnGround.first = CardsOnGround[v].first;
					}
				}
				//	cout << "Mafysh mshakel le7ad hena (1) ! :D" << endl;

				for (int i = 0; i < Shapes[gro].size(); i++)
				{
					if (Shapes[gro][i] < mxOnGround.first)
					{
					//	cout << "NOTONGROUND!!!"<<endl;
						wara2a.first = Shapes[gro][i];
						wara2a.second = gros;
						for (int jk = 0; jk < pc.size(); jk++) {
							if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
								pc.erase(pc.begin() + jk); break;
							}
						}
						//Shapes[gro].erase(Shapes[gro].begin() + i);
						NotOnGround = false;
						int tempooo;
						if (wara2a.second == "Spades")tempooo = 0;
						if (wara2a.second == "Hearts")tempooo = 1;
						if (wara2a.second == "Diamonds")tempooo = 2;
						if (wara2a.second == "EClubs")tempooo = 3;
						for (int mj = 0; mj < lammaty.size(); mj++)
						{
							if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
							{
								lammaty.erase(lammaty.begin() + mj); break;
							}
						}
						break;
					}
				}
			//	cout << "Mafysh mshakel le7ad hena (2) ! :D" << endl;
				if (!NotOnGround)return wara2a;
				else if (NotOnGround)
				{
					for (int i = 0; i < Shapes[gro].size(); i++)
					{
					//	cout << "Mafysh mshakel le7ad hena (3) ("<<i<<")" << endl;
						for (int ik = ((gro + 1) * 13) - 1; ik >= ((gro) * 13); ik--)
						{
						//	cout << "Mafysh mshakel le7ad hena (3) (" << ik << ")" << endl;
							if (CardDeck[ik].second == gros && CardDeck[ik].first > Shapes[gro][i])
							{
								//cout << "NOTINDECK!!!" << endl;
								wara2a.first = Shapes[gro][i];
								wara2a.second = gros;
								for (int jk = 0; jk < pc.size(); jk++) {
									if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
										pc.erase(pc.begin() + jk); break;
									}
								}
							//	Shapes[gro].erase(Shapes[gro].begin() + i);
								NotInDeck = false;
								int tempooo;
								if (wara2a.second == "Spades")tempooo = 0;
								if (wara2a.second == "Hearts")tempooo = 1;
								if (wara2a.second == "Diamonds")tempooo = 2;
								if (wara2a.second == "EClubs")tempooo = 3;
								for (int mj = 0; mj < lammaty.size(); mj++)
								{
									if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
									{
										lammaty.erase(lammaty.begin() + mj); break;
									}
								}
								break;
							}
						}
					}
				}
				//cout << "Mafysh mshakel le7ad hena (4) ! :D" << endl;
				if (!NotInDeck)return wara2a;
				else if (NotInDeck)
				{
				//	cout << "wasal " << endl;
				//	cout << "MODTAR Al3AB!!!" << endl;
					if (Shapes[gro].size() > 0)
					{
					wara2a.first = Shapes[gro][0];
					wara2a.second = gros;
					}
					else
					{
						int tuna,temp;
						string Stemp;
						if (Trump == "Spades") { tuna = 0;}
						if (Trump == "Hearts") { tuna = 1;}
						if (Trump == "Diamonds") { tuna = 2;}
						if (Trump == "EClubs") { tuna = 3;}
						for (int f = 0; f < 4; f++)
						{
							if (f != gro && f != tuna && Shapes[f].size()!=0)
							{
								temp = f;
								break;
							}
							else if(Shapes[f].size() != 0)
							{
								temp = f;
							}
						}
								if (temp == 0) { Stemp ="Spades"; }
								if (temp == 1) { Stemp = "Hearts"; }
								if (temp == 2) { Stemp = "Diamonds"; }
								if (temp == 3) { Stemp = "EClubs"; }
						wara2a.first = Shapes[temp][0];
						wara2a.second = Stemp;
					}
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
				//	Shapes[gro].erase(Shapes[gro].begin());
					int tempooo;
					if (wara2a.second == "Spades")tempooo = 0;
					if (wara2a.second == "Hearts")tempooo = 1;
					if (wara2a.second == "Diamonds")tempooo = 2;
					if (wara2a.second == "EClubs")tempooo = 3;
					for (int mj = 0; mj < lammaty.size(); mj++)
					{
						if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
						{
							lammaty.erase(lammaty.begin() + mj); break;
						}
					}
					return wara2a;
				}

			}
		}

		else
		{

		}

	}
		
	else if (Status == "Under")
	{

	}

	
	
	return wara2a;
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

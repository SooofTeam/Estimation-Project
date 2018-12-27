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


	return Counter;
}
void AiPlayer::PlayGround(vector<pair<int, string>> &CardOnGround, string Trump, vector<int> &KolElLammat, vector<bool>&inHand, vector<int> &lammat)
{
	int assign[4] = { -1,-1,-1,-1 };


	bool c = 1, t = 0, m = 1;
	int mod, it = 0, ity = 0;
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


	int maxi = CardOnGround[0].first, maxT = -1, iTrump = -1;
	it = 0;

	for (int i = 1; i < 4; i++) {
		if (CardOnGround[i].first > maxi&&CardOnGround[i].second == CardOnGround[0].second) {
			maxi = CardOnGround[i].first;
			it = i;
		}
	}

	for (int i = 1; i < 4; i++) {
		if (CardOnGround[i].second == Trump && CardOnGround[i].first > maxT&&CardOnGround[i].second != CardOnGround[0].second) {
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
		inHand = { 0,0,0,0 };
		inHand[assign[it]] = 1;
		lammat[assign[it]]++;
	}


}

pair<int, string> AiPlayer::CardDes(vector < pair<int, string>> &CardDeck, vector < pair<int, string>> GlobalDeck, vector<pair<int, string>> CardsOnGround, string Trump, vector < pair<int, string>>&pc, string Status, int &Lammat, int FinalCall, vector<pair<int, int>>&lammaty)
{
	for (int j = 0; j < lammaty.size();j++) {
		for (int i = 0; i < pc.size();i++) {
			if (lammaty[j].first == pc[i].first&&lammaty[j].second == switchString(pc[i].second)) {
				break;
			}
			else if (i == pc.size() - 1) {
				lammaty.erase(lammaty.begin() + j);
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


	pair<int, string> wara2a;

	for (int i = 0; i < Shapes.size(); i++) {
		for (int j = 0; j < Shapes[i].size(); j++) {
			CardDeck[(i * 13) + Shapes[i][j] - 2].first = -2;
		}
	}
	if (pc.size() == 1)
	{
		
		wara2a = pc[0];
		for (int jk = 0; jk < pc.size(); jk++) {
			if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
				pc.erase(pc.begin() + jk); break;
			}
		}
		return wara2a;
	}

	if (Status == "Over")
	{
		
		if (Lammat < FinalCall)
		{
			
			if (CardsOnGround.empty()) {
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


				bool LammatFelTrump = true, Hal3abDy = true, bal7a2Nafsy = false, Hal3abElRisk = true, el3abElKing = true, okk2 = true;
				int tuna;
				string tunas, sushi;
				tunas = Trump;
				tuna = switchString(Trump);
			
				if (lammaty.size() == 0)
				{
					int iMaxinHandString;
					pair<int, int> maxinHand;
					iMaxinHandString = switchString(pc[0].second);
					maxinHand.first = pc[0].first;
					maxinHand.second = iMaxinHandString;
					for (int i = 0; i < pc.size(); i++)
					{
						if (maxinHand.first < pc[i].first && pc[i].second != Trump)
						{
							maxinHand.first = pc[i].first;
							iMaxinHandString = switchString(pc[i].second);
							maxinHand.second = iMaxinHandString;
						}
					}
					for (int i = 0; i < pc.size(); i++)
					{
						if (pc[i].second == Trump)
						{
							maxinHand.first = pc[i].first;
							iMaxinHandString = switchString(pc[i].second);
							maxinHand.second = iMaxinHandString;
						}
					}
					bal7a2Nafsy = true;
					lammaty.push_back(maxinHand);
				}

			


				for (int i = 0; i < lammaty.size(); i++) {
					if (lammaty[i].second != tuna) {
						LammatFelTrump = false;
						sushi = switchInt(lammaty[i].second);
						if (lammaty[i].first == 14) {
							wara2a.first = 14;
							wara2a.second = sushi;
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
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
						sushi = switchInt(lammaty[i].second);
						if (lammaty[i].first == 13) {
							for (int gh = 0; gh < GlobalDeck.size(); gh++)
							{
								if (GlobalDeck[gh].first == 14 && GlobalDeck[gh].second == sushi)
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
								}
								else {
									wara2a.first = Shapes[lammaty[i].second][0];
									wara2a.second = sushi;
									for (int jk = 0; jk < pc.size(); jk++) {
										if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
											pc.erase(pc.begin() + jk); break;
										}
									}
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
								lammaty.erase(lammaty.begin() + i);
							}
							return wara2a;
						}
					}
				}

				if (bal7a2Nafsy && lammaty[0].second != tuna)
				{
					bool tmam = false;
					LammatFelTrump = false;
					sushi = switchInt(lammaty[0].second);

					for (int i = 0; i < pc.size(); i++)
					{
						if (lammaty[0].first == pc[i].first && sushi == pc[i].second)
						{
							tmam = false;
							break;
						}
					}
					if (tmam)
					{
						int Counter = 0;
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

							wara2a.first = lammaty[0].first;
							sushi = switchInt(lammaty[0].second);
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
							sushi = switchInt(lammaty[0].second);
							if (Shapes[lammaty[0].second].size() > 2) {
								wara2a.first = Shapes[lammaty[0].second][Shapes[lammaty[0].second].size() / 2];
								wara2a.second = sushi;
								for (int jk = 0; jk < pc.size(); jk++) {
									if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
										pc.erase(pc.begin() + jk); break;
									}
								}
							}
							else {
								wara2a.first = Shapes[lammaty[0].second][0];
								wara2a.second = sushi;
								for (int jk = 0; jk < pc.size(); jk++) {
									if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
										pc.erase(pc.begin() + jk); break;
									}
								}
							}
							lammaty.clear();
							return wara2a;
						}
					}
					else
					{
						lammaty.clear();
						LammatFelTrump = true;
					}


				}

				for (int i = 0; (i < lammaty.size()) && LammatFelTrump; i++)
				{
					tunas = Trump;
					tuna = switchString(Trump);
					
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
									for (int jk = 0; jk < pc.size(); jk++) {
										if (pc[jk].first == wara2a.first && pc[jk].second == tunas) {
											pc.erase(pc.begin() + jk); break;
										}
									}
									lammaty.erase(lammaty.begin() + i);
									break;
								}
								else if (kk == lammaty.size() - 1) {
									wara2a.first = Shapes[lammaty[i].second][Shapes[lammaty[i].second].size() / 2];
									for (int jk = 0; jk < pc.size(); jk++) {
										if (pc[jk].first == wara2a.first && pc[jk].second == tunas) {
											pc.erase(pc.begin() + jk); break;
										}
									}
									lammaty.erase(lammaty.begin() + i);
									break;
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
							lammaty.erase(lammaty.begin() + i);
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
						lammaty.erase(lammaty.begin() + i);
					}

					return wara2a;
				}

				if (lammaty.size() == 0 && LammatFelTrump)
				{
					pair<int, string> maxinHand;
					maxinHand.first = pc[0].first;
					maxinHand.second = pc[0].second;
					for (int i = 0; i < pc.size(); i++)
					{
						if (maxinHand.first < pc[i].first && pc[i].second != Trump)
						{
							maxinHand.first = pc[i].first;
							maxinHand.second = pc[i].second;
						}
					}
					wara2a.first = maxinHand.first;
					wara2a.second = maxinHand.second;
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;
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

				
				gros = CardsOnGround[0].second;
				gro = switchString(CardsOnGround[0].second);
				
				if (gros == Trump && Shapes[gro].size() == 0)
				{
					int tuna;
					tuna = switchString(Trump);
					
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
					
					tempooo = switchString(wara2a.second);
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
						string maxiColor = pc[0].second;
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
					tempooo = switchString(wara2a.second);
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

									if (haseb || biggeT) {
										wara2a.first = Shapes[gro][0];
										CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
										wara2a.second = gros;
										for (int jk = 0; jk < pc.size(); jk++) {
											if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
												pc.erase(pc.begin() + jk); break;
											}
										}
										int tempooo;
										tempooo = switchString(wara2a.second);
										for (int mj = 0; mj < lammaty.size(); mj++)
										{
											if (lammaty[mj].first == wara2a.first && lammaty[mj].second == tempooo)
											{
												lammaty.erase(lammaty.begin() + mj); break;
											}
										}
										return wara2a;
									}
									else if (CardDeck[ik].second == gros && CardDeck[ik].first > lammaty[x].first) {

										if (Shapes[gro].size() > 2) {

											wara2a.first = Shapes[gro][Shapes[gro].size() / 2];
											CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
											wara2a.second = gros;
											for (int jk = 0; jk < pc.size(); jk++) {
												if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
													pc.erase(pc.begin() + jk); break;
												}
											}
											int tempooo;
											tempooo = switchString(wara2a.second);
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
											CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
											wara2a.second = gros;
											for (int jk = 0; jk < pc.size(); jk++) {
												if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
													pc.erase(pc.begin() + jk); break;
												}
											}
											int tempooo;
											tempooo = switchString(wara2a.second);
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
											CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
											wara2a.second = gros;
											for (int jk = 0; jk < pc.size(); jk++) {
												if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
													pc.erase(pc.begin() + jk); break;
												}
											}
											int tempooo;
											tempooo = switchString(wara2a.second);
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
										
										wara2a.first = lammaty[x].first;
										lammaty.erase(lammaty.begin() + x);
										CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
										CardDeck[(gro * 13) + wara2a.first - 2].first = -1;
										wara2a.second = gros;
										for (int jk = 0; jk < pc.size(); jk++) {
											if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
												pc.erase(pc.begin() + jk); break;
											}
										}
										int tempooo;
										tempooo = switchString(wara2a.second);
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
								tempooo = switchString(wara2a.second);
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
							tempooo = switchString(wara2a.second);
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
							tempooo = switchString(wara2a.second);
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
					int tuna, index;
					bool el3ab = true;
					if (gros != Trump) {
						tuna = switchString(Trump);
						if (Shapes[tuna].size() == 0)el3ab = false;
						for (int i = 0; i < Shapes[tuna].size(); i++) {
							for (int ik = 0; ik < CardsOnGround.size(); ik++) {
								if (CardsOnGround[ik].second == Trump && Shapes[tuna][i] < CardsOnGround[ik].first) {
									el3ab = false;
									break;
								}
								else if (CardsOnGround[ik].second == Trump && Shapes[tuna][i] > CardsOnGround[ik].first) {
									el3ab = true;
								}
								if (el3ab&&ik == CardsOnGround.size() - 1) {
									index = -1;
								}


							}
							if (index == -1) { index = i; }
						}
						if (el3ab) {
							wara2a.first = Shapes[tuna][index];
							wara2a.second = Trump;
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							CardDeck[(tuna * 13) + wara2a.first - 2].first = -1;
							int tempooo;
							tempooo = switchString(wara2a.second);
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
							int maxi = -1, indexi = -1, tempoz;
							for (int i = 0; i < Shapes.size(); i++) {
								if (i != gro && i != tuna) {
									tempoz = Shapes[i].size();
									if (maxi < tempoz)
									{
										maxi = Shapes[i].size();
										indexi = i;
									}
								}
								if (i == Shapes.size() - 1 && indexi == -1)
								{
									indexi = i;
								}
							}
							wara2a.first = Shapes[indexi][0];
							wara2a.second = switchInt(indexi);
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							CardDeck[(indexi * 13) + wara2a.first - 2].first = -1;
							int tempooo;
							tempooo = switchString(wara2a.second);
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
		else if (Lammat == FinalCall)
		{
			if (CardsOnGround.empty())
			{
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
								return wara2a;
							}
						}
					}
				}
				pair<int, string> maxinHand;
				maxinHand.first = pc[0].first;
				maxinHand.second = pc[0].second;
				for (int i = 0; i < pc.size(); i++)
				{
					if (maxinHand.first > pc[i].first && pc[i].second != Trump)
					{
						maxinHand.first = pc[i].first;
						maxinHand.second = pc[i].second;
					}
				}
				wara2a.first = maxinHand.first;
				wara2a.second = maxinHand.second;
				for (int jk = 0; jk < pc.size(); jk++) {
					if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
						pc.erase(pc.begin() + jk); break;
					}
				}
				return wara2a;
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
				bool NotOnGround = true, NotInDeck = true;
				pair <int, int> mxOnGround;
				gro = switchString(CardsOnGround[0].second);
				gros = CardsOnGround[0].second;
				mxOnGround.first = CardsOnGround[0].first;
				mxOnGround.second = gro;
				for (int v = 0; v < CardsOnGround.size(); v++)
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
						wara2a.second = gros;
						for (int jk = 0; jk < pc.size(); jk++) {
							if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
								pc.erase(pc.begin() + jk); break;
							}
						}
						NotOnGround = false;
						int tempooo;
						tempooo = switchString(wara2a.second);
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

				if (!NotOnGround)return wara2a;
				else if (NotOnGround)
				{
					for (int i = 0; i < Shapes[gro].size(); i++)
					{
						for (int ik = ((gro + 1) * 13) - 1; ik >= ((gro) * 13); ik--)
						{
							if (CardDeck[ik].second == gros && CardDeck[ik].first > Shapes[gro][i])
							{
								wara2a.first = Shapes[gro][i];
								wara2a.second = gros;
								for (int jk = 0; jk < pc.size(); jk++) {
									if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
										pc.erase(pc.begin() + jk); break;
									}
								}
								NotInDeck = false;
								int tempooo;
								tempooo = switchString(wara2a.second);
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
				if (!NotInDeck)return wara2a;
				else if (NotInDeck)
				{
					if (Shapes[gro].size() > 0)
					{
						wara2a.first = Shapes[gro][0];
						wara2a.second = gros;
					}
					else
					{
						int tuna, temp;
						string Stemp;
						tuna = switchString(Trump);
						for (int f = 0; f < 4; f++)
						{
							if (f != gro && f != tuna && Shapes[f].size() != 0)
							{
								temp = f;
								break;
							}
							else if (Shapes[f].size() != 0)
							{
								temp = f;
							}
						}
						Stemp = switchInt(temp);
						wara2a.first = Shapes[temp][0];
						wara2a.second = Stemp;
					}
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					int tempooo;
					tempooo = switchString(wara2a.second);
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
			int gro, tuna, index=-1; string gros; bool hal3ab = true;

			if (CardsOnGround.empty())
			{
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
				pair<int, string> myCard;
				myCard.first = -1;
				for (auto j : pc) {
					for (int oh = 0; oh < CardDeck.size(); oh++) {
						if (j.first < CardDeck[oh].first&&j.second == CardDeck[oh].second) {
							break;
						}
						else if (oh == CardDeck.size()) {
							myCard.first = j.first;
							myCard.second = j.second;
						}
					}
				}
				if (myCard.first == -1) {
					myCard.first = pc[0].first;
					myCard.second = pc[0].second;
				}
				wara2a.first = myCard.first;
				wara2a.second = myCard.second;
				for (int jk = 0; jk < pc.size(); jk++) {
					if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
						pc.erase(pc.begin() + jk); break;
					}
				}
				return wara2a;

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
				tuna = switchString(Trump);
				gro = switchString(CardsOnGround[0].second);
				gros = CardsOnGround[0].second;

				if (Shapes[gro].size() != 0)
				{
					for (int i = 0; i < Shapes[gro].size(); i++)
					{
						for (int j = ((gro + 1) * 13) - 1; j > (((gro + 1) * 13) - 1) - 13; j--)
						{
							if (CardDeck[j].first > Shapes[gro][i])
							{
								hal3ab = false;
								break;
							}
							else
							{
								hal3ab = true;
								index = i;
							}
						}
						if (index == -1)
						{
							index = i;
						}
						
					}

					wara2a.first = Shapes[gro][index];
					wara2a.second = gros;
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;
				}

				else if (Shapes[tuna].size() != 0)
				{
					for (int i = 0; i < Shapes[tuna].size(); i++)
					{
						for (int j = 0; j < CardsOnGround.size(); j++)
						{
							if (CardsOnGround[j].second == Trump && Shapes[tuna][j] < CardsOnGround[j].first)
							{
								hal3ab = false;
								break;
							}
							else
							{
								hal3ab = true;
								index = i;
							}
						}
						if (index == i)
							break;
					}
					wara2a.first = Shapes[tuna][index];
					wara2a.second = Trump;
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;
				}

				else
				{
					pair<int, string> maxinHand;
					maxinHand.first = pc[0].first;
					maxinHand.second = pc[0].second;
					for (int i = 0; i < pc.size(); i++)
					{
						if (maxinHand.first > pc[i].first && pc[i].second != Trump)
						{
							maxinHand.first = pc[i].first;
							maxinHand.second = pc[i].second;
						}
					}
					wara2a.first = maxinHand.first;
					wara2a.second = maxinHand.second;
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;
				}

			}
		}

	}
	else if (Status == "Under")
	{
		if (lammaty.size() == 0)
		{
			int iMaxinHandString;
			pair<int, int> maxinHand;
			iMaxinHandString = switchString(pc[0].second);
			maxinHand.first = pc[0].first;
			maxinHand.second = iMaxinHandString;
			for (int i = 0; i < pc.size(); i++)
			{
				if (maxinHand.first < pc[i].first && pc[i].second != Trump)
				{
					maxinHand.first = pc[i].first;
					iMaxinHandString = switchString(pc[i].second);
					maxinHand.second = iMaxinHandString;
				}
			}
			for (int i = 0; i < pc.size(); i++)
			{
				if (pc[i].second == Trump)
				{
					maxinHand.first = pc[i].first;
					iMaxinHandString = switchString(pc[i].second);
					maxinHand.second = iMaxinHandString;
				}
			}
			lammaty.push_back(maxinHand);
		}
	vector < pair<int, int>>safe;
	for (int i = 0; i < Shapes.size(); i++) {
		for (int j = 0; j < Shapes[i].size(); j++) {
			int countingUnders = 0;
			for (int ik = i * 13; ik < ((i + 1) * 13) - 1; ik++) {
				if (CardDeck[ik].first < Shapes[i][j] && CardDeck[ik].first != -1) {
					countingUnders++;
				}
			}
			if (countingUnders <= 2) {
				bool okk = false;
				for (auto jk : lammaty) {
					if (Shapes[i][j] == jk.first&&jk.second == i) { okk = true; break; }
				}
				if (!okk)
					safe.push_back(make_pair(Shapes[i][j], i));
			}
		}
	}
	if (CardsOnGround.empty()) {

		int least = 20, elIndex, ite = 0, maxSafe = -1, elIndex2;	
		for (int jb = 0; jb < Shapes.size(); jb++) {
			int counter321 = 0;
			if (Shapes[jb].size() == 0)continue;
			for (int jk = 0; jk < safe.size(); jk++) {
				if (safe[jk].second == jb) {
					counter321++;
				}
			}
			if (counter321 > maxSafe) {
				maxSafe = counter321;
				elIndex2 = jb;
			}
		}

		for (auto k : Shapes) {
			if (k.size() < least&&k.size() != 0) {
				least = k.size();
				elIndex = ite;
			}
			ite++;
		}
		if (Lammat >= FinalCall) {
			if (Lammat == FinalCall) {
				int cou_nter = 0;
				for (auto k : safe) {
					if (k.second == elIndex) {
						cou_nter++;
					}
				}
				if (cou_nter >= 2) {
					wara2a.first = Shapes[elIndex][0];
					wara2a.second = switchInt(elIndex);
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;

				}
				else {
					wara2a.first = Shapes[elIndex2][0];
					wara2a.second = switchInt(elIndex2);
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;
				}
			}
			else {
				bool la2 = 0;
				for (int lp = 0; lp < Shapes.size(); lp++) {
					for (auto kp : Shapes[lp]) {
						la2 = 0;
						for (auto f : CardDeck) {
							if (f.second == switchInt(lp) && kp < f.first) {
								la2 = 1;
								break;
							}
						}
						if (!la2) {
							wara2a.first = kp;
							wara2a.second = switchInt(lp);
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							return wara2a;
						}
					}
				}
				int leastCard = 20, indEx;
				for (int lp = 0; lp < 4; lp++) {
					for (auto kp : Shapes[lp]) {
						if (kp < leastCard) {
							leastCard = kp;
							indEx = lp;
						}
					}
				}
				wara2a.first = leastCard;
				wara2a.second = switchInt(indEx);
				for (int jk = 0; jk < pc.size(); jk++) {
					if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
						pc.erase(pc.begin() + jk); break;
					}
				}
				return wara2a;
			}
		}
		else {
			//lw heyya wara2a wa7da hal3abha w 5alas
			if (least = 1) {
				wara2a.first = Shapes[elIndex][0];
				wara2a.second = switchInt(elIndex);
				for (int jk = 0; jk < lammaty.size(); jk++) {
					if (lammaty[jk].first == wara2a.first&&lammaty[jk].second == elIndex) {
						lammaty.erase(lammaty.begin() + jk);
					}
				}
				for (int jk = 0; jk < pc.size(); jk++) {
					if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
						pc.erase(pc.begin() + jk); break;
					}
				}
				return wara2a;
			}
			else {
				int counter9 = 0;
				for (int n = 0; n < safe.size(); n++) {
					if (safe[n].second == elIndex) {
						counter9++;
					}
				}
				for (auto n : lammaty) {
					if (n.second == elIndex) {
						if (counter9 >= 2 || (Shapes[elIndex].size() == 2 && counter9 == 1)) {
							wara2a.first = n.first;
							wara2a.second = switchInt(elIndex);
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							return wara2a;
						}
					}
				}
				if (counter9 >= 2) {
					wara2a.first = Shapes[elIndex][0];
					wara2a.second = switchInt(elIndex);
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;
				}
				else {
					wara2a.first = Shapes[elIndex2][0];
					wara2a.second = switchInt(elIndex2);
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;
				}
			}

		}
	}
	else if (!CardsOnGround.empty()) {
		int tuna, trumpp;
		string tunas;
		tuna = switchString(CardsOnGround[0].second);
		tunas = switchInt(tuna);
		trumpp = switchString(Trump);
		int maxOnGround = CardsOnGround[0].first;
		bool TrumpOnGround = 0;
		for (int v = 1; v < CardsOnGround.size(); v++)
		{
			if (CardsOnGround[v].first > maxOnGround&&CardsOnGround[v].second == tunas) {
				maxOnGround = CardsOnGround[v].first;
			}
			else if (CardsOnGround[v].second == Trump && CardsOnGround[0].second != Trump) {
				TrumpOnGround = 1;
			}
		}
		if (Lammat >= FinalCall) {
			if (Lammat == FinalCall) {
				if (Shapes[tuna].size() == 0) {
					pair<int, string> akbar7aga;
					akbar7aga.first = -1;
					for (auto jk : pc) {
						if (jk.first > akbar7aga.first&&jk.second != Trump) {
							akbar7aga.first = jk.first;
							akbar7aga.second = jk.second;
						}
					}
					if (akbar7aga.first == -1) {
						akbar7aga.first = pc[0].first;
						akbar7aga.second = pc[0].second;
					}
					wara2a.first = akbar7aga.first;
					wara2a.second = akbar7aga.second;
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;
				}
				else if (Shapes[tuna].size() == 1) {
					wara2a.first = Shapes[tuna][0];
					wara2a.second = tunas;
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;
				}
				else {
					int maxPlay = -1;
					for (auto k : Shapes[tuna]) {
						if (k < maxOnGround) {
							maxPlay = k;
						}
					}
					if (maxPlay == -1) {
						wara2a.first = Shapes[tuna][0];
						wara2a.second = tunas;
						for (int jk = 0; jk < pc.size(); jk++) {
							if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
								pc.erase(pc.begin() + jk); break;
							}
						}
						return wara2a;

					}
					else {
						wara2a.first = maxPlay;
						wara2a.second = tunas;
						for (int jk = 0; jk < pc.size(); jk++) {
							if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
								pc.erase(pc.begin() + jk); break;
							}
						}
						return wara2a;
					}
				}
			}
			else {
				if (Shapes[tuna].size() == 1) {
					wara2a.first = Shapes[tuna][0];
					wara2a.second = tunas;
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;
				}
				else if (Shapes[tuna].size() == 0 && tuna != trumpp) {
					if (Shapes[trumpp].size() != 0) {
						int maxTrumpOnGround = -1;
						for (auto gh : CardsOnGround) {
							if (gh.second == Trump && gh.first > maxTrumpOnGround) {
								maxTrumpOnGround = gh.first;
							}
						}
						if (maxTrumpOnGround == -1) {
							wara2a.first = Shapes[trumpp][Shapes[trumpp].size() - 1];
							wara2a.second = Trump;
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							return wara2a;
						}
						else {
							if (Shapes[trumpp][Shapes[trumpp].size() - 1] > maxTrumpOnGround) {
								wara2a.first = Shapes[trumpp][Shapes[trumpp].size() - 1];
								wara2a.second = Trump;
								for (int jk = 0; jk < pc.size(); jk++) {
									if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
										pc.erase(pc.begin() + jk); break;
									}
								}
								return wara2a;
							}
							else {
								int decisive = -1, colorr;
								for (int op = 0; op < 4; op++) {
									if (op = trumpp)continue;
									for (auto jk : Shapes[op]) {
										decisive = jk; colorr = op; break;
									}
								}
								if (decisive == -1) {
									decisive = Shapes[trumpp][0]; colorr = trumpp;
								}
								wara2a.first = decisive;
								wara2a.second = switchInt(colorr);
								for (int jk = 0; jk < pc.size(); jk++) {
									if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
										pc.erase(pc.begin() + jk); break;
									}
								}
								return wara2a;
							}
						}
					}
					else {
						pair<int, string> leastCard;
						leastCard.first= pc[0].first;
						leastCard.second = pc[0].second;
						for (auto kk : pc) {
							if (kk.first < leastCard.first) {
								leastCard.first = kk.first;
								leastCard.second = kk.second;
							}
						}
						wara2a.first = leastCard.first;
						wara2a.second = leastCard.second;
						for (int jk = 0; jk < pc.size(); jk++) {
							if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
								pc.erase(pc.begin() + jk); break;
							}
						}
						return wara2a;
					}
				}
				else if (Shapes[tuna].size() == 0 && tuna == trumpp) {
					pair<int, string> maxCard;
					maxCard.first = pc[0].first;
					maxCard.second = pc[0].second;
					for (auto ko : pc) {
						if (ko.first > maxCard.first) {
							maxCard.first = ko.first;
							maxCard.second = ko.second;
						}
					}
					wara2a.first = maxCard.first;
					wara2a.second = maxCard.second;
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;

				}

				else {
					for (auto ik : Shapes[tuna]) {
						if (ik > maxOnGround) {
							wara2a.first = ik;
							wara2a.second = tunas;
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							return wara2a;
						}
					}
					wara2a.first = Shapes[tuna][0];
					wara2a.second = tunas;
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					return wara2a;
				}
			}
		}
		else {
			if (Shapes[tuna].size() == 1) {
				wara2a.first = Shapes[tuna][0];
				wara2a.second = tunas;
				for (int jk = 0; jk < pc.size(); jk++) {
					if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
						pc.erase(pc.begin() + jk); break;
					}
				}
				return wara2a;
			}
			else if (Shapes[tuna].size() == 0) {
				if (FinalCall - Lammat < lammaty.size()) {
					string m3lsh;
					wara2a.first = lammaty[0].first;
					m3lsh = switchInt(lammaty[0].second);
					wara2a.second = m3lsh;
					for (int jk = 0; jk < pc.size(); jk++) {
						if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
							pc.erase(pc.begin() + jk); break;
						}
					}
					lammaty.erase(lammaty.begin());
					return wara2a;
				}
				else {
					pair <int, int> biggestUselessCard;
					biggestUselessCard.first = -1;
					for (int n = 0; n < Shapes.size(); n++) {
						if (n == trumpp)continue;
						for (int na = 0; na < Shapes[n].size(); na++) {
							for (int b = 0; b < lammaty.size(); b++) {
								if (Shapes[n][na] != lammaty[b].first&&Shapes[n][na] > biggestUselessCard.first) {
									biggestUselessCard.first = Shapes[n][na];
									biggestUselessCard.second = n;
								}
							}
						}
					}
					if (biggestUselessCard.first == -1) {
						if (CardsOnGround[0].second != Trump) {
							if (Shapes[trumpp].size() != 0) {
								wara2a.first = Shapes[trumpp][0];
								wara2a.second = Trump;
								for (int jk = 0; jk < pc.size(); jk++) {
									if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
										pc.erase(pc.begin() + jk); break;
									}
								}
								for (int jk = 0; jk < lammaty.size(); jk++) {
									if (lammaty[jk].first == wara2a.first&&switchInt(lammaty[jk].second) == wara2a.second)
										lammaty.erase(lammaty.begin() + jk);
								}
								return wara2a;
							}
							else {
								wara2a.first = lammaty[0].first;
								wara2a.second = switchInt(lammaty[0].second);
								for (int jk = 0; jk < pc.size(); jk++) {
									if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
										pc.erase(pc.begin() + jk); break;
									}
								}
								lammaty.erase(lammaty.begin());
								return wara2a;
							}
						}
						else {
							wara2a.first = lammaty[0].first;
							wara2a.second = switchInt(lammaty[0].second);
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							lammaty.erase(lammaty.begin());
							return wara2a;
						}
					}
					else {
						wara2a.first = biggestUselessCard.first;
						wara2a.second = switchInt(biggestUselessCard.second);
						for (int jk = 0; jk < pc.size(); jk++) {
							if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
								pc.erase(pc.begin() + jk); break;
							}
						}
						return wara2a;
					}
				}
			}
			for (int j = 0; j < lammaty.size(); j++) {
				if (lammaty[j].second == tuna) {
					int counte = 0;
					for (int hk = 0; hk < safe.size(); hk++) {
						if (safe[hk].second == tuna) {
							counte++;
						}
					}
					if (counte >= 2) {
						wara2a.first = lammaty[j].first;
						wara2a.second = tunas;
						for (int jk = 0; jk < pc.size(); jk++) {
							if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
								pc.erase(pc.begin() + jk); break;
							}
						}
						lammaty.erase(lammaty.begin() + j);
						return wara2a;

					}
					else {
						int kwysAwy = -1;
						for (int i = 0; i < Shapes[tuna].size(); i++) {
							if (TrumpOnGround) {
								if (FinalCall - Lammat < lammaty.size()) {
									wara2a.first = lammaty[j].first;
									wara2a.second = tunas;
									lammaty.erase(lammaty.begin() + j);
									for (int jk = 0; jk < pc.size(); jk++) {
										if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
											pc.erase(pc.begin() + jk); break;
										}
									}

								}

								else {
									for (int fi = 0; fi < lammaty.size(); fi++) {
										for (int f = 0; f < Shapes[tuna].size(); f++) {
											if (lammaty[fi].second == tuna && lammaty[fi].first == Shapes[tuna][f]) {
												if (f != 0) {
													wara2a.first = Shapes[tuna][f - 1];
													wara2a.second = tunas;
												}
												else {
													wara2a.first == lammaty[j].first;
													wara2a.second = tunas;
													lammaty.erase(lammaty.begin() + j);
													for (int jk = 0; jk < pc.size(); jk++) {
														if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
															pc.erase(pc.begin() + jk); break;
														}
													}
													return wara2a;
												}
											}
										}
									}
								}
								for (int jk = 0; jk < pc.size(); jk++) {
									if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
										pc.erase(pc.begin() + jk); break;
									}
								}
								return wara2a;
							}
							if (maxOnGround > Shapes[tuna][i] && Shapes[tuna][i] > kwysAwy) {
								kwysAwy = Shapes[tuna][i];
							}
						}
						if (kwysAwy != -1) {
							wara2a.first = kwysAwy;
							wara2a.second = tunas;
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							return wara2a;
						}
						else {
							wara2a.first = lammaty[j].first;
							wara2a.second = tunas;
							for (int jk = 0; jk < pc.size(); jk++) {
								if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
									pc.erase(pc.begin() + jk); break;
								}
							}
							return wara2a;
						}
					}
				}
				if (j == lammaty.size() - 1) {
					int kwysAwy = -1;
					for (int y = 0; y < Shapes[tuna].size(); y++) {
						if (maxOnGround > Shapes[tuna][y] && Shapes[tuna][y] > kwysAwy) {
							kwysAwy = Shapes[tuna][y];
						}
					}
					if (kwysAwy != -1) {
						wara2a.first = kwysAwy;
						wara2a.second = tunas;
						for (int jk = 0; jk < pc.size(); jk++) {
							if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
								pc.erase(pc.begin() + jk); break;
							}
						}
						return wara2a;
					}
					else {
						if (CardsOnGround.size() == 3) {
							wara2a.first = Shapes[tuna][Shapes[tuna].size() - 1];
						}
						else wara2a.first = Shapes[tuna][0];
						wara2a.second = tunas;
						for (int jk = 0; jk < pc.size(); jk++) {
							if (pc[jk].first == wara2a.first && pc[jk].second == wara2a.second) {
								pc.erase(pc.begin() + jk); break;
							}
						}
					}
				}
			}

		}
	}
	}		return wara2a;
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

bool  AiPlayer::dashCall(vector < pair<int, string>> pc)
{
	vector<int>comp;
	vector<pair<int, string>>Counter;
	int counterS = 0;
	int counterH = 0;
	int counterD = 0;
	int counterE = 0;
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
}
string AiPlayer::switchInt(int x) {
	string k;
	if (x == 0) { k = "Spades"; }
	if (x == 1) { k = "Hearts"; }
	if (x == 2) { k = "Diamonds"; }
	if (x == 3) { k = "EClubs"; }
	return k;
}
int AiPlayer::switchString(string x) {
	int k;
	if (x == "Spades") { k = 0; }
	if (x == "Hearts") { k = 1; }
	if (x == "Diamonds") { k = 2; }
	if (x == "EClubs") { k = 3; }
	return k;
}

int AiPlayer::score(int call, int lammat, bool risk, bool dash, bool trump, bool with, string gameStatus, int numWinners, int numLoosers)
{
	int score = 0;
	if (call == lammat) {
		if (dash) {
			if (gameStatus == "Over") {
				score += 25;
			}
			else {
				score += 33;
			}
			if (numWinners == 1) {
				score += 10;
			}
			return score;
		}
		if (risk && !dash) {
			score += 10;
		}
		if (numWinners == 1) {
			score += 10;
		}
		if (!dash&&(trump || with)) {
			score += 10;
		}
		if (call != 0) {
			score += lammat;
			score += 10;
		}
	}

	if (call != lammat) {
		if (dash) {
			if (gameStatus == "Over") {
				score -= 25;
			}
			else {
				score -= 33;
			}
			if (numLoosers == 1)score -= 10;
			return score;
		}
		if (risk) {
			score -= 10;
		}
		if (numLoosers == 1) {
			score -= 10;
		}
		if (trump || with) {
			score -= 10;
		}
		if (call != 0) {
			int totalLammat = abs(lammat - call);
			score -= totalLammat;
		}
	}
	return score;
}
AiPlayer::~AiPlayer()
{
}

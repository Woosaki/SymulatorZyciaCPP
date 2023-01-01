#pragma once
#include "Organizm.h"
#include <vector>
#include <algorithm>
#include <iostream>

const int N = 20;

class Organizm;

class Swiat
{
	Organizm* mapa[N][N];
	std::vector <Organizm*> kolejnosc;
	int liczbaOrganizmow;
public:
	Swiat();
	void wykonajTure();
	void rysujSwiat();

	void dodajOrganizmNaMape(Organizm* organizm);
	bool czyZajeteMiejsce(int x, int y);
	int iloscOrganizmow();
	void ruchOrganizmu(Organizm* organizm);
	void sortOrganizmow();
};


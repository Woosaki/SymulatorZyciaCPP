#pragma once
#include "Organizm.h"
#include <vector>

const int N = 20;

class Organizm;

class Swiat
{
	Organizm* mapa[N][N];
	std::vector <Organizm*> organizmy;
public:
	Swiat();
	void wykonajTure();
	void rysujSwiat();

	void dodajOrganizmNaMape(Organizm* organizm, int x, int y);
};


#pragma once
#include "Organizm.h"
#include <vector>
#include <algorithm>
#include <iostream>

const int N = 20;

class Organizm;

class Swiat {
	Organizm* mapa[N][N];
	std::vector <Organizm*> kolejnosc;
public:
	Swiat();
	void wykonajTure();
	void rysujSwiat();

	void dodajOrganizmNaMape(Organizm* organizm);
	bool czyZajeteMiejsce(int x, int y);
	Organizm* organizmNaPolu(int x, int y);
	void przesunOrganizm(Organizm* organizm, int x, int y);
	void przesunOrganizmLosowo(Organizm* organizm);
	void sortOrganizmow();
	void usunOrganizm(Organizm* organizm);
	bool czyWolnePoleObok(Organizm* organizm);
};


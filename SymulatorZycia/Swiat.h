#pragma once
#include "Organizm.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

const int N = 20;

class Organizm;

class Swiat {
	Organizm* mapa[N][N];
	std::vector <Organizm*> kolejnosc;
	int tura;
	int iloscNowychOrganizmow;
public:
	Swiat();
	void wykonajTure();
	void rysujSwiat();

	int getTura();

	void zwiekszIloscNowychOrganizmow();
	void dodajLosowoOrganizmNaMape(Organizm* organizm);
	void dodajOrganizmNaMape(Organizm* organizm, int x, int y);
	void dodajDoKolejki(Organizm* organizm);
	bool czyZajeteMiejsce(int x, int y);
	Organizm* organizmNaPolu(int x, int y);
	void przesunOrganizm(Organizm* organizm, int x, int y);
	void przesunOrganizmLosowo(Organizm* organizm);
	void sortOrganizmow();
	void usunOrganizm(Organizm* organizm);
	bool wspolrzednePozaMapa(int x, int y);
	bool czyWolnePoleObok(Organizm* organizm);
	void zapiszSwiat();
	void wczytajSwiat();
};


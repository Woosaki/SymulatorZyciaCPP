#pragma once
#include <iostream>
#include "Swiat.h"

class Swiat;

class Organizm {
protected:
	int sila;
	int inicjatywa;
	int x;
	int y;
	int wiek;
	Swiat* swiat;
public:

	Organizm(Swiat* swiat);

	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizm) = 0;
	virtual char rysowanie() = 0;
	virtual std::string nazwa() = 0;
	virtual void rozmnazanie() = 0;

	int getX();
	int getY();
	int getInicjatywa();
	int getSila();
	int getWiek();

	void ustawXY(int x, int y);
	void ustawSila(int sila);
	void ustawInicjatywa(int inicjatywa);
	void ustawWiek(int wiek);

	void zwiekszWiek();
	bool czyRoslina();
	void rozmnoz(Organizm* organizm);

	virtual ~Organizm() {}
};


#pragma once
#include <iostream>
#include "Swiat.h"

class Swiat;

class Organizm
{
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
	virtual void kolizja() = 0;
	virtual char rysowanie() = 0;

	void ustawXY(int x, int y);

	virtual ~Organizm() {}
};


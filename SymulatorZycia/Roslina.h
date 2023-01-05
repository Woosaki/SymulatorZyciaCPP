#pragma once
#include <iostream>
#include "Organizm.h"

class Roslina : public Organizm {
public:
	Roslina(Swiat* swiat) : Organizm(swiat) {}

	virtual void akcja();
	virtual void kolizja(Organizm* organizm);
	virtual char rysowanie() = 0;
	virtual std::string nazwa() = 0;
	virtual void rozmnazanie(Swiat* swiat, int x, int y) = 0;

	virtual ~Roslina() {}
};


#pragma once
#include <iostream>
#include "Zwierze.h"

class Zmija : public Zwierze {
public:
	Zmija(Swiat* swiat);

	virtual char rysowanie();
	virtual void kolizja(Organizm* organizm);
	virtual std::string nazwa();
	virtual void rozmnazanie();

	virtual ~Zmija() {}
};


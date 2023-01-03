#pragma once
#include <iostream>
#include "Zwierze.h"

class Zmija : public Zwierze {
public:
	Zmija(Swiat* swiat);

	virtual void kolizja(Organizm* organizm);
	virtual char rysowanie();
	virtual std::string nazwa();

	virtual ~Zmija() {}
};


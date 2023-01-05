#pragma once
#include <iostream>
#include "Roslina.h"

class Ciern : public Roslina {
public:
	Ciern(Swiat* swiat);

	virtual void akcja();
	virtual void kolizja(Organizm* organizm);
	virtual char rysowanie();
	virtual std::string nazwa();
	virtual void rozmnazanie(Swiat* swiat, int x, int y);

	virtual ~Ciern() {}
};


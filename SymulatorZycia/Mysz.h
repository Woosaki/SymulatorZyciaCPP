#pragma once
#include <iostream>
#include "Zwierze.h"

class Mysz : public Zwierze {
public:
	Mysz(Swiat* swiat);

	virtual void kolizja(Organizm* organizm);
	virtual char rysowanie();
	virtual std::string nazwa();

	virtual ~Mysz() {}
};


#pragma once
#include <iostream>
#include "Organizm.h"
#include "Roslina.h"

class Zwierze : public Organizm {
public:
	Zwierze(Swiat* swiat) : Organizm(swiat) {}

	virtual void akcja();
	virtual void kolizja(Organizm* organizm);
	virtual char rysowanie() = 0;
	virtual std::string nazwa() = 0;

	virtual ~Zwierze() {}
};


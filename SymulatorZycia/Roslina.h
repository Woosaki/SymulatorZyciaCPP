#pragma once
#include <iostream>
#include "Organizm.h"

class Roslina : public Organizm
{
public:
	Roslina(Swiat* swiat) : Organizm(swiat) {}

	virtual void akcja();
	virtual void kolizja();
	virtual char rysowanie() = 0;

	virtual ~Roslina() {}
};


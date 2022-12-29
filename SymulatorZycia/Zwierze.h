#pragma once
#include <iostream>
#include "Organizm.h"

class Zwierze : public Organizm
{
public:
	Zwierze(Swiat* swiat) : Organizm(swiat) {}

	virtual void akcja();
	virtual void kolizja();
	virtual char rysowanie() = 0;

	virtual ~Zwierze() {}
};


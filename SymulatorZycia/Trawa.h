#pragma once
#include <iostream>
#include "Roslina.h"

class Trawa : public Roslina
{
public:
	Trawa(Swiat* swiat) : Roslina(swiat) {}

	virtual void akcja();
	virtual void kolizja();
	virtual char rysowanie();

	virtual ~Trawa() {}
};


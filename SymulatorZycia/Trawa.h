#pragma once
#include <iostream>
#include "Roslina.h"

class Trawa : public Roslina {
public:
	Trawa(Swiat* swiat) : Roslina(swiat) {}

	virtual char rysowanie();
	virtual std::string nazwa();
	virtual void rozmnazanie(Swiat* swiat, int x, int y);

	virtual ~Trawa() {}
};


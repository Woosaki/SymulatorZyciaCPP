#pragma once
#include <iostream>
#include "Roslina.h"

class Trawa : public Roslina {
public:
	Trawa(Swiat* swiat) : Roslina(swiat) {}

	virtual char rysowanie();
	virtual std::string nazwa();

	virtual ~Trawa() {}
};


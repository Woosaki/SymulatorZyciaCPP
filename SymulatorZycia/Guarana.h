#pragma once
#include <iostream>
#include "Roslina.h"

class Guarana : public Roslina {
public:
	Guarana(Swiat* swiat) : Roslina(swiat) {}

	virtual void kolizja(Organizm* organizm);
	virtual char rysowanie();
	virtual std::string nazwa();
	virtual void rozmnazanie(Swiat* swiat, int x, int y);

	virtual ~Guarana() {}
};


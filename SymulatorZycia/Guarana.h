#pragma once
#include <iostream>
#include "Roslina.h"

class Guarana : public Roslina
{
public:
	Guarana(Swiat* swiat) : Roslina(swiat) {}

	virtual void akcja();
	virtual void kolizja();
	virtual char rysowanie();

	virtual ~Guarana() {}
};


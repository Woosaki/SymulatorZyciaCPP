#pragma once
#include <iostream>
#include "Roslina.h"

class Ciern : public Roslina
{
public:
	Ciern(Swiat* swiat);

	virtual void akcja();
	virtual void kolizja();
	virtual char rysowanie();

	virtual ~Ciern() {}
};


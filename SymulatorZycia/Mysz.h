#pragma once
#include <iostream>
#include "Zwierze.h"

class Mysz : public Zwierze
{
public:
	Mysz(Swiat* swiat);

	virtual void akcja();
	virtual void kolizja();
	virtual char rysowanie();

	virtual ~Mysz() {}
};


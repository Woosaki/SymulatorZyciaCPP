#pragma once
#include <iostream>
#include "Zwierze.h"

class Zmija : public Zwierze
{
public:
	Zmija(Swiat* swiat);

	virtual void akcja();
	virtual void kolizja();
	virtual char rysowanie();

	virtual ~Zmija() {}
};


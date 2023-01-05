#pragma once
#include <iostream>
#include "Zwierze.h"

class Zmija : public Zwierze {
public:
	Zmija(Swiat* swiat);

	virtual char rysowanie();
	virtual std::string nazwa();
	virtual void rozmnazanie(Swiat* swiat, int x, int y);

	virtual ~Zmija() {}
};


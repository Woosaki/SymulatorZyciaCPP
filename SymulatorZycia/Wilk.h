#pragma once
#include <iostream>
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
	Wilk(Swiat* swiat);

	virtual char rysowanie();
	virtual std::string nazwa();
	virtual void rozmnazanie(Swiat* swiat, int x, int y);

	virtual ~Wilk() {}
};


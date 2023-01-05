#pragma once
#include <iostream>
#include "Zwierze.h"

class Leniwiec : public Zwierze {
public:
	Leniwiec(Swiat* swiat);

	virtual void akcja();
	virtual char rysowanie();
	virtual std::string nazwa();
	virtual void rozmnazanie(Swiat* swiat, int x, int y);

	virtual ~Leniwiec() {}
};


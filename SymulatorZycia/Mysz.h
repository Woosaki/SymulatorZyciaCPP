#pragma once
#include <iostream>
#include "Zwierze.h"

class Mysz : public Zwierze {
public:
	Mysz(Swiat* swiat);

	virtual char rysowanie();
	virtual std::string nazwa();
	virtual void rozmnazanie();

	virtual ~Mysz() {}
};


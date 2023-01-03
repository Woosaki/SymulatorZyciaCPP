#pragma once
#include <iostream>
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
	Wilk(Swiat* swiat);

	virtual char rysowanie();
	virtual std::string nazwa();

	virtual ~Wilk() {}
};


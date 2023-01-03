#pragma once
#include <iostream>
#include "Zwierze.h"

class Owca : public Zwierze {
public:
	Owca(Swiat* swiat);

	virtual char rysowanie();
	virtual std::string nazwa();

	virtual ~Owca() {}
};


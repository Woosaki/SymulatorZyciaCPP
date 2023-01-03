#pragma once
#include <iostream>
#include "Zwierze.h"

class Leniwiec : public Zwierze {
public:
	Leniwiec(Swiat* swiat);

	virtual void akcja();
	virtual void kolizja(Organizm* organizm);
	virtual char rysowanie();
	virtual std::string nazwa();

	virtual ~Leniwiec() {}
};


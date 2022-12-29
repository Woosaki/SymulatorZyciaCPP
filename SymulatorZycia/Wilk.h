#pragma once
#include <iostream>
#include "Zwierze.h"

class Wilk : public Zwierze
{
public:
	Wilk(Swiat* swiat);

	virtual void akcja();
	virtual void kolizja();
	virtual char rysowanie();

	virtual ~Wilk() {}
};


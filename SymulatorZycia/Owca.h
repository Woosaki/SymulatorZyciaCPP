#pragma once
#include <iostream>
#include "Zwierze.h"

class Owca : public Zwierze
{
public:
	Owca(Swiat* swiat);

	virtual void akcja();
	virtual void kolizja();
	virtual char rysowanie();

	virtual ~Owca() {}
};


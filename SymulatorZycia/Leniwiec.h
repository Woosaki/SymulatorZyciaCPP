#pragma once
#include <iostream>
#include "Zwierze.h"

class Leniwiec : public Zwierze
{
public:
	Leniwiec(Swiat* swiat);

	virtual void akcja();
	virtual void kolizja();
	virtual char rysowanie();

	virtual ~Leniwiec() {}
};


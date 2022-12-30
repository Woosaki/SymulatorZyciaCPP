#include "Organizm.h"

Organizm::Organizm(Swiat* swiat)
	: swiat{ swiat }, sila{ 0 }, inicjatywa{ 0 }, x{ 0 }, y{ 0 }, wiek{ 0 } {}

void Organizm::ustawXY(int x, int y) {
	this->x = x;
	this->y = y;
}
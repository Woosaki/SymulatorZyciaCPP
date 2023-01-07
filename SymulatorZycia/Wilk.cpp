#include "Wilk.h"

Wilk::Wilk(Swiat* swiat) : Zwierze(swiat) {
	sila = 9;
	inicjatywa = 5;
}

void Wilk::rozmnazanie() {
	Organizm* organizm = new Wilk(swiat);
	rozmnoz(organizm);
}

char Wilk::rysowanie() {
	return 'W';
}

std::string Wilk::nazwa() {
	return "WILK";
}
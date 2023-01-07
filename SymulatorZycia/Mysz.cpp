#include "Mysz.h"

Mysz::Mysz(Swiat* swiat) : Zwierze(swiat) {
	sila = 1;
	inicjatywa = 6;
}

void Mysz::rozmnazanie() {
	Organizm* organizm = new Mysz(swiat);
	rozmnoz(organizm);
}

char Mysz::rysowanie() {
	return 'M';
}

std::string Mysz::nazwa() {
	return "MYSZ";
}


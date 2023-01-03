#include "Mysz.h"

Mysz::Mysz(Swiat* swiat) : Zwierze(swiat) {
	sila = 1;
	inicjatywa = 6;
}

void Mysz::kolizja(Organizm* organizm) {

	Zwierze::kolizja(organizm);
}

char Mysz::rysowanie() {
	return 'M';
}

std::string Mysz::nazwa() {
	return "MYSZ";
}


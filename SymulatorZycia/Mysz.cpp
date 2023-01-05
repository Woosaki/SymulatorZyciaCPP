#include "Mysz.h"

Mysz::Mysz(Swiat* swiat) : Zwierze(swiat) {
	sila = 1;
	inicjatywa = 6;
}

void Mysz::rozmnazanie(Swiat* swiat, int x, int y) {
	Organizm* organizm = new Mysz(swiat);
	swiat->dodajOrganizmNaMape(organizm, x, y);
	swiat->przesunOrganizmLosowo(organizm);
	swiat->zwiekszIloscNowychOrganizmow();
}

char Mysz::rysowanie() {
	return 'M';
}

std::string Mysz::nazwa() {
	return "MYSZ";
}


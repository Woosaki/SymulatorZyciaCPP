#include "Wilk.h"

Wilk::Wilk(Swiat* swiat) : Zwierze(swiat) {
	sila = 9;
	inicjatywa = 5;
}

void Wilk::rozmnazanie(Swiat* swiat, int x, int y) {
	Organizm* organizm = new Wilk(swiat);
	swiat->dodajOrganizmNaMape(organizm, x, y);
	swiat->przesunOrganizmLosowo(organizm);
	swiat->zwiekszIloscNowychOrganizmow();
}

char Wilk::rysowanie() {
	return 'W';
}

std::string Wilk::nazwa() {
	return "WILK";
}
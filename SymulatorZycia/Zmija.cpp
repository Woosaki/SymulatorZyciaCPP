#include "Zmija.h"

Zmija::Zmija(Swiat* swiat) : Zwierze(swiat) {
	sila = 2;
	inicjatywa = 3;
}

void Zmija::rozmnazanie(Swiat* swiat, int x, int y) {
	Organizm* organizm = new Zmija(swiat);
	swiat->dodajOrganizmNaMape(organizm, x, y);
	swiat->przesunOrganizmLosowo(organizm);
	swiat->zwiekszIloscNowychOrganizmow();
}

char Zmija::rysowanie() {
	return 'Z';
}

std::string Zmija::nazwa() {
	return "ZMIJA";
}
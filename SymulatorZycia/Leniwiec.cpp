#include "Leniwiec.h"

Leniwiec::Leniwiec(Swiat* swiat) : Zwierze(swiat) {
	sila = 2;
	inicjatywa = 1;
}

void Leniwiec::akcja() {
	if (wiek % 2 == 0)
		Zwierze::akcja();
}

void Leniwiec::rozmnazanie(Swiat* swiat, int x, int y) {
	Organizm* organizm = new Leniwiec(swiat);
	swiat->dodajOrganizmNaMape(organizm, x, y);
	swiat->przesunOrganizmLosowo(organizm);
	swiat->zwiekszIloscNowychOrganizmow();
}

char Leniwiec::rysowanie() {
	return 'L';
}

std::string Leniwiec::nazwa() {
	return "LENIWIEC";
}

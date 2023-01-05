#include "Owca.h"

Owca::Owca(Swiat* swiat) : Zwierze(swiat) {
	sila = 4;
	inicjatywa = 4;
}

void Owca::rozmnazanie(Swiat* swiat, int x, int y) {
	Organizm* organizm = new Owca(swiat);
	swiat->dodajOrganizmNaMape(organizm, x, y);
	swiat->przesunOrganizmLosowo(organizm);
	swiat->zwiekszIloscNowychOrganizmow();
}

char Owca::rysowanie() {
	return 'O';
}

std::string Owca::nazwa() {
	return "OWCA";
}
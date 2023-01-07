#include "Owca.h"

Owca::Owca(Swiat* swiat) : Zwierze(swiat) {
	sila = 4;
	inicjatywa = 4;
}

void Owca::rozmnazanie() {
	Organizm* organizm = new Owca(swiat);
	rozmnoz(organizm);
}

char Owca::rysowanie() {
	return 'O';
}

std::string Owca::nazwa() {
	return "OWCA";
}
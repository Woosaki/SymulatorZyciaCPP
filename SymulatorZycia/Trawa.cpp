#include "Trawa.h"

void Trawa::rozmnazanie() {
	Organizm* organizm = new Trawa(swiat);
	rozmnoz(organizm);
}

char Trawa::rysowanie() {
	return 'T';
}

std::string Trawa::nazwa() {
	return "TRAWA";
}
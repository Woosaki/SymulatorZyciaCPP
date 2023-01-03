#include "Owca.h"

Owca::Owca(Swiat* swiat) : Zwierze(swiat) {
	sila = 4;
	inicjatywa = 4;
}

char Owca::rysowanie() {
	return 'O';
}

std::string Owca::nazwa() {
	return "OWCA";
}
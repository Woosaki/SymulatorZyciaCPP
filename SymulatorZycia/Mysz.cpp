#include "Mysz.h"

Mysz::Mysz(Swiat* swiat) : Zwierze(swiat) {
	sila = 1;
	inicjatywa = 6;
}

char Mysz::rysowanie() {
	return 'M';
}

std::string Mysz::nazwa() {
	return "MYSZ";
}


#include "Mysz.h"

Mysz::Mysz(Swiat* swiat) : Zwierze(swiat) {
	sila = 1;
	inicjatywa = 6;
}

void Mysz::akcja() {


}

void Mysz::kolizja() {


}


char Mysz::rysowanie() {
	return 'M';
}


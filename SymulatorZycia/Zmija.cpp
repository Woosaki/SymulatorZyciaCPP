#include "Zmija.h"

Zmija::Zmija(Swiat* swiat) : Zwierze(swiat) {
	sila = 2;
	inicjatywa = 3;
}

void Zmija::akcja() {


}

void Zmija::kolizja() {


}


char Zmija::rysowanie() {
	return 'Z';
}
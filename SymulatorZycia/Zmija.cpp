#include "Zmija.h"

Zmija::Zmija(Swiat* swiat) : Zwierze(swiat) {
	sila = 2;
	inicjatywa = 3;
}

void Zmija::kolizja(Organizm* organizm) {
	Zwierze::kolizja(organizm);

}

char Zmija::rysowanie() {
	return 'Z';
}

std::string Zmija::nazwa() {
	return "ZMIJA";
}
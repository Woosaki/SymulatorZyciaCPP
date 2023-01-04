#include "Leniwiec.h"

Leniwiec::Leniwiec(Swiat* swiat) : Zwierze(swiat) {
	sila = 2;
	inicjatywa = 1;
}

void Leniwiec::akcja() {
	if (wiek % 2 == 0)
		Zwierze::akcja();
}

char Leniwiec::rysowanie() {
	return 'L';
}

std::string Leniwiec::nazwa() {
	return "LENIWIEC";
}

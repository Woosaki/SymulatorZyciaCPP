#include "Leniwiec.h"

Leniwiec::Leniwiec(Swiat* swiat) : Zwierze(swiat) {
	sila = 2;
	inicjatywa = 1;
}

void Leniwiec::akcja() {


}

void Leniwiec::kolizja() {


}


char Leniwiec::rysowanie() {
	return 'L';
}


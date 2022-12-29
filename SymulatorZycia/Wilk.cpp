#include "Wilk.h"

Wilk::Wilk(Swiat* swiat) : Zwierze(swiat) {
	sila = 9;
	inicjatywa = 5;
}

void Wilk::akcja() {


}

void Wilk::kolizja() {


}


char Wilk::rysowanie() {
	return 'W';
}
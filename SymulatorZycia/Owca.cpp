#include "Owca.h"

Owca::Owca(Swiat* swiat) : Zwierze(swiat) {
	sila = 4;
	inicjatywa = 4;
}

void Owca::akcja() {


}

void Owca::kolizja() {


}


char Owca::rysowanie() {
	return 'O';
}

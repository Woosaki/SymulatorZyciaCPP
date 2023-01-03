#include "Ciern.h"

Ciern::Ciern(Swiat* swiat) : Roslina(swiat) {
	sila = 2;
}

void Ciern::akcja() {


}

void Ciern::kolizja(Organizm* organizm) {
	if (sila >= organizm->getSila()) {
		swiat->usunOrganizm(organizm);
		std::cout << nazwa() << " pokonal atakujacego\n\n";
	}
	else
		Roslina::kolizja(organizm);
}

char Ciern::rysowanie() {
	return 'C';
}

std::string Ciern::nazwa() {
	return "CIERN";
}
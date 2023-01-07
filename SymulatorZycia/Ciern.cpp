#include "Ciern.h"

Ciern::Ciern(Swiat* swiat) : Roslina(swiat) {
	sila = 2;
}

void Ciern::akcja() {
	int czyRozmnozyc = rand() % 5;
	if (czyRozmnozyc == 0) {
		if (swiat->czyWolnePoleObok(this)) {
			rozmnazanie();
			std::cout << nazwa() << " rozprzestrzenia sie na polu (" << x << ", " << y << ")\n\n";
		}
		else
			std::cout << nazwa() << " nie mogl sie rozprzestrzenic na polu (" << x << ", " << y << "), gdyz nie bylo miejsca obok\n\n";
	}
}

void Ciern::kolizja(Organizm* organizm) {
	if (sila >= organizm->getSila()) {
		std::cout << nazwa() << " pokonal " << organizm->nazwa() << " na polu (" << x << ", " << y << ")\n\n";
		swiat->usunOrganizm(organizm);	
	}
	else
		Roslina::kolizja(organizm);
}

void Ciern::rozmnazanie() {
	Organizm* organizm = new Ciern(swiat);
	rozmnoz(organizm);
}

char Ciern::rysowanie() {
	return 'C';
}

std::string Ciern::nazwa() {
	return "CIERN";
}
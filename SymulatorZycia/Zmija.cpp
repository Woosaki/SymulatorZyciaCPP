#include "Zmija.h"

Zmija::Zmija(Swiat* swiat) : Zwierze(swiat) {
	sila = 2;
	inicjatywa = 3;
}

void Zmija::kolizja(Organizm* organizm) {
	if (organizm->czyRoslina())
		Zwierze::kolizja(organizm);	
	else if (organizm->rysowanie() == 'Z')
		if(czyRozmnozyc(organizm))
			rozmnazanie();
	else if (sila <= organizm->getSila()) {
		std::cout << nazwa() << " zatruwa " << organizm->nazwa() << " i oba organizmy gina na polu ("
			<< organizm->getX() << ", " << organizm->getY() << ")\n\n";
		swiat->usunOrganizm(organizm);
		swiat->usunOrganizm(this);
	}
	else
		Zwierze::kolizja(organizm);
}

void Zmija::rozmnazanie() {
	Organizm* organizm = new Zmija(swiat);
	rozmnoz(organizm);
}

char Zmija::rysowanie() {
	return 'Z';
}

std::string Zmija::nazwa() {
	return "ZMIJA";
}
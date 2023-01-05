#include "Zwierze.h"

void Zwierze::akcja() {
	int x = getX();
	int y = getY();
	do {
		x = getX();
		y = getY();

		switch (rand() % 8) {
		case 0:
			x--;
			y--;
			break;
		case 1:
			y--;
			break;
		case 2:
			x++;
			y--;
			break;
		case 3:
			x++;
			break;
		case 4:
			x++;
			y++;
			break;
		case 5:
			y++;
			break;
		case 6:
			x--;
			y++;
			break;
		case 7:
			x--;
			break;
		}
	} while (swiat->wspolrzednePozaMapa(x, y));
	if (swiat->czyZajeteMiejsce(x, y))
		kolizja(swiat->organizmNaPolu(x, y));
	else
		swiat->przesunOrganizm(this, x, y);
}

void Zwierze::kolizja(Organizm* organizm) {
	//jesli kolizja z roslina
	if (organizm->czyRoslina())
		organizm->kolizja(this);
	else {
		int organizmX = organizm->getX();
		int organizmY = organizm->getY();
		//jesli kolizja z tym samym gatunkiem
		if (rysowanie() == organizm->rysowanie()) {
			if (!swiat->czyWolnePoleObok(organizm))
				std::cout << nazwa() << " nie moze sie rozmnozyc na polu (" << x << "," << y << "), gdyz nie ma miejsca obok!\n\n";
			else {
				std::cout << nazwa() << " sie rozmnaza na polu (" << x << "," << y << ")\n\n";
				organizm->rozmnazanie(swiat, organizmX, organizmY);
				swiat->przesunOrganizm(organizm, organizmX, organizmY);
			}	
		}
		//zmija jest atakowana przez silniejszy organizm
		else if (organizm->rysowanie() == 'Z' && sila >= organizm->getSila()) {
			std::cout << "Atakujacy " << nazwa() << " pokonuje " << organizm->nazwa() << ", lecz ta go zatruwa "
				<< "i oba organizmy gina na polu (" << organizmX << ", " << organizmY << ")\n\n";
			swiat->usunOrganizm(organizm);
			swiat->usunOrganizm(this);		
		}
		//zmija atakuje silniejszy organizm
		else if (rysowanie() == 'Z' && sila <= organizm->getSila()) {
			std::cout << nazwa() << " zatruwa " << organizm->nazwa() << " i oba organizmy gina na polu ("
				<< organizmX << ", " << organizmY << ")\n\n";
			swiat->usunOrganizm(organizm);
			swiat->usunOrganizm(this);	
		}
		//jesli kolizja z mysza organizmu nie bedacym zmija z pustym polem obok
		else if (rysowanie() != 'Z' && organizm->rysowanie() == 'M' && swiat->czyWolnePoleObok(organizm)) {
			std::cout << organizm->nazwa() << " uciekla na sasiednie pole przed " << nazwa()
				<< " na polu (" << organizmX << ", " << organizmY << ")\n\n";
			swiat->przesunOrganizmLosowo(organizm);
			swiat->przesunOrganizm(this, organizmX, organizmY);
		}	
		//zwykla walka organizmow
		else {
			std::cout << "Doszlo do walki pomiedzy " << nazwa() << " a " << organizm->nazwa() 
				<< " na polu (" << organizmX << ", " << organizmY << ")\n";
			if (sila >= organizm->getSila()) {
				
				swiat->usunOrganizm(organizm);
				swiat->przesunOrganizm(this, organizmX, organizmY);
				std::cout << "Atakujacy " << nazwa() << " okazal sie silniejszy\n\n";
			}
			else {
				swiat->usunOrganizm(this);
				std::cout << "Broniacy " << organizm->nazwa() << " okazal sie silniejszy\n\n";
			}
		}
	}
}
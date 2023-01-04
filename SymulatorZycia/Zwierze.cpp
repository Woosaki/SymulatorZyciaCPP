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
	} while (x == -1 || y == -1 || x == 20 || y == 20);

	if (swiat->czyZajeteMiejsce(x, y)) {
		kolizja(swiat->organizmNaPolu(x, y));
	}
	else {
		swiat->przesunOrganizm(this, x, y);
	}
}

void Zwierze::kolizja(Organizm* organizm) {
	//jesli kolizja z roslina
	if (organizm->rysowanie() == 'T' || organizm->rysowanie() == 'C' || organizm->rysowanie() == 'G') {
		organizm->kolizja(this);
	}
	else {
		int organizmX = organizm->getX();
		int organizmY = organizm->getY();
		//jesli kolizja z tym samym gatunkiem
		if (rysowanie() == organizm->rysowanie()) {
			std::cout << nazwa() << " ma sie rozmnozyc na polu (" << x << "," << y << ")\n";
		}
		//zmija jest atakowana przez silniejszy organizm
		else if (organizm->rysowanie() == 'Z' && sila >= organizm->getSila()) {
			std::cout << "Atakujacy " << nazwa() << " pokonuje " << organizm->nazwa() << ", lecz ta go zatruwa "
				<< "i oba organizmy gina polu (" << organizmX << ", " << organizmY << ")\n\n";
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

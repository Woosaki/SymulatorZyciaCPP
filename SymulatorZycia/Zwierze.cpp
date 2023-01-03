#include "Zwierze.h"

void Zwierze::akcja() {
	int x = this->getX();
	int y = this->getY();

	do {
		x = this->getX();
		y = this->getY();

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

	if (this->swiat->czyZajeteMiejsce(x, y)) {
		this->kolizja(this->swiat->organizmNaPolu(x, y));
	}
	else {
		this->swiat->przesunOrganizm(this, x, y);
	}

}

void Zwierze::kolizja(Organizm* organizm) {
	if (organizm->rysowanie() == 'T' || organizm->rysowanie() == 'C' || organizm->rysowanie() == 'G') {
		organizm->kolizja(this);
	}
	else {
		if (rysowanie() == organizm->rysowanie()) {
			std::cout << nazwa() << " ma sie rozmnozyc na polu (" << x << "," << y << ")\n";
		}
		else {
			std::cout << "Doszlo do walki pomiedzy " << nazwa() << " a " << organizm->nazwa() 
				<< " na polu (" << organizm->getX() << ", " << organizm->getY() << ")\n";
			if (sila >= organizm->getSila()) {
				int organizmX = organizm->getX();
				int organizmY = organizm->getY();
				swiat->usunOrganizm(organizm);
				swiat->przesunOrganizm(this, organizmX, organizmY);
				std::cout << "Atakujacy (" << nazwa() << ") okazal sie silniejszy\n\n";
			}
			else {
				swiat->usunOrganizm(this);
				std::cout << "Broniacy (" << organizm->nazwa() << ") okazal sie silniejszy\n\n";
			}
		}
	}
}

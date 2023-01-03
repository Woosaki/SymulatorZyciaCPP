#include "Roslina.h"

void Roslina::akcja() {


}

void Roslina::kolizja(Organizm* organizm) {
	std::cout << organizm->nazwa() << " zjadl " << nazwa() << " na polu (" << x << ", " << y << ")\n\n";
	int organizmX = this->getX();
	int organizmY = this->getY();
	this->ustawXY(organizm->getX(), organizm->getY());
	swiat->przesunOrganizm(organizm, organizmX, organizmY);	
	swiat->usunOrganizm(this);	
}

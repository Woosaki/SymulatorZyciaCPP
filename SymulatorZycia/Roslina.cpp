#include "Roslina.h"

void Roslina::akcja() {
	int czyRozmnozyc = rand() % 10;
	if (czyRozmnozyc == 0) {
		if (swiat->czyWolnePoleObok(this)) {
			rozmnazanie();
			std::cout<<nazwa() << " rozprzestrzenia sie na polu (" << x << ", " << y << ")\n\n";
		}		
		else
			std::cout << nazwa() << " nie mogl sie rozprzestrzenic na polu (" << x << ", " << y << "), gdyz nie bylo miejsca obok\n\n";
	}
}

void Roslina::kolizja(Organizm* organizm) {
	std::cout << organizm->nazwa() << " zjadl " << nazwa() << " na polu (" << x << ", " << y << ")\n\n";
	swiat->usunOrganizm(this);	
}
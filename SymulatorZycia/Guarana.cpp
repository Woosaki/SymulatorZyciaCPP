#include "Guarana.h"

void Guarana::kolizja(Organizm* organizm) {
	
	Roslina::kolizja(organizm);
	std::cout << "GUARANA sprawila ze " << organizm->nazwa() << " zwiekszyl sile o 3!\n\n";
	organizm->ustawSila(organizm->getSila() + 3);	
}

char Guarana::rysowanie() {
	return 'G';
}

std::string Guarana::nazwa() {
	return "GUARANA";
}
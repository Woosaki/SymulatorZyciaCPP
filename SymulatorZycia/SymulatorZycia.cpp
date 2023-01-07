#include <iostream>
#include "Organizm.h"
#include "Swiat.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "Zmija.h"
#include "Leniwiec.h"
#include "Mysz.h"
#include "Wilk.h"
#include "Owca.h"
#include "Trawa.h"
#include "Ciern.h"
#include "Guarana.h"

int main() {
    char znak;

    Swiat* swiat = new Swiat();
    swiat->rysujSwiat();

     while (std::cin >> znak) {
		 system("CLS");
		 switch (znak) {
		 case '1':
			 swiat->wykonajTure();
			 swiat->rysujSwiat();
			 break;
		 case '2':
			 swiat->zapiszSwiat();
			 swiat->rysujSwiat();
			 break;
		 case '3':
			 swiat->wczytajSwiat();
			 swiat->rysujSwiat();
			 break;
		 default:
			 std::cout << "Nie ma takiej opcji w menu\n";
			 swiat->rysujSwiat();
		 }
    }

    return 0;
}

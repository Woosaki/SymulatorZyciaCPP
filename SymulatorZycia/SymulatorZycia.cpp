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
    int tura{ 1 };

    Swiat* swiat = new Swiat();
    std::cout << "\n\t\t\t" << "Tura: 0\n\n";
    swiat->rysujSwiat();

     while (std::cin >> znak) {
        system("CLS");
        std::cout << "\n\t\t\t" << "Tura: " << tura <<"\n\n";
        swiat->wykonajTure();
        swiat->rysujSwiat();
        tura++;
    }

    return 0;
}

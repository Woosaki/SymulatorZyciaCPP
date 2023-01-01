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
    int tura{ 0 };

    Swiat* swiat = new Swiat();
    swiat->rysujSwiat();

    while (std::cin >> znak) {
        system("CLS");
        swiat->wykonajTure();
        swiat->rysujSwiat();
    }

    
    return 0;
}

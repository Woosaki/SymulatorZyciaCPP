#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Leniwiec.h"
#include "Zmija.h"
#include "Mysz.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Ciern.h"

Swiat::Swiat() : liczbaOrganizmow{ 0 } {

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			mapa[i][j] = nullptr;

	for (int i = 0; i < 5; i++) {
		Organizm* organizm = new Wilk(this);
		dodajOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 5; i++) {
		Organizm* organizm = new Owca(this);
		dodajOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 3; i++) {
		Organizm* organizm = new Leniwiec(this);
		dodajOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 3; i++) {
		Organizm* organizm = new Zmija(this);
		dodajOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 2; i++) {
		Organizm* organizm = new Mysz(this);
		dodajOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 4; i++) {
		Organizm* organizm = new Trawa(this);
		dodajOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 2; i++) {
		Organizm* organizm = new Guarana(this);
		dodajOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 2; i++) {
		Organizm* organizm = new Ciern(this);
		dodajOrganizmNaMape(organizm);
	}
}

void Swiat::sortOrganizmow() {
	std::sort(kolejnosc.begin(), kolejnosc.end(), [](Organizm* organizm1, Organizm* organizm2) {
		if (organizm1->getInicjatywa() == organizm2->getInicjatywa())
			return organizm1->getWiek() > organizm2->getWiek();
		else
			return organizm1->getInicjatywa() > organizm2->getInicjatywa();
		});
}

void Swiat::wykonajTure() {
	sortOrganizmow();
	for (Organizm* organizm : kolejnosc)
		ruchOrganizmu(organizm);
}

void Swiat::rysujSwiat() {
	std::cout << "\n===============================================================\n    ";

	for (int j = 0; j < N; j++)	{
		if (j < 10)
			std::cout << j << "  ";
		else
			std::cout << j << " ";
	}

	std::cout << "\n";

	for (int j = 0; j < N; j++)	{
		for (int i = 0; i < N; i++)	{
			if (i == 0 && j < 10)
				std::cout << j << "   ";
			if (i == 0 && j > 9)
				std::cout << j << "  ";

			if (mapa[i][j] != nullptr)
				std::cout << mapa[i][j]->rysowanie() << "  ";
			else
				std::cout << ".  ";
		}
		std::cout << "\n";
	}

	std::cout << "===============================================================\n";
}

void Swiat::dodajOrganizmNaMape(Organizm* organizm) {
	int randomX = rand() % 20;
	int randomY = rand() % 20;
	while (czyZajeteMiejsce(randomX, randomY)) {
		randomX = rand() % 20;
		randomY = rand() % 20;
	}

	mapa[randomX][randomY] = organizm;
	liczbaOrganizmow++;
	organizm->ustawXY(randomX, randomY);
	kolejnosc.push_back(organizm);
}

void Swiat::ruchOrganizmu(Organizm* organizm) {
	int x = organizm->getX();
	int y = organizm->getY();

	do {
		x = organizm->getX();
		y = organizm->getY();

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

	if (czyZajeteMiejsce(x, y)) {
		organizm->kolizja();
		std::cout << "Napierdalamy sie\n";
	}				
	else {
		mapa[organizm->getX()][organizm->getY()] = nullptr;
		organizm->ustawXY(x, y);
		mapa[organizm->getX()][organizm->getY()] = organizm;
	}
}

bool Swiat::czyZajeteMiejsce(int x, int y) {
	return mapa[x][y] != nullptr;
}

int Swiat::iloscOrganizmow() {
	return liczbaOrganizmow;
}
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
	for (int i = 0; i < kolejnosc.size(); i++) {
		kolejnosc[i]->akcja();
		kolejnosc[i]->zwiekszWiek();
	}
	/*for (Organizm* organizm : kolejnosc) {
		organizm->akcja();
		organizm->zwiekszWiek();
	}*/
}

void Swiat::rysujSwiat() {
	std::cout << "\n===============================================================\n    ";
	for (int i = 0; i < N; i++)	{
		if (i < 10)
			std::cout << i << "  ";
		else
			std::cout << i << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)	{
			if (j == 0 && i < 10)
				std::cout << i << "   ";
			if (j == 0 && i > 9)
				std::cout << i << "  ";

			if (mapa[j][i] != nullptr)
				std::cout << mapa[j][i]->rysowanie() << "  ";
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



void Swiat::przesunOrganizm(Organizm* organizm, int x, int y) {
	mapa[organizm->getX()][organizm->getY()] = nullptr;
	organizm->ustawXY(x, y);
	mapa[x][y] = organizm;
}

bool Swiat::czyZajeteMiejsce(int x, int y) {
	return mapa[x][y] != nullptr;
}

Organizm* Swiat::organizmNaPolu(int x, int y) {
	return mapa[x][y];
}

int Swiat::iloscOrganizmow() {
	return liczbaOrganizmow;
}

void Swiat::usunOrganizm(Organizm* organizm) {
	auto itr = std::find(kolejnosc.begin(), kolejnosc.end(), organizm);
	kolejnosc.erase(itr);
	mapa[organizm->getX()][organizm->getY()] = nullptr;
	delete organizm;
	liczbaOrganizmow--;
}
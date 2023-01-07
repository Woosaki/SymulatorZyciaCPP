#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Leniwiec.h"
#include "Zmija.h"
#include "Mysz.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Ciern.h"

Swiat::Swiat() : tura(0), iloscNowychOrganizmow(0){

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			mapa[i][j] = nullptr;

	for (int i = 0; i < 5; i++) {
		Organizm* organizm = new Wilk(this);
		dodajLosowoOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 6; i++) {
		Organizm* organizm = new Owca(this);
		dodajLosowoOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 4; i++) {
		Organizm* organizm = new Leniwiec(this);
		dodajLosowoOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 4; i++) {
		Organizm* organizm = new Zmija(this);
		dodajLosowoOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 3; i++) {
		Organizm* organizm = new Mysz(this);
		dodajLosowoOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 5; i++) {
		Organizm* organizm = new Trawa(this);
		dodajLosowoOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 3; i++) {
		Organizm* organizm = new Guarana(this);
		dodajLosowoOrganizmNaMape(organizm);
	}
	for (int i = 0; i < 1; i++) {
		Organizm* organizm = new Ciern(this);
		dodajLosowoOrganizmNaMape(organizm);
	}
}

int Swiat::getTura() { return tura; }

void Swiat::zwiekszIloscNowychOrganizmow() {
	iloscNowychOrganizmow++;
}

void Swiat::dodajDoKolejki(Organizm* organizm) {
	kolejnosc.push_back(organizm);
}

void Swiat::sortOrganizmow() {
	std::sort(kolejnosc.begin(), kolejnosc.end(), [] (Organizm* organizm1, Organizm* organizm2) {
		if (organizm1->getInicjatywa() == organizm2->getInicjatywa())
			return organizm1->getWiek() > organizm2->getWiek();
		else
			return organizm1->getInicjatywa() > organizm2->getInicjatywa();
	});
}

void Swiat::wykonajTure() {
	sortOrganizmow();
	for (int i = 0; i < kolejnosc.size() - iloscNowychOrganizmow; i++) {
		kolejnosc[i]->akcja();
		kolejnosc[i]->zwiekszWiek();
	}
	iloscNowychOrganizmow = 0;
	tura++;	
}

void Swiat::zapiszSwiat() {
	std::fstream plik;
	plik.open("zapisSwiata.txt", std::ios::out);
	plik << tura << "\n";

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (mapa[i][j] != nullptr)
				plik << mapa[i][j]->rysowanie() << " " << i << " " << j << " " 
					<< mapa[i][j]->getSila() << " " << mapa[i][j]->getInicjatywa() << " " << mapa[i][j]->getWiek();
}

void Swiat::wczytajSwiat() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			mapa[i][j] = nullptr;
	kolejnosc.clear();
	std::fstream plik;
	plik.open("zapisSwiata.txt", std::ios::in);
	char znak;
	int x, y, sila, inicjatywa, wiek, tura;
	plik >> tura;
	this->tura = tura;
	while (!plik.eof())	{
		plik >> znak;
		plik >> x;
		plik >> y;
		plik >> sila;
		plik >> inicjatywa;
		plik >> wiek;

		Organizm* organizm = nullptr;

		switch (znak)
		{
		case 'W':
			organizm = new Wilk(this);
			break;
		case 'O':
			organizm = new Owca(this);
			break;
		case 'Z':
			organizm = new Zmija(this);
			break;
		case 'M':
			organizm = new Mysz(this);
			break;
		case 'L':
			organizm = new Leniwiec(this);
			break;
		case 'T':
			organizm = new Trawa(this);
			break;
		case 'G':
			organizm = new Guarana(this);
			break;
		case 'C':
			organizm = new Ciern(this);
			break;
		}
		organizm->ustawSila(sila);
		organizm->ustawInicjatywa(inicjatywa);
		organizm->ustawWiek(wiek);
		dodajOrganizmNaMape(organizm, x, y);
	}
}

void Swiat::rysujSwiat() {
	std::cout << "\n\t\t\t" << "Tura: " << tura << "\n\n";
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
	std::cout << "WYKONAJ TURE: '1' \nZAPISZ DO PLIKU: '2' \nWCZYTAJ Z PLIKU: '3' \n";
	std::cout << "===============================================================\n\n";
}

void Swiat::dodajLosowoOrganizmNaMape(Organizm* organizm) {
	int randomX = rand() % N;
	int randomY = rand() % N;
	while (czyZajeteMiejsce(randomX, randomY)) {
		randomX = rand() % N;
		randomY = rand() % N;
	}
	mapa[randomX][randomY] = organizm;
	organizm->ustawXY(randomX, randomY);
	kolejnosc.push_back(organizm);
}

void Swiat::dodajOrganizmNaMape(Organizm* organizm, int x, int y) {
	mapa[x][y] = organizm;
	organizm->ustawXY(x, y);
	kolejnosc.push_back(organizm);
}

void Swiat::przesunOrganizm(Organizm* organizm, int x, int y) {
	mapa[organizm->getX()][organizm->getY()] = nullptr;
	organizm->ustawXY(x, y);
	mapa[x][y] = organizm;
}

void Swiat::przesunOrganizmLosowo(Organizm* organizm) {
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
	} while (czyZajeteMiejsce(x, y) || wspolrzednePozaMapa(x, y));
	organizm->ustawXY(x, y);
	mapa[x][y] = organizm;
}

bool Swiat::czyZajeteMiejsce(int x, int y) {
	return mapa[x][y] != nullptr;
}

Organizm* Swiat::organizmNaPolu(int x, int y) {
	return mapa[x][y];
}

void Swiat::usunOrganizm(Organizm* organizm) {
	auto itr = std::find(kolejnosc.begin(), kolejnosc.end(), organizm);
	kolejnosc.erase(itr);
	mapa[organizm->getX()][organizm->getY()] = nullptr;
	delete organizm;
}

bool Swiat::wspolrzednePozaMapa(int x, int y) {
	return (x < 0 || y < 0 || x > N - 1 || y > N - 1);
}

bool Swiat::czyWolnePoleObok(Organizm* organizm) {
	for (int i = 0; i < 8; i++) {
		int x = organizm->getX();
		int y = organizm->getY();
		switch (i) {
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
		if (!czyZajeteMiejsce(x, y) && !wspolrzednePozaMapa(x, y))
			return true;
	}
	return false;
}
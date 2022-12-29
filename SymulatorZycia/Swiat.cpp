#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Leniwiec.h"
#include "Zmija.h"
#include "Mysz.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Ciern.h"

Swiat::Swiat() {

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			mapa[i][j] = nullptr;

	for (int i = 0; i < 5; i++) { Organizm* organizm = new Wilk(this); }
	for (int i = 0; i < 5; i++) { Organizm* organizm = new Owca(this); }
	for (int i = 0; i < 3; i++) { Organizm* organizm = new Leniwiec(this); }
	for (int i = 0; i < 3; i++) { Organizm* organizm = new Zmija(this); }
	for (int i = 0; i < 2; i++) { Organizm* organizm = new Mysz(this); }
	for (int i = 0; i < 4; i++) { Organizm* organizm = new Trawa(this); }
	for (int i = 0; i < 2; i++) { Organizm* organizm = new Guarana(this); }
	for (int i = 0; i < 2; i++) { Organizm* organizm = new Ciern(this); }
}

void Swiat::wykonajTure() {

}

void Swiat::rysujSwiat() {
	std::cout << "\n===============================================================\n    ";
	for (int j = 0; j < N; j++)
	{
		if (j < 10)
		{
			std::cout << j << "  ";
		}
		else
		{
			std::cout << j << " ";
		}
	}
	std::cout << "\n";
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == 0 && j < 10)
			{
				std::cout << j << "   ";
			}
			if (i == 0 && j > 9)
			{
				std::cout << j << "  ";
			}

			if (mapa[i][j] != nullptr)
				std::cout << mapa[i][j]->rysowanie() << "  ";
			else
				std::cout << ".  ";
		}
		std::cout << "\n";
	}
	std::cout << "===============================================================\n";
}

void Swiat::dodajOrganizmNaMape(Organizm* organizm, int x, int y)
{
	mapa[x][y] = organizm;
}
#include "Organizm.h"

Organizm::Organizm(Swiat* swiat)
	: swiat{ swiat }, sila{ 0 }, inicjatywa{ 0 }, x{ 0 }, y{ 0 }, wiek{ 0 } {}

int Organizm::getX() { return x; }
int Organizm::getY() { return y; }
int Organizm::getInicjatywa() { return inicjatywa; }
int Organizm::getSila() { return sila; }
int Organizm::getWiek() { return wiek; }

void Organizm::ustawXY(int x, int y) {
	this->x = x;
	this->y = y;
}

void Organizm::ustawSila(int sila) {
	this->sila = sila;
}

void Organizm::ustawInicjatywa(int inicjatywa) {
	this->inicjatywa = inicjatywa;
}

void Organizm::ustawWiek(int wiek) {
	this->wiek = wiek;
}

void Organizm::zwiekszWiek() {
	this->wiek++;
}

bool Organizm::czyRoslina() {
	return rysowanie() == 'T' || rysowanie() == 'C' || rysowanie() == 'G';
}

void Organizm::rozmnoz(Organizm* organizm) {
	organizm->ustawXY(x, y);
	swiat->przesunOrganizmLosowo(organizm);
	swiat->dodajDoKolejki(organizm);
	swiat->zwiekszIloscNowychOrganizmow();
}
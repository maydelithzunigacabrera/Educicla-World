#pragma once
#include "Personaje.hpp"

class CBarco : public CPersonajes {
private:
	int hp;
	int cont;
public:

	CBarco(int ancho, int alto, int x);
	~CBarco() {}

	void mover();
	void dibujar(Graphics^ lienzo, Bitmap^ bmp);

	int getHp();
	void reducirHp();

	int getContador();
	void setContador(int v);

	void AumentarContador();
	Rectangle getRectangle();

	void setHp(int n);
};

CBarco::CBarco(int ancho, int alto, int x) : CPersonajes(ancho, alto) {
	dx = dy = 7;
	y = 100;
	hp = 0;
	this->x = x;
	idy = 1;
	cont = rand() % 6;
}

void CBarco::mover() {

	if (x <= 2 || x + ancho >= 1250) {
		dx *= -1;
	}

	if (x>1100) {
		idy = 0;
	}
	else if (x <= 2) {
		idy = 1;
	}
	else idy = idy;
	
	x += dx;
}

void CBarco::dibujar(Graphics^ lienzo, Bitmap^ bmp) {
	Rectangle recorte = Rectangle(idx * ancho, idy * alto, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho * 1.5, alto * 1.5);
	lienzo->DrawImage(bmp, zoom, recorte, GraphicsUnit::Pixel);
}

int CBarco::getHp() {
	return hp;
}

void CBarco::reducirHp() {
	hp--; 
}

int CBarco::getContador() {
	return cont;
}
void CBarco::setContador(int v) {
	cont = v;
}

void CBarco::AumentarContador() {
	cont++;
}

Rectangle CBarco::getRectangle() {
	return Rectangle(x, y, ancho * 1.5, alto * 1.5);
}

void CBarco::setHp(int n) {
	hp = n;
}

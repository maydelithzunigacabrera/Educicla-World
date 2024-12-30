#pragma once
#include "Personaje.hpp"
#include "Buzo.hpp"

class CSubmarino : public CPersonajes {
public:
	CSubmarino(int ancho, int alto);
	~CSubmarino();
	void mover(Graphics^ lienzo, CBuzo* obuzo);
	void dibujar(Graphics^ lienzo, Bitmap^ bmp);
	Rectangle getRectangle();
};

CSubmarino::CSubmarino(int ancho, int alto) : CPersonajes(ancho, alto) {

	x = 1000;
	y = rand() % 30 * 10;
	dx = dy = 5;
}

CSubmarino::~CSubmarino() {
}

void CSubmarino::dibujar(Graphics^ lienzo, Bitmap^ bmp) {
	Rectangle recorte = Rectangle(idx * ancho, idy * alto, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho * 3.0, alto * 3.0);
	lienzo->DrawImage(bmp, zoom, recorte, GraphicsUnit::Pixel);
}


void CSubmarino::mover(Graphics^ lienzo, CBuzo* obuzo) {

	if (x == obuzo->getX()) {
		x += 0;
	}
	else if (x > obuzo->getX()) {
		x -= dx;
		idy = 1;
	}
	else if (x < obuzo->getX()) {
		x += dx;
		idy = 0;
	}

	if (y == obuzo->getY()) {
		y += 0;
	}
	else if (y > obuzo->getY()) {
		y -= dy;
	}
	else if (y < obuzo->getY()) {
		y += dy;
	}

	idx = 0;
}

Rectangle CSubmarino::getRectangle() {
	return Rectangle(x, y, ancho * 3.0, alto * 3.0);
}
#pragma once
#include "Personaje.hpp"

class CBasura : public CPersonajes {
public:
	CBasura(int ancho, int alto, int x);
	~CBasura(){}
	void mover(Graphics^ lienso);
	void Dibujar(Graphics^ lienzo, Bitmap^ bmp);
	Rectangle getRectangle();
};

CBasura::CBasura(int ancho, int alto, int x) : CPersonajes(ancho, alto) {
	dy = 5;
	dx = 0;
	this->x = x;
	y = 130;
}

//CBasura::~CBasura(){}

void CBasura::mover(Graphics^ lienso) {
	if (y < lienso->VisibleClipBounds.Height) {
		y += dy;
	}
}
void CBasura::Dibujar(Graphics^ lienzo, Bitmap^ bmp) {
	Rectangle recorte = Rectangle(idx * ancho, idy * alto, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho * 1.0, alto * 1.0);
	lienzo->DrawImage(bmp, zoom, recorte, GraphicsUnit::Pixel);
}

Rectangle CBasura::getRectangle() {
	return Rectangle(x, y, ancho * 1.0, alto * 1.0);
}
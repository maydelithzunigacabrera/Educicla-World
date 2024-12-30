#pragma once
#include "Personaje.hpp"

using namespace System::Drawing;

class CAnimalMarino : public CPersonajes
{
public:
	CAnimalMarino(int ancho, int alto);
	~CAnimalMarino();
	void dibujarAnimal(Graphics^ lienzo, Bitmap^ bmp);
	void mover();
};

CAnimalMarino::CAnimalMarino(int ancho, int alto) : CPersonajes(ancho, alto)
{
	x = (rand() % 1000) + 5;
	y = (rand() % 450) + 200;
	int i = rand() % 2;
	if (i == 0) {
		dx = 10;
		idy = 1;
	}
	if (i == 1) {
		dx = -10;
		idy = 0;
	}
	dy = 0;
}
CAnimalMarino::~CAnimalMarino() {}

void CAnimalMarino::dibujarAnimal(Graphics^ lienzo, Bitmap^ bmp)
{
	Rectangle recorte = Rectangle(idx * ancho, idy * alto, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho * 1.5, alto * 1.5);
	lienzo->DrawImage(bmp, zoom, recorte, GraphicsUnit::Pixel);
}
void CAnimalMarino::mover()
{
	if (x <= 2 || x + ancho >= 1250) {
		dx *= -1;
	}
	if (x > 1100) {
		idy = 0;
	}
	else if (x <= 2) {
		idy = 1;
	}
	else idy = idy;

	x += dx;
}

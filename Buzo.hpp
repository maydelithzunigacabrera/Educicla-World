#pragma once
#include "Personaje.hpp"

class CBuzo : public CPersonajes {
private:
	int hp;
	int direccion;
public:

	CBuzo(int ancho, int alto);
	~CBuzo();

	void mover(Graphics^ lienzo);
	void dibujar(Graphics^ lienzo, Bitmap^ bmp);

	int getHp();
	void setHp(int n);
	void reducirHp();
	void setDireccion(int n);
	Rectangle getRectangle();
};

CBuzo::CBuzo(int ancho, int alto) : CPersonajes(ancho, alto) {
	dx = dy = 20;
	x = 100;
	y = 180;
	hp = 0;
	direccion = 0;
}

CBuzo::~CBuzo() {}

void CBuzo::mover(Graphics^ lienzo) {

	switch (direccion)
	{

	case 1:
		if (x > 0) {
			x -= dx;
			idy = 1;
		}
		break;

	case 2:
		if (x + ancho * 2.0 < lienzo->VisibleClipBounds.Width) {
			x += dx;
			idy = 2;
		}
		break;

	case 3:
		if (y > 180) {
			y -= dy;
			idy = 0;
		}
		break;

	case 4:
		if (y + alto * 2.0 < lienzo->VisibleClipBounds.Height) {
			y += dy;
			idy = 3;
		}
		break;
	}

	if (direccion != 0) {
		idx++;
	}
	if (idx > 2)idx = 0;
	direccion = 0;
}

void CBuzo::dibujar(Graphics^ lienzo, Bitmap^ bmp) {
	Rectangle recorte = Rectangle(idx * ancho, idy * alto, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho * 2.0, alto * 2.0);
	lienzo->DrawImage(bmp, zoom, recorte, GraphicsUnit::Pixel);
}

int CBuzo::getHp() {
	return hp; 
}

void CBuzo::setHp(int n) {
	hp = n;
}

void CBuzo::reducirHp() {
	hp -= 1;
}

void CBuzo::setDireccion(int n) {
	direccion = n;
}

Rectangle CBuzo::getRectangle() {
	return Rectangle(x, y, ancho * 2.0, alto * 2.0);
}
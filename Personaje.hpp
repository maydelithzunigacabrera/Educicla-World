#pragma once
#include <iostream>

using namespace System::Drawing;

class CPersonajes {
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx, idy;
	bool visible;

public:
	CPersonajes(int ancho, int alto);
	~CPersonajes();

	virtual void mover() {};

	int getX();
	int getY();
	int getIDY();
	bool getVisible();
	void setVisible(bool v);
	void setX(int n);
	void setY(int n);
};

CPersonajes::CPersonajes(int ancho, int alto) {
	this->ancho = ancho;
	this->alto = alto;
	idx = idy = 0;
	visible = true;
}

CPersonajes::~CPersonajes() {}

int CPersonajes::getX() { return x; }
int CPersonajes::getY() { return y; }
int CPersonajes::getIDY() { return idy; }
bool CPersonajes::getVisible() { return visible; }
void CPersonajes::setVisible(bool v) { visible = v; }
void CPersonajes::setX(int n) { x = n; }
void CPersonajes::setY(int n) { y = n; }


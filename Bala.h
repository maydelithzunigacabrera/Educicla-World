#pragma once
#include "Personaje.hpp"

class CBala : public CPersonajes
{
private:
    int  direccion;
public:
    CBala(int x, int y, int ancho, int alto);
    ~CBala() {}
    void Dibujar(Graphics^ g);
    void mover(Graphics^ g);
    Rectangle getRectangle();
    int getXancho();
    int getYalto();
    void setDireccion(int v);
};

CBala::CBala(int x, int y, int ancho, int alto) :CPersonajes(ancho, alto)
{
    dx = dy = 20;
    this->x = x;
    this->y = y;
}

//CBala::~CBala() {}
void CBala::Dibujar(Graphics^ lienzo)
{
    lienzo->FillEllipse(Brushes::Black, x, y, ancho, alto);
}

void CBala::mover(Graphics^ lienzo)
{
    switch (direccion)
    {
    case 0:
        if (y >= 0)
        {
            y -= dy;
        }
        break;
    case 1:
        if (x >= 0)
        {
            x -= dx;
        }
        break;
    case 2:
        if (x + ancho <= lienzo->VisibleClipBounds.Width)
        {
            x += dx;
        }
        break;
    case 3:
        if (direccion == 0 && y + alto <= lienzo->VisibleClipBounds.Height)
        {
            y += dy;
        }
        break;
    }
}
Rectangle CBala::getRectangle(){
    return Rectangle(x, y, ancho, alto);
}

int CBala::getXancho(){
    return x + ancho; 
}

int CBala::getYalto() { 
    return y + alto;
}

void CBala::setDireccion(int v) {
    direccion = v;
}

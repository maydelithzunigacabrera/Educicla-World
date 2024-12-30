#pragma once
#include "Barco.hpp"
#include "Buzo.hpp"
#include "AnimalesMarinos.hpp"
#include "Basura.hpp"
#include "Bala.h"
#include "Submarino.hpp"
#include <vector>

using namespace std;
using namespace System::Windows::Forms;

class CControladora {
private:
	CBuzo* oBuzo;
	CSubmarino* oSubmarino;
	vector<CAnimalMarino*> arrPezPlomo;
	vector<CAnimalMarino*> arrPezAzul;
	vector<CAnimalMarino*> arrPulpos;
	vector<CAnimalMarino*> arrTortugaMarina;
	vector<CBarco*> arrBarcos;
	vector<CBasura*> arrBasura;
	vector<CBala*> arrBalas;
	int contBasuraBuzo;
	int contBasuraFondo;
	bool bala;
	int balas;
	int nivel;
	bool nivel2;
	int nBarcosNivel2;
	int HpBarcoNivel2;

public:
	CControladora(Bitmap^ bmpBuzo, Bitmap^ bmpBarco, Bitmap^ bmpPezPlomo, Bitmap^ bmpPezAzul, Bitmap^ bmpPulpo, Bitmap^bmpTortugaMarina, Bitmap^ bmpSubmarino);
	~CControladora();
	void dibujarTodo(Graphics^ lienzo, Bitmap^ bmpBuzo, Bitmap^ bmpBarco, Bitmap^ bmpPezPlomo, Bitmap^ bmpPezAzul, Bitmap^ bmpPulpo, Bitmap^ bmpBasura, Bitmap^ bmpTortugaMarina, Bitmap^ bmpSubmarino);
	void moverTodo(Graphics^ lienzo);
	void AgregarBasura(CBasura* objBasura);
	void AgregarBala(CBala* objBala);
	void colision(Graphics^ lienzo);
	void info(Graphics^ lienzo);
	CBuzo* getBuzo();
	int getBalas();
	vector<CBarco*> getBarcos();
	void jugarNivel1(Graphics^lienzo, Bitmap^bmpesc1, Panel^panel, Bitmap^ bmpBuzo, Bitmap^ bmpBarco, Bitmap^ bmpPezPlomo, Bitmap^ bmpPezAzul, Bitmap^ bmpPulpo, Bitmap^ bmpBasura, Bitmap^ bmpTortugaMarina, Bitmap^ bmpSubmarino);
	void jugarNivel2(Graphics^ lienzo, Bitmap^ bmpesc2, Panel^ panel, Bitmap^ bmpBuzo, Bitmap^ bmpBarco, Bitmap^ bmpPezPlomo, Bitmap^ bmpPezAzul, Bitmap^ bmpPulpo, Bitmap^ bmpBasura, Bitmap^ bmpTortugaMarina, Bitmap^ bmpSubmarino);
	void setNivel(int n);
	int getNivel();
	void setNBarcosNivel2(int n);
	void setHpBarcosNivel2(int n);
};

CControladora::CControladora(Bitmap^ bmpBuzo, Bitmap^ bmpBarco, Bitmap^ bmpPezPlomo, Bitmap^ bmpPezAzul, Bitmap^ bmpPulpo, Bitmap^ bmpTortugaMarina, Bitmap^ bmpSubmarino) {
	oBuzo = new CBuzo(bmpBuzo->Width / 3, bmpBuzo->Height / 4);
	oSubmarino = new CSubmarino(bmpSubmarino->Width, bmpSubmarino->Height / 4);
	int interador = 10;
	for (int i = 0; i < 4; i++){
		arrBarcos.push_back(new CBarco(bmpBarco->Width, bmpBarco->Height / 2, interador));
		interador += 150;
	}
	for (int i = 0; i < arrBarcos.size(); i++) {
		arrBarcos[i]->setHp(2);
	}
	for (int i = 0; i <= 10; i++) {
		arrPezPlomo.push_back(new CAnimalMarino(bmpPezPlomo->Width, bmpPezPlomo->Height / 2));
		arrPezAzul.push_back(new CAnimalMarino(bmpPezAzul->Width, bmpPezAzul->Height / 2));
		arrPulpos.push_back(new CAnimalMarino(bmpPulpo->Width / 3, bmpPulpo->Height / 2));
		arrTortugaMarina.push_back(new CAnimalMarino(bmpTortugaMarina->Width, bmpTortugaMarina->Height / 2));
	}
	contBasuraBuzo = contBasuraFondo = balas = 0;
	bala = false;
	nivel = 1;
	nivel2 = false;
}

CControladora::~CControladora() {}

void CControladora::dibujarTodo(Graphics^ lienzo, Bitmap^ bmpBuzo, Bitmap^ bmpBarco, Bitmap^ bmpPezPlomo, Bitmap^ bmpPezAzul, Bitmap^ bmpPulpo, Bitmap^ bmpBasura, Bitmap^ bmpTortugaMarina, Bitmap^ bmpSubmarino) {
	oBuzo->dibujar(lienzo, bmpBuzo);
	if (nivel == 2) {
		oSubmarino->dibujar(lienzo, bmpSubmarino);
	}
	for (int i = 0; i < arrBarcos.size(); i++) {
		if (arrBarcos[i]->getVisible() == true) {
			arrBarcos[i]->dibujar(lienzo, bmpBarco);
		}
	}
	for (int i = 0; i <= 10; i++) {
		arrPezPlomo[i]->dibujarAnimal(lienzo, bmpPezPlomo);
		arrPezAzul[i]->dibujarAnimal(lienzo, bmpPezAzul);
		arrPulpos[i]->dibujarAnimal(lienzo, bmpPulpo);
		if (nivel == 2) {
			arrTortugaMarina[i]->dibujarAnimal(lienzo, bmpTortugaMarina);
        }
	}
	for (int i = 0; i < arrBasura.size(); i++) {
		arrBasura[i]->Dibujar(lienzo, bmpBasura);
	}

	for (int i = 0; i < arrBalas.size(); i++) {
		arrBalas[i]->Dibujar(lienzo);
	}
}

void CControladora::moverTodo(Graphics^ lienzo) {
	oBuzo->mover(lienzo);
	for (int i = 0; i < arrBarcos.size(); i++) {
		arrBarcos[i]->mover();
	}
	for (int i = 0; i <= 10; i++) {
		arrPezPlomo[i]->mover();
		arrPezAzul[i]->mover();
		arrPulpos[i]->mover();
		if (nivel == 2) {
			arrTortugaMarina[i]->mover();
		}
	}
	for (int i = 0; i < arrBasura.size(); i++) {
		arrBasura[i]->mover(lienzo);
	}
	for (int i = 0; i < arrBalas.size(); i++) {
		arrBalas[i]->mover(lienzo);
	}
	if (nivel == 2) {
		oSubmarino->mover(lienzo, oBuzo);
	}
}

void CControladora::AgregarBasura(CBasura * objBasura) {
		arrBasura.push_back(objBasura);
}

void CControladora::AgregarBala(CBala* objBala) {
	arrBalas.push_back(objBala);
	balas--;
}

void CControladora::colision(Graphics^ lienzo) {
	//colision de buzo con basura
	for (int i = 0; i < arrBasura.size(); i++) {
		if (oBuzo->getRectangle().IntersectsWith(arrBasura[i]->getRectangle())) {
			contBasuraBuzo++;
			arrBasura[i]->setVisible(false);
		}
		if (arrBasura[i]->getY() == 600) {
			contBasuraFondo++;
			oBuzo->reducirHp();
		}
	}
	for (int i = 0; i < arrBasura.size(); i++) {
		if (arrBasura[i]->getVisible() == false) {
			arrBasura.erase(arrBasura.begin() + i);
		}
	}
	for (int i = 0; i < arrBalas.size(); i++) {
		for (int j = 0; j < arrBarcos.size(); j++) {
			if (arrBalas[i]->getRectangle().IntersectsWith(arrBarcos[j]->getRectangle())) {
				arrBarcos[j]->reducirHp();
				arrBalas[i]->setVisible(false);
			}
		}
	}
	for (int i = 0; i < arrBarcos.size(); i++) {
		if (arrBarcos[i]->getHp() == 0) {
			arrBarcos[i]->setVisible(false);
		}
	}
	for (int i = 0; i < arrBarcos.size(); i++) {
		if (arrBarcos[i]->getVisible() == false) {
			delete arrBarcos[i];
			arrBarcos.erase(arrBarcos.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < arrBalas.size(); i++) {
		if (arrBalas[i]->getVisible() == false) {
			arrBalas.erase(arrBalas.begin() + i);
		}
	}
	if (nivel == 2) {
		if (oBuzo->getRectangle().IntersectsWith(oSubmarino->getRectangle())) {
			oBuzo->reducirHp();
			oBuzo->setX(100);
			oBuzo->setY(180);
			oSubmarino->setX(1000);
			oSubmarino->setY(400);
		}
	}
	if (contBasuraBuzo == 5) {
		bala = true;
		contBasuraBuzo = 0;
	}
	else bala = false;
	if (bala == true) {
		balas++;
	}
}

void CControladora::info(Graphics^ lienso) {
	int interador=30;
	Font^ letra = gcnew Font("Arial", 12);
	lienso->FillRectangle(Brushes::LightPink, 5, 5, 165, 20);
	lienso->DrawString("VIDAS DEL BUZO: " + oBuzo->getHp(), letra, Brushes::Black, 7, 7);
	lienso->FillRectangle(Brushes::LightPink, 5, 30, 90, 20);
	lienso->DrawString("BALAS: " + balas, letra, Brushes::Black, 7, 32);
	for (int i = 0; i < arrBarcos.size(); i++) {
		interador += 25;
	   lienso->FillRectangle(Brushes::LightPink, 5, interador, 100, 20);
	   lienso->DrawString("VIDAS B" + (i+1) + ": " + arrBarcos[i]->getHp(), letra, Brushes::Black, 7, interador+2);
	}
}

CBuzo* CControladora::getBuzo() { return oBuzo; }

int CControladora::getBalas() {
	return balas;
}

vector<CBarco*> CControladora::getBarcos() {
	return arrBarcos;
}

void CControladora::jugarNivel1(Graphics^ lienzo, Bitmap^ bmpesc1, Panel^ panel, Bitmap^ bmpBuzo, Bitmap^ bmpBarco, Bitmap^ bmpPezPlomo, Bitmap^ bmpPezAzul, Bitmap^ bmpPulpo, Bitmap^ bmpBasura, Bitmap^ bmpTortugaMarina, Bitmap^ bmpSubmarino){
    colision(lienzo);
	moverTodo(lienzo);
	lienzo->DrawImage(bmpesc1, 0, 0, panel->Width, panel->Height);
	info(lienzo);
	dibujarTodo(lienzo, bmpBuzo, bmpBarco, bmpPezPlomo, bmpPezAzul, bmpPulpo, bmpBasura, bmpTortugaMarina, bmpSubmarino);
}
void CControladora::jugarNivel2(Graphics^ lienzo, Bitmap^ bmpesc2, Panel^ panel, Bitmap^ bmpBuzo, Bitmap^ bmpBarco, Bitmap^ bmpPezPlomo, Bitmap^ bmpPezAzul, Bitmap^ bmpPulpo, Bitmap^ bmpBasura, Bitmap^ bmpTortugaMarina, Bitmap^ bmpSubmarino) {
	if (nivel2 == false) {
		int interador = 10;
		for (int i = 0; i < nBarcosNivel2; i++) {
			arrBarcos.push_back(new CBarco(bmpBarco->Width, bmpBarco->Height / 2, interador));
			interador += 150;
		}
		oBuzo->setHp(5);
		oBuzo->setX(100);
		oBuzo->setY(180);
		for (int i = 0; i < arrBarcos.size(); i++) {
			arrBarcos[i]->setHp(HpBarcoNivel2);
		}
		for (int i = 0; i < arrBasura.size(); i++) {
			arrBasura[i]->setVisible(false);
		}
		for (int i = 0; i < arrBasura.size(); i++) {
			if (arrBasura[i]->getVisible() == false) {
				arrBasura.erase(arrBasura.begin() + i);
			}
		}
		balas = 0;
		bala = false;
		nivel2 = true;
	}
	colision(lienzo);
	moverTodo(lienzo);
	lienzo->DrawImage(bmpesc2, 0, 0, panel->Width, panel->Height);
	info(lienzo);
	dibujarTodo(lienzo, bmpBuzo, bmpBarco, bmpPezPlomo, bmpPezAzul, bmpPulpo, bmpBasura, bmpTortugaMarina, bmpSubmarino);
}

void CControladora::setNivel(int n) {
	nivel = n;
}

int CControladora::getNivel() {
	return nivel;
}

void CControladora::setNBarcosNivel2(int n){
	nBarcosNivel2 = n;
}

void CControladora::setHpBarcosNivel2(int n) {
	HpBarcoNivel2 = n;
}
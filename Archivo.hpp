#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace System;
using namespace std;

class CArchivo {
private:
	ifstream fileRead;
	string text;

	int myTime1;
	int myTime2;
	int hp;
	int HpBarco2;
	int nBarco2;

public:
	CArchivo();
	//~CFile() {}

	void readData();

	int getMyTime1();
	int getMyTime2();
	int getHp();
	int getHpBarco2();
	int getNBarco2();
};

CArchivo::CArchivo() {}

//CFile::~CFile() {}

void CArchivo::readData() {
	fileRead.open("configuración.txt", ios::in);

	getline(fileRead, text);
	myTime1 = stoi(text);
	getline(fileRead, text);
	myTime2 = stoi(text);
	getline(fileRead, text);
	hp = stoi(text);
	getline(fileRead, text);
	HpBarco2 = stoi(text);
	getline(fileRead, text);
	nBarco2 = stoi(text);

	fileRead.close();
}

int CArchivo::getMyTime1() { return myTime1; }
int CArchivo::getMyTime2() { return myTime2; }
int CArchivo::getHp() { return hp; }
int CArchivo::getHpBarco2() { return HpBarco2; }
int CArchivo::getNBarco2() { return nBarco2; }

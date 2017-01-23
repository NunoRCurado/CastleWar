#pragma once
#ifndef CASTELO_H
#define CASTELO_H

#include <iostream>
#include <string.h>
#include "Edificios.h"
#include "Colonia.h"


using namespace std;
class Mapa;
class Terreno;
class Colonia;
class Castelo : public Edificios {
private:
	vector <Seres*> seresNoCastelo;

public:

	Castelo();
	Castelo(string id, Terreno *terreno);
	~Castelo();

	vector <Seres*> *getSeres() { return &seresNoCastelo; }
	void colocaSeres(Seres *ser);

	Edificios *duplica() {
		return new Castelo(*this); //erro se a classe edificios for abstracta?
	}

	void repara(Colonia *colonia, int id);
	void efeito(Colonia *colonia, Mapa *mapa);
	void upgrade(Colonia *colonia, int id);
	void vende(Colonia * colonia, int id);
};



#endif

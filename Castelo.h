#pragma once
#ifndef CASTELO_H
#define CASTELO_H

#include <iostream>
#include <string.h>
#include "Edificios.h"
#include "Colonia.h"


using namespace std;
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

	void repara(Colonia *colonia);
	void efeito(Colonia *colonia);
	void upgrade(Colonia *colonia);
	void vende(Colonia *colonia);
};



#endif

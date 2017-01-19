#pragma once
#ifndef TORRE_H
#define TORRE_H

#include <iostream>
#include <string.h>
#include "Edificios.h"
#include "Colonia.h"
#include "Seres.h"


using namespace std;
class Colonia;
class Seres;
class Terreno;
class Torre : public Edificios {


public:

	Torre();
	Torre(string id, Terreno *terreno);
	~Torre();

	Edificios *duplica() {
		return new Torre(*this);
	}

	void efeito(Colonia *colonia);
	void upgrade(Colonia *colonia);
	void vende(Colonia *colonia); //usar alguma coisa para apagar o edificio?
	void repara(Colonia *colonia);


};


#endif
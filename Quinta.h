#pragma once
#ifndef QUINTA_H
#define QUINTA_H

#include <iostream>
#include <string.h>
#include "Edificios.h"


using namespace std;
class Terreno;
class Colonia;
class Quinta : public Edificios {


public:

	Quinta();
	Quinta(string id, Terreno *terreno);
	~Quinta();


	Edificios *duplica() { //
		return new Quinta(*this);
	}

	void efeito(Colonia *colonia);
	void upgrade(Colonia *colonia);
	void vende(Colonia *colonia); //usar alguma coisa para apagar o edificio?
	void repara(Colonia *colonia);

};


#endif

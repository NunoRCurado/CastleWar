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
	Quinta(string id, Terreno *terreno, int edificioId, Colonia *colonia, char idColonia);
	~Quinta();


	Edificios *duplica() { //
		return new Quinta(*this);
	}

	void efeito(Colonia *coloniaActual, Mapa *mapa);
	void upgrade(Colonia *colonia, int id);
	void vende(Colonia * colonia, int id); //usar alguma coisa para apagar o edificio?
	void repara(Colonia *colonia, int id);

};


#endif

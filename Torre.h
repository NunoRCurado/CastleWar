#pragma once
#ifndef TORRE_H
#define TORRE_H

#include <iostream>
#include <string.h>
#include "Edificios.h"
#include "Colonia.h"
#include "Seres.h"


using namespace std;
class Mapa;
class Terreno;
class Torre : public Edificios {


public:

	Torre();
	Torre(string id, Terreno *terreno, int edificioId, Colonia *colonia, char idColonia);
	~Torre();

	Edificios *duplica() {
		return new Torre(*this);
	}

	void efeito(Colonia *coloniaActual, Mapa *mapa);
	void upgrade(Colonia *colonia, int id);
	void vende(Colonia *colonia, int id); //usar alguma coisa para apagar o edificio?
	void repara(Colonia *colonia, int id);


};


#endif
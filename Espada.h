#pragma once
#ifndef ESPADA_H
#define ESPADA_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class Espada : public CaracteristicasSeres{
private:
	int nAtaques;
	int flag;
public:
	Espada();
	~Espada();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new Espada(*this);
	}
};

#endif
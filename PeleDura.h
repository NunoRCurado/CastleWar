#pragma once
#ifndef PELEDURA_H
#define PELEDURA_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class PeleDura : public CaracteristicasSeres {
public:
	PeleDura();
	~PeleDura();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new PeleDura(*this);
	}
};

#endif
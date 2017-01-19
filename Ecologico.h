#pragma once
#ifndef ECOLOGICO_H
#define ECOLOGICO_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class Ecologico : public CaracteristicasSeres {
public:
	Ecologico();
	~Ecologico();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new Ecologico(*this);
	}
};

#endif

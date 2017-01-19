#pragma once
#ifndef SUPERIOR_H
#define SUPERIOR_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class Superior : public CaracteristicasSeres {
public:
	Superior();
	~Superior();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new Superior(*this);
	}
};

#endif#

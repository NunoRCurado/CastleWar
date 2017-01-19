#pragma once
#ifndef FACA_H
#define FACA_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class Faca : public CaracteristicasSeres {
public:
	Faca();
	~Faca();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new Faca(*this);
	}
};

#endif
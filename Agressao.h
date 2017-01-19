#pragma once
#ifndef AGRESSAO_H
#define AGRESSAO_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class Agressao : public CaracteristicasSeres {

public:
	Agressao();
	~Agressao();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new Agressao(*this);
	}
};

#endif
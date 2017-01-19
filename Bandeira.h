#pragma once
#ifndef BANDEIRA_H
#define BANDEIRA_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class Bandeira : public  CaracteristicasSeres {
public:
	Bandeira();
	~Bandeira();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new Bandeira(*this);
	}
};

#endif

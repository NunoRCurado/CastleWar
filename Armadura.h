#pragma once
#ifndef ARMADURA_H
#define ARMADURA_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class Armadura : public  CaracteristicasSeres {
public:
	Armadura();
	~Armadura();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new Armadura(*this);
	}
};

#endif

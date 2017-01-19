#pragma once
#ifndef SECONDCHANCE_H
#define SECONDCHANCE_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class SecondChance : public CaracteristicasSeres {
private:
	int flag;
public:
	SecondChance();
	~SecondChance();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new SecondChance(*this);
	}
};

#endif

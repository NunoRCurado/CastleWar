#pragma once
#ifndef WALKER_H
#define WALKER_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class Walker : public  CaracteristicasSeres {
public:
	Walker();
	~Walker();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new Walker(*this);
	}
};

#endif

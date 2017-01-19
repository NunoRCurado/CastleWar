#pragma once
#ifndef HEATSEEKER_H
#define HEATSEEKER_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class HeatSeeker : public CaracteristicasSeres {
public:
	HeatSeeker();
	~HeatSeeker();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new HeatSeeker(*this);
	}
};

#endif

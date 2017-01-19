#pragma once
#ifndef REMEDIO_H
#define REMEDIO_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class Remedio : public  CaracteristicasSeres {
private:
	int flag;
public:
	Remedio();
	~Remedio();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new Remedio(*this);
	}
};

#endif

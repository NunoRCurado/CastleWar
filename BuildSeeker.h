#pragma once
#ifndef BUILDSEEKER_H
#define BUILDSEEKER_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class BuildSeeker : public  CaracteristicasSeres {
public:
	BuildSeeker();
	~BuildSeeker();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new BuildSeeker(*this);
	}
};

#endif

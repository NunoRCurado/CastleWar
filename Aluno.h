#pragma once
#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"
#include "Mapa.h"

using namespace std;

class Aluno : public  CaracteristicasSeres {
public:
	Aluno();
	~Aluno();

	void efeito(Seres *ser, Mapa *mapa);

	CaracteristicasSeres *duplica() {
		return new Aluno(*this);
	}
};

#endif

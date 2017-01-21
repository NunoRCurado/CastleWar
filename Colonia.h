#pragma once
#ifndef COLONIA_H
#define COLONIA_H

#include <iostream>
#include <vector>
#include <string.h>
#include "Edificios.h"
#include "Seres.h"
class Jogo;

using namespace std;
class Colonia {
private: 
	double moedas;
	char id;
	Jogo &jogo;
	vector <Seres *> seres;
	vector <Edificios *> edificios;

public:

	Colonia(Jogo &jogo, int moedas, char id);
	~Colonia();

	void setMoedas(double moedas) { this->moedas = moedas; }
	double getMoedas() { return this->moedas; }
	void setId(char id) { this-> id = id; }
	char getId() { return this->id; }


	

	void setSeres(Seres *ser);
	vector <Seres*> getSeres() { return this->seres; }

	vector <Edificios*> getEdificios() { return this->edificios; }
	void setEdificios(Edificios *edificio);

};


#endif

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
	int cor;
	Jogo &jogo;
	vector <Seres *> seres;
	vector <Edificios *> edificios;
	int flagAge;

public:

	Colonia(Jogo &jogo, int moedas, char id, int cor, int flagAge);
	~Colonia();

	void setMoedas(double moedas) { this->moedas = moedas; }
	double getMoedas() { return this->moedas; }
	void setId(char id) { this-> id = id; }
	char getId() { return this->id; }
	void setCor(int cor) { this->cor = cor; }
	int getCor() { return this->cor; }

	int getFlagAge() { return this->flagAge; }
	void setFlagAge(int flagAge) { this->flagAge = flagAge; }

	void setSeres(Seres *ser);
	vector <Seres*> *getSeres() { return &seres; }

	vector <Edificios*> *getEdificios() { return &edificios; }
	void setEdificios(Edificios *edificio);

	


};


#endif

#pragma once
#ifndef COLONIA_H
#define COLONIA_H

#include <iostream>
#include <vector>
#include <string.h>
#include "Edificios.h"
#include "Seres.h"


using namespace std;
class Seres;
class Edificios;
class Colonia {
private: 
	double moedas;
	char id;
	int cor;

	vector <Seres *> seres;
	vector <Edificios *> edificios;

public:
	
	Colonia();
	Colonia(int moedas, char id, int cor);
	~Colonia();

	void setMoedas(double moedas) { this->moedas = moedas; }
	double getMoedas() { return this->moedas; }
	void setId(char id) { this-> id = id; }
	char getId() { return this->id; }
	void setCor(int cor) { this->cor = cor; }
	int getCor() { return this->cor; }


	

	void setSeres(Seres *ser);
	vector <Seres*> getSeres() { return this->seres; }

	vector <Edificios*> getEdificios() { return this->edificios; }
	void setEdificios(Edificios *edificio);

};


#endif

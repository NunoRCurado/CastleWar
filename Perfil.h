#pragma once
#ifndef PERFIL_H
#define PERFIL_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"


using namespace std;

class Perfil {
private:
	string id;
	vector <CaracteristicasSeres*> caracteristicas;
	int forca;
	int custo;

public:

	Perfil();
	Perfil(string id, int forca, int custo);
	~Perfil();

	string getID() { return this->id; }
	void setID(string id) { this->id = id; }

	vector <CaracteristicasSeres*> getCaracteristicas() { return this->caracteristicas; }
	void setCaracteristicas(CaracteristicasSeres *caracteristica);

	int getForca() { return this->forca;}
	void setForca(int forca) { this->forca = forca; }

	int getCusto() { return this->custo; }
	void setCusto(int custo) { this->custo = custo; }

	void setVectorCaracteristicas(vector<CaracteristicasSeres*> caracteristicas);


};
#endif
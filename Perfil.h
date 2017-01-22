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
	int saude;
	int ataque;
	int defesa;

public:

	Perfil();
	Perfil(string id, int forca, int custo, int saude, int ataque, int defesa);
	~Perfil();

	string getID() { return this->id; }
	void setID(string id) { this->id = id; }

	vector <CaracteristicasSeres*> *getCaracteristicas() { return &caracteristicas; }
	void setCaracteristicas(CaracteristicasSeres *caracteristica);

	int getForca() { return this->forca;}
	void setForca(int forca) { this->forca = forca; }

	int getAtaque() { return this->ataque; }
	void setAtaque(int ataque) { this->ataque = ataque; }

	int getSaude() { return this->saude; }
	void setSaude(int saude) { this->saude = saude; }

	int getDefesa() { return this->defesa; }
	void setDefesa(int saude) { this->defesa = defesa; }

	int getCusto() { return this->custo; }
	void setCusto(int custo) { this->custo = custo; }

	void setVectorCaracteristicas(vector<CaracteristicasSeres*> caracteristicas);


};
#endif
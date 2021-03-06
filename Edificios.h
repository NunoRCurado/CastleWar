#pragma once
#ifndef EDIFICIOS_H
#define EDIFICIOS_H

#include <iostream>
#include <string.h>
#include "Seres.h"

using namespace std;
class Mapa;
class Terreno;
class Colonia;
class Seres;
class Edificios {

private:
	string id;
	int custo;
	int saude;
	int defesa;
	int ataque;
	int edificioID;
	Terreno *terreno; 
	Colonia *colonia;
	int numeroUpgrades;
	char idColonia;
	

public:

	Edificios(const Edificios &edificio); 
	Edificios();
	Edificios(string id, int custo, int saude, int defesa, int ataque, Terreno *terreno,int numeroUpgrades, int edificioID, Colonia *colonia, char idColonia);
	~Edificios();

	virtual char getIdColonia() { return this->idColonia; }
	virtual void setIdColonia() { this->idColonia = idColonia; }

	virtual vector<Seres*> *getSeres() { return NULL; }
	virtual void colocaSeres(Seres *ser){}

	virtual void setEdificioID(int EID) { this->edificioID = EID; }
	virtual int getEdificioID() { return this->edificioID; }

	virtual void setId(string id) { this->id = id; }
	virtual string getId() { return this->id; }

	virtual void setCusto(int custo) { this->custo = custo; }
	virtual int getCusto() { return this->custo; }

	virtual void setSaude(int saude) { this->saude = saude; }
	virtual int getSaude() { return this->saude; }

	virtual void setDefesa(int defesa) { this->defesa = defesa; }
	virtual int getDefesa() { return this->defesa; }

	virtual void setTerreno(Terreno *terreno) { this->terreno = terreno; }
	virtual Terreno *getTerreno() { return this->terreno; }

	virtual void setNumeroUpgrades(int numeroUpgrades) { this->numeroUpgrades = numeroUpgrades; }
	virtual int getNumeroUpgrades() { return this->numeroUpgrades; }

	virtual void setAtaque(int ataque) { this->ataque = ataque; }
	virtual int getAtaque() { return this->ataque; }

	virtual void setColonia(Colonia *Colonia) { this->colonia = colonia; }
	virtual Colonia *getColonia() { return this->colonia; }

	virtual Edificios *duplica() = 0;
	virtual void efeito(Colonia *coloniaActual, Mapa *mapa) = 0;
	virtual void repara(Colonia *colonia, int id) = 0;
	virtual void upgrade(Colonia *colonia, int id) = 0;
	virtual void vende(Colonia * colonia, int id) = 0;


	//constructor por copia
	Edificios & operator=(const Edificios & x) {

		if (this == &x) {
			return *this;
		}

		this->id = x.id;
		this->terreno = x.terreno;
		this->saude = x.saude;
		this->defesa = x.defesa;
		this->custo = x.custo;
		this->ataque = x.ataque;
		this->numeroUpgrades;
		this->edificioID = x.edificioID;
		this->colonia = x.colonia;

		return *this;
	}

};


#endif
#pragma once
#ifndef SERES_H
#define SERES_H

#include <iostream>
#include <string>
#include <vector>
#include "CaracteristicasSeres.h"


using namespace std;
class CaracteristicasSeres;
class Terreno;
class Seres {

private:
	char id;
	int saude;
	int forca;
	int velocidade;
	int ataque;
	int defesa;
	int perfil;
	int localizacao;
	Terreno *terreno;


	vector <CaracteristicasSeres *> caracteristicasSeres; 

public:
	Seres(const Seres &ser);
	Seres();
	Seres(Terreno *terreno);
	~Seres();

	//construtor por copia
	Seres operator=(const Seres &ser);

	void setSaude(int saude) { this->saude = saude; }
	int getSaude() { return this->saude; }

	void setForca(int forca) { this->forca = forca; }
	int getForca() { return this->forca; }

	void setVelocidade(int velocidade) { this->velocidade = velocidade; }
	int getVelocidade() { return this->velocidade; }

	void setAtaque(int ataque) { this->ataque = ataque; }
	int getAtaque() { return this->ataque; }

	void setDefesa(int defesa) { this->defesa = defesa; }
	int getDefesa() { return this->defesa; }

	void setLocalizacao(int localizacao) { this->localizacao = localizacao; }
	int getLocalizacao() { return this->localizacao; }

	void setTerreno(Terreno *terreno) { this->terreno = terreno; }
	Terreno * getTerreno() { return this->terreno; }

	void setPerfil(int perfil) { this->perfil = perfil; }
	int getPerfil() { return this->perfil; }

	void setId(int id) { this->id = id; }
	int getId() { return this->id; }

	vector <CaracteristicasSeres*> getCaracteristicasSeres() { return this->caracteristicasSeres;}
	void setCaracteristicasSeres(vector <CaracteristicasSeres> caracteristicasSeres);

	Seres *duplica() {
		return new Seres(*this);
	}
};
#endif
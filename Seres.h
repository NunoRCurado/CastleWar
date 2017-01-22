#pragma once
#ifndef SERES_H
#define SERES_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;
class CaracteristicasSeres;
class Colonia;
class Terreno;
class Seres {

private:
	char id;
	int saude;
	int forca;
	int velocidade;
	int ataque;
	int defesa;
	string perfil;
	int localizacao;
	Terreno *terreno;
	Colonia *colonia;
	

	vector <CaracteristicasSeres *> caracteristicasSeres; 

public:
	Seres(const Seres &ser);
	Seres(char id, string idPerfil, Colonia *colonia);
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

	void setColonia(Colonia *colonia) { this->colonia = colonia; }
	Colonia * getColonia() { return this->colonia; }


	void setPerfil(string perfil) { this->perfil = perfil; }
	string getPerfil() { return this->perfil; }

	void setId(int id) { this->id = id; }
	int getId() { return this->id; }

	vector <CaracteristicasSeres*> *getCaracteristicasSeres() { return &caracteristicasSeres;}
	void setCaracteristicasSeres(vector<CaracteristicasSeres*>* caracteristicasSeres);

	Seres *duplica() {
		return new Seres(*this);
	}
};
#endif

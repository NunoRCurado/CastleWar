#pragma once
#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Terreno.h"
#include "Colonia.h"
#include "Edificios.h"
#include "Castelo.h"

class Castelo;
class Edificios;
class Colonia;
class Terreno;
class Mapa {
private:

	int numeroColuna;
	int numeroLinha;


	vector <Terreno *> terrenos;
	vector <Colonia *> colonias;

public:

	Mapa();
	~Mapa();


	void setNumeroColuna(int numeroColuna) { this->numeroColuna = numeroColuna; }
	int getNumeroColuna() { return this->numeroColuna; }
	void setNumeroLinha(int numeroLinha) { this->numeroLinha = numeroLinha; }
	int getNumeroLinha() { return this->numeroLinha; }

	vector <Terreno*> getTerreno() { return this->terrenos; }

	void criarMapa(int numeroLinha, int numeroColuna);
	void setAdjacentes(Terreno *terrenoPosicao);

	void setColonias(Colonia *colonias);
	vector <Colonia*> getColonias() { return this->colonias; }

	bool verificaEdificios(int linhas, int colunas, string id);
	int converteCoordenadasemPosicao(int linhas, int colunas);
	int randomSelector(int valInicial, int valFinal);
};

#endif
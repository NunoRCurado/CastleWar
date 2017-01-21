#pragma once
#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;
class Terreno;
class Colonia;
class Jogo;

class Mapa {
private:

	int numeroColuna;
	int numeroLinha;
	Jogo &jogo;

	vector <Terreno *> terrenos;
	vector <Colonia *> colonias;

	Colonia *coloniaActual;

public:

	Mapa(Jogo &jogo) : jogo(jogo) {}
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

	void addSer(int numeroSeres, string idPerfil);

	Colonia* getColoniaActual() { return this->coloniaActual; }
	void setColoniaActual() { this->coloniaActual = coloniaActual; }


	bool verificaEdificios(int linhas, int colunas, string id, int raio);
	int converteCoordenadasemPosicao(int linhas, int colunas);
	bool comparaDinheiroNasColonias(int dinheiro, Colonia *coloniaActual);


	int randomSelector(int valInicial, int valFinal);

};

#endif
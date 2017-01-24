#pragma once
#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Desenho.h"

using namespace std;
class Terreno;
class Colonia;
class Jogo;

class Mapa {
private:

	vector<int> pos_foco;

	int numeroColuna;
	int numeroLinha;
	Jogo &jogo;

	vector <Terreno *> terrenos;
	vector <Colonia *> colonias;

	Colonia *coloniaActual;

public:

	Mapa(Jogo &jogo) : jogo(jogo) {}
	~Mapa();
	
	void setPos_foco(vector <int> pos_foco) { this->pos_foco = pos_foco; }
	vector<int> getPos_foco() { return this->pos_foco; }


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
	void setColoniaActual(Colonia *coloniaActual) { this->coloniaActual = coloniaActual; }

	void mostraColonia(string idColonia);
	void mostraPerfil(string perfil);

	bool focoMapa(int linhas, int colunas);

	bool verificaEdificios(int linhas, int colunas, string id, int raio);
	int converteCoordenadasemPosicao(int linhas, int colunas);
	bool comparaDinheiroNasColonias(int dinheiro, Colonia *coloniaActual);
	void setMoedasaUmaColonia(string id, int numero);

	void constroiEdificio(string id, int linha, int coluna);
	bool verificaProximidadeAoProprioCasteloTorre(int linhas, int colunas, Colonia *coloniaActual, int raio);
	bool verificaProximidadeAoProprioCasteloQuinta(int linhas, int colunas, Colonia *coloniaActual, int raio);

	void vendeEdificio(int id);

	bool controlaCicloColonias(int turnos);
	void ComandosDoPC();
	void upgradeEdificio(int id);
	void verificaMortos();

	void actuamSeres();
	void actuamEdificios();

	int randomSelector(int valInicial, int valFinal);

	void removeSeresDaColonia(Colonia * colonia, Seres * ser);

};

#endif
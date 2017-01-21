#pragma once
#ifndef TERRENO_H
#define TERRENO_H


#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;
class Seres;
class Edificios;
class Terreno {
private:
	
	int linha;
	int coluna;
	int posicao;


	 Seres* seres = NULL;
	 Edificios* edificios = NULL;
	 //flag para saber se esta um edificio no terreno para prioridade de desenho
	 vector <Terreno*> terrenosAdjacentes;
			 
public:

	Terreno(int numeroLinha, int numeroColuna, int posicao);
	Terreno();
	~Terreno();


	void setLinha(int linha) { this->linha = linha; }
	int getLinha() { return this->linha; }

	void setColuna(int coluna) { this->coluna = coluna; }
	int getColuna() { return this->coluna; }

	void setPosicao(int posicao) { this->posicao = posicao; }
	int getPosicao() { return this->posicao; }



	Edificios* getEdificios() { return this->edificios; }
	void setEdificios(Edificios* edificios);

	Seres* getSeres() { return this->seres; }
	void setSeres(Seres* seres);

	void setTerrenoAdjacente(Terreno *terrenoAdjacente);
	vector <Terreno *> *getTerrenoAdjacentes() { return &terrenosAdjacentes; }


};

#endif
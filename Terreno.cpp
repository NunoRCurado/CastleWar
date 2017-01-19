#include "Terreno.h"

Terreno::Terreno(int numeroLinha, int numeroColuna, int posicao){
	this->linha = numeroLinha;
	this->coluna = numeroColuna;
	this->posicao = posicao;
	this->edificios = NULL;
	this->seres = NULL;
}

Terreno::Terreno(){
}

Terreno::~Terreno(){
}


void Terreno::setSeres(Seres* seres){
	this->seres=seres;
}

void Terreno::setTerrenoAdjacente(Terreno *terrenoAdjacente){
	this->terrenosAdjacentes.push_back(terrenoAdjacente);
}

void Terreno::setEdificios(Edificios *edificios){
	this->edificios=edificios;
}


#pragma once
#ifndef JOGO_H
#define JOGO_H


#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include "Perfil.h"
using namespace std;
class Mapa;
class Interface;


class Jogo {
private:

	int numeroJogadores;
	int moedasInicial;
	vector <Perfil*> perfis;
	Mapa *mapa;
	Interface *itf;
	

public:
	Jogo();
	~Jogo();

	void ConfiguraJogoInicio();
	void ConfiguraJogoInicioProximo();
	void InicioJogo();

	int getMoedasInicial() { return this->moedasInicial; }
	void setMoedasInicial(int moedasInicial) { this->moedasInicial = moedasInicial; }

	int getNumeroJogadores() { return this->numeroJogadores; }
	void setNumeroJogadores(int numeroJogadores) { this->numeroJogadores = numeroJogadores; }

	vector <Perfil*> getPerfis() { return this->perfis;}
	void setPerfis(Perfil *perfil);

	void setPerfilNoVector(string id, string caracteristica);
	bool removePerfil(string id);
	bool removeCaracteristicaDoPerfil(string id, string id1);

	int custoNumeroSerescomPerfil(string id, int numeroSeres);

	Perfil * apanhaPerfilPeloId(string id);


	Mapa *getMapa() { return mapa; }

};

#endif
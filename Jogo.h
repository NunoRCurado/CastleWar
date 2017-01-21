#pragma once
#ifndef JOGO_H
#define JOGO_H


#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Interface.h"
#include "Mapa.h"
#include "Colonia.h"
#include "Perfil.h"
#include "CaracteristicasSeres.h"
#include "Agressao.h"
#include "Aluno.h"
#include "Armadura.h"
#include "Bandeira.h"
#include "BuildSeeker.h"
#include "Ecologico.h"
#include "Espada.h"
#include "Faca.h"
#include "HeatSeeker.h"
#include "PeleDura.h"
#include "Remedio.h"
#include "SecondChance.h"
#include "Superior.h"
#include "Walker.h"
#include <algorithm>



class Jogo {
private:

	int numeroJogadores;
	int moedasInicial;
	vector <Perfil*> perfis;

	

public:
	Jogo();
	~Jogo();

	void ConfiguraJogoFicheiro();

	bool Menu();


	void ConfiguraJogoInicio();
	void ConfiguraJogoInicioProximo();

	int getMoedasInicial() { return this->moedasInicial; }
	void setMoedasInicial(int moedasInicial) { this->moedasInicial = moedasInicial; }

	int getNumeroJogadores() { return this->numeroJogadores; }
	void setNumeroJogadores(int numeroJogadores) { this->numeroJogadores = numeroJogadores; }

	vector <Perfil*> getPerfis() { return this->perfis;}
	void setPerfis(Perfil *perfil);

	void setPerfilNoVector(string id, string caracteristica);
	bool removePerfil(string id);
	bool removeCaracteristicaDoPerfil(string id, string id1);

};

#endif
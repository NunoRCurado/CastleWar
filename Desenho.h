#pragma once
#ifndef Desenho_H
#define Desenho_H
#include "Consola.h"
#include "Terreno.h"
#include "Mapa.h"

#include <iostream>
#include <vector>
using namespace std;

class Desenho
{
	int x;
	int y;

public:
	Desenho(int x, int y);
	Desenho();
	~Desenho();

	void SetTitulo(int linha);


	void DesenhaScreenSize();
	void DesenhaLimpa();
	void DesenhoLimitesMapa();
	void DesenhoLimitesInfo();
	void DesenhoLimitesComandos();
	//void DesenhaSer(string nome, int posicao, int posicaoAnterior);
	void DesenhaTudo();
	void limpaLinhaProntoComandos();
	void limpaLinhaProntoAvisos();
	void limpaLinhaInfo();
	void MapaInicial();
	void escreveEmInfo(int linha);
	void preencheMapa(Mapa *mapa, int i);

};

#endif

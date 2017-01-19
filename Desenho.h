#pragma once
#ifndef Desenho_H
#define Desenho_H
#include "Consola.h"

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

	void DesenhaScreenSize();
	void DesenhaLimpa();
	void limpaPosicaoActual(int posicao);
	void DesenhoMapa();
	void DesenhoLimitesInfo();
	void DesenhoLimitesComandos();
	//void DesenhaSer(string nome, int posicao, int posicaoAnterior);
	void DesenhaEdificio();
	void DesenhaTudo();
	
};

#endif

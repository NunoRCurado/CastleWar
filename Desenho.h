#pragma once
#ifndef Desenho_H
#define Desenho_H
#include "Consola.h"
#include "Terreno.h"


#include <iostream>
#include <vector>
using namespace std;

class Mapa;
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
	void DesenhaTudo();
	void limpaLinhaProntoComandos();
	void limpaLinhaProntoAvisos();
	void limpaLinhaInfo();
	void MapaInicial();
	void DesenhaMapa(Mapa *mapa, int pos);
	void escreveEmInfo(int linha);
	void pintaMapa(Mapa *mapa, vector<int> pos);
};

#endif

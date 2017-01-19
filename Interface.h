#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H
#include "Comando.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <locale> 
#include "Consola.h"
#include "Mapa.h"
#include "Desenho.h"
#include "Jogo.h"
#include "Colonia.h"

class Colonia;
class Jogo;
class Mapa;
class Consola;
class Interface {

private:

	Consola c;
	Comando comObj;


public:

	Interface();
	~Interface();

	bool verificaComando(Mapa *mapa, Jogo *jogo, Colonia *colonia, int controlo);
	bool verificaComandoFase2(Jogo *jogo, int controlo);

	void setComando(Comando comObj);
	

};
#endif
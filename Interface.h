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
using namespace std;
class Colonia;
class Jogo;
class Mapa;
class Seres;
class Interface {

private:
	Consola c;
	Comando comObj;
	Jogo &jogo;

public:

	Interface(Jogo &jogo) : jogo(jogo) {}
	~Interface();

	bool verificaComando(int controlo);
	bool verificaComandoFase2(int controlo);
	bool verificaComandoInicioJogo();

	void setComando(Comando comObj);
	

};
#endif
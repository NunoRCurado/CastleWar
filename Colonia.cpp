#include "Colonia.h"
#include "Jogo.h"

Colonia::Colonia(Jogo &jogo, int moedas, char id) : jogo(jogo)
{
	this->moedas = moedas;
	this->id = id;
}

Colonia::~Colonia()
{
}

void Colonia::setSeres(Seres *ser)
{
	
	this->seres.push_back(ser);
	
}

void Colonia::setEdificios(Edificios * edificio)
{
	this->edificios.push_back(edificio);
	
}

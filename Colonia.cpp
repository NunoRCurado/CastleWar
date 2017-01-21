#include "Colonia.h"

Colonia::Colonia()
{
}

Colonia::Colonia(int moedas, char id, int cor)
{
	this->moedas = moedas;
	this->id = id;
	this->cor = cor;
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

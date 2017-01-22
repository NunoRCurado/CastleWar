#include "Edificios.h"


Edificios::Edificios(const Edificios & edificio)
{
	*this = edificio;
}

Edificios::Edificios()
{
}


Edificios::Edificios(string id, int custo, int saude, int defesa, int ataque, Terreno *terreno, int numeroUpgrades, int edificioID, Colonia *colonia)
{
	this->id = id;
	this->custo = custo;
	this->saude = saude;
	this->defesa = defesa;
	this->terreno = terreno;
	this->ataque = ataque;
	this->numeroUpgrades = numeroUpgrades;
	this->edificioID = edificioID;
	this->colonia = colonia;
}

Edificios::~Edificios()
{
}






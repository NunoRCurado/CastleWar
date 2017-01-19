#include "Edificios.h"

Edificios::Edificios(const Edificios & edificio)
{
	*this = edificio;
}

Edificios::Edificios()
{
}


Edificios::Edificios(string id, int custo, int saude, int defesa, int ataque, Terreno *terreno, int numeroUpgrades)
{
	this->id = id;
	this->custo = custo;
	this->saude = saude;
	this->defesa = defesa;
	this->terreno = terreno;
	this->ataque = ataque;
	this->numeroUpgrades = numeroUpgrades;
}

Edificios::~Edificios()
{
}






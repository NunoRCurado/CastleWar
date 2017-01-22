#include "Perfil.h"

Perfil::Perfil()
{
}

Perfil::Perfil(string id, int forca, int custo, int saude, int ataque, int defesa)
{
	this->id = id;
	this->forca = forca;
	this->custo = custo;
	this->saude = saude;
	this->ataque = ataque;
	this->defesa = defesa;
}

Perfil::~Perfil()
{
}

void Perfil::setCaracteristicas(CaracteristicasSeres * caracteristica)
{
	this->caracteristicas.push_back(caracteristica);
}

void Perfil::setVectorCaracteristicas(vector<CaracteristicasSeres*> caracteristicas)
{
	this->caracteristicas = caracteristicas;
}

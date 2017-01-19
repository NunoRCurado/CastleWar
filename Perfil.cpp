#include "Perfil.h"

Perfil::Perfil()
{
}

Perfil::Perfil(string id, int forca, int custo)
{
	this->id = id;
	this->forca = forca;
	this->custo = custo;
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

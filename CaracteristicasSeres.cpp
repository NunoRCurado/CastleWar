#include "CaracteristicasSeres.h"

CaracteristicasSeres::CaracteristicasSeres(int id, int custoMonetario, int custoForca, bool activo, string nome)
{
	this->id = id;
	this->custoMonetario = custoMonetario;
	this->custoForca = custoForca;
	this->activo = activo;
	this->nome = nome;
}

CaracteristicasSeres::CaracteristicasSeres()
{
}

CaracteristicasSeres::~CaracteristicasSeres()
{
}


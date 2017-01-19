#include "Seres.h"

Seres::Seres(const Seres & ser)//ver para que serve
{
	*this = ser;
}

Seres::Seres()
{
}

Seres::Seres(Terreno *terreno)
{
	this->terreno = terreno;
	this->ataque = 0;
	this->defesa = 0;
	this->forca = 10;
	this->saude = 10;
	this->velocidade = 0;
	this->localizacao = 1; // loc do castelo
}

Seres::~Seres()
{
}

Seres Seres::operator=(const Seres & ser)
{
	if (this == &ser) {
		return *this;
	}
	this->ataque = ser.ataque;
	this->defesa = ser.defesa;
	this->forca = ser.forca;
	this->velocidade = ser.velocidade;
	this->saude = ser.saude;
	this->localizacao = ser.localizacao;
	this->id = ser.id;
	this->terreno = ser.terreno;
	this->perfil = ser.perfil;


//Apaga 
	for (auto p : this->caracteristicasSeres)
		delete p;
	this->caracteristicasSeres.clear();

//copia do vector caracteristicas
	for (auto p : ser.caracteristicasSeres) {
		this->caracteristicasSeres.push_back(p->duplica());
	}


	return *this;
}

void Seres::setCaracteristicasSeres(vector<CaracteristicasSeres> caracteristicasSeres)
{
	for (int i = 0; caracteristicasSeres.size(); i++) {
		this->caracteristicasSeres.push_back(&caracteristicasSeres.at(i));
	}	
}

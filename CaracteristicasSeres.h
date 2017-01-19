#pragma once
#ifndef CARACTERISTICASSERES_H
#define CARACTERISTICASSERES_H

#include <iostream>
#include <string>
#include <vector>
#include "Seres.H"
#include "Mapa.h"

using namespace std;
class Seres;
class Mapa;
class CaracteristicasSeres {

private:
	int id;
	int custoMonetario;
	int custoForca;
	bool activo;
	string nome;

public:
	
	CaracteristicasSeres(int id, int custoMonetario, int custoForca, bool activo, string nome);
	CaracteristicasSeres();
	~CaracteristicasSeres();



	virtual void efeito(Seres *ser, Mapa *mapa) = 0;

	virtual int getId() { return this->id; }
	virtual void setId(int id) { this->id = id; }

	virtual int getCustoMonetario() { return this->custoMonetario; }
	virtual void setCustoMonetario(int custoMonetario) { this->custoMonetario = custoMonetario; }

	virtual void setCustoForca(int custoForca) { this->custoForca = custoForca; }
	virtual int getCustoForca() { return this->custoForca; }

	virtual void setActivo(bool activo) { this->activo = activo; }
	virtual bool getActivo() { return this->activo; }

	virtual string getNome() { return this->nome; }
	virtual void setNome(string nome) { this->nome = nome; }

	virtual CaracteristicasSeres *duplica() = 0;

	//constructor por copia
	CaracteristicasSeres & operator=(const CaracteristicasSeres & x) {

		if (this == &x) {
			return *this;
		}
		this->id = x.id;
		this->custoMonetario = x.custoMonetario;
		this->custoForca = x.custoForca;
		this->activo = x.activo;
		this->nome = x.nome;
		

		return *this;
	}
};
#endif
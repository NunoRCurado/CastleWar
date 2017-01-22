#include "Quinta.h"
#include "Terreno.h"
#include "Colonia.h"
#include "Edificios.h"

Quinta::Quinta()
{
}


Quinta::Quinta(string id, Terreno *terreno) : Edificios (id, 30, 20, 10, 0, terreno, 0, 0)
{
}

Quinta::~Quinta()
{
}

void Quinta::efeito(Colonia * colonia)
{
	colonia->setMoedas(colonia->getMoedas() + 2 + this->getNumeroUpgrades());
}

void Quinta::upgrade(Colonia * colonia)
{
	if (colonia->getMoedas() >= 10) {
		this->setDefesa(this->getDefesa() + 1);
		this->setNumeroUpgrades(this->getNumeroUpgrades() + 1);
		colonia->setMoedas(colonia->getMoedas() - 10);
		
	}
	else {
		cout << "Nao ha dinheiro para fazer upgrade a esta quinta";
	}
}

void Quinta::vende(Colonia * colonia)
{
	colonia->setMoedas(colonia->getMoedas() + ((getCusto()) / 2 + (getNumeroUpgrades() * 5))); //utilizo aquele get?
	delete this->getTerreno()->getEdificios();
}

void Quinta::repara(Colonia * colonia)
{
	if (this->getSaude() <= 0) {
		cout << "Edificio impossivel de reparar devido a ter sustido danos irreversiveis";
	}
	else {
		if (getSaude() < 20) {
			if (colonia->getMoedas() >= (20 - getSaude())*1.1) {
				colonia->setMoedas(colonia->getMoedas() - (20 - getSaude()*1.1));
				setSaude(20);
			}
			else {
				cout << "Nao ha dinheiro para reparar esta quinta";
			}
		}
		else {
			cout << "Edificio nao danificado";
		}
	}
}

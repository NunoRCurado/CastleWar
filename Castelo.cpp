#include "Castelo.h"



Castelo::Castelo()
{
}

Castelo::Castelo(string id, Terreno *terreno, char idColonia) : Edificios(id, 0, 50, 10, 0, terreno, 0, 0, NULL, idColonia )
{
	
}

Castelo::~Castelo()
{
}

void Castelo::colocaSeres(Seres * ser)
{
	this->seresNoCastelo.push_back(ser);
}

void Castelo::repara(Colonia * colonia, int id)
{
	if (this->getSaude() <= 0) { 
		cout << "Edificio impossivel de reparar devido a ter sustido danos irreversiveis";
	}
	else {
		if (getSaude() < 50) {
			if (colonia->getMoedas() >= (50 - getSaude())*1.05) {
				colonia->setMoedas(colonia->getMoedas() - (50 - getSaude()*1.05));
				setSaude(50);
			}
			else {
				cout << "Nao ha dinheiro para reparar o Castelo";
			}
		}
		else {
			cout << "Edificio nao danificado";
		}
	}

}

void Castelo::efeito(Colonia * colonia, Mapa *mapa)
{
}

void Castelo::upgrade(Colonia * colonia, int id)
{
}

void Castelo::vende(Colonia * colonia, int id)
{
}

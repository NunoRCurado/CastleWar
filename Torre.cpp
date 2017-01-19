#include "Torre.h"

Torre::Torre()
{
}


Torre::Torre(string id, Terreno *terreno) : Edificios (id, 20,20,10, 3, terreno,0)
{
}

Torre::~Torre()
{
}

void Torre::efeito(Colonia *colonia)
{
	//tem q ir verificar se ha seres inimigos a volta, utilizar vector de vizinhos?
	// se houver da o dano
	for (int i = 0; i < getTerreno()->getTerrenoAdjacentes().size(); i++) {
		if (getTerreno()->getTerrenoAdjacentes().at(i)->getSeres() != NULL) { //bandeira
			getTerreno()->getTerrenoAdjacentes().at(i)->getSeres()->setSaude(getTerreno()->getTerrenoAdjacentes().at(i)->getSeres()->getSaude() - getAtaque());
		}

	}



}

void Torre::upgrade(Colonia *colonia)
{
	if (colonia->getMoedas() >= 10) {
		this->setDefesa(this->getDefesa() + 2);
		this->setAtaque(this->getAtaque() + 1);
		colonia->setMoedas(colonia->getMoedas() - 10);
		this->setNumeroUpgrades(this->getNumeroUpgrades() + 1);
	}
	else {
		cout << "Nao ha dinheiro para fazer upgrade a esta torre";
	}
	
}

void Torre::vende(Colonia * colonia)
{
	colonia->setMoedas(colonia->getMoedas() + ((getCusto()) / 2 + (getNumeroUpgrades() * 5)));
	delete this->getTerreno()->getEdificios();
}

void Torre::repara(Colonia * colonia)
{
	
	if (this->getSaude() <= 0) {
		cout << "Edificio impossivel de reparar devido a ter sustido danos irreversiveis";
	}
	else {
		if (getSaude() < 50) {
			if (colonia->getMoedas() >= (20 - getSaude())*1.2) { //posso comparar int com double?
				colonia->setMoedas(colonia->getMoedas() - (20 - getSaude()*1.2));
				setSaude(20);
			}
			else {
				cout << "Nao ha dinheiro para reparar esta torre";
			}
		}
		else {
			cout << "Edificio nao danificado";
		}
	}
}

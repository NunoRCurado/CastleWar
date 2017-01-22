#include "Torre.h"
#include "Terreno.h"
#include "Mapa.h"

Torre::Torre()
{
}


Torre::Torre(string id, Terreno *terreno, int edificioId, Colonia *colonia) : Edificios (id, 20,20,10, 3,terreno,0, 0, colonia)
{
}

Torre::~Torre()
{
}

void Torre::efeito(Colonia *colonia,Mapa *mapa)
{
	//tem q ir verificar se ha seres inimigos a volta, utilizar vector de vizinhos?
	// se houver da o dano

	Terreno* terreno = this->getTerreno();
	vector<Terreno*> *adj = terreno->getTerrenoAdjacentes();
	int n = adj->size();

	for (int i = 0; i < n; i++) {
		if (adj->at(i)->getSeres() != NULL) {
			if(adj->at(i)->getSeres()->getColonia()->getId() != this->getColonia()->getId()){
				adj->at(i)->getSeres()->setSaude(adj->at(i)->getSeres()->getSaude() - getAtaque());
			}
		}
	}
}

void Torre::upgrade(Colonia *colonia, int id)
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

void Torre::vende(Colonia * colonia, int id)
{
	colonia->setMoedas(colonia->getMoedas() + ((getCusto()) / 2 + (getNumeroUpgrades() * 5)));
	delete this->getTerreno()->getEdificios();
	for (int i = 0; i < colonia->getEdificios().size(); i++) {
		if (colonia->getEdificios().at(i)->getEdificioID() == id) {
			delete colonia->getEdificios().at(i);
		}
	}
	
	
}

void Torre::repara(Colonia * colonia, int id)
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

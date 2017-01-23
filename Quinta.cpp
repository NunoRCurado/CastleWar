#include "Quinta.h"
#include "Terreno.h"
#include "Colonia.h"
#include "Edificios.h"
#include "Mapa.h"

Quinta::Quinta()
{
}


Quinta::Quinta(string id, Terreno *terreno, int edificioId, Colonia *colonia, char idColonia) : Edificios (id, 20, 20, 10, 0, terreno, 0, edificioId, colonia, idColonia)
{
}

Quinta::~Quinta()
{
}

void Quinta::efeito(Colonia * coloniaActual, Mapa *mapa)
{
	coloniaActual->setMoedas(coloniaActual->getMoedas() + 2 + this->getNumeroUpgrades());
}

void Quinta::upgrade(Colonia * colonia, int id)
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

void Quinta::vende(Colonia * colonia, int id)
{
	Edificios *edifico;
	vector <Edificios*>  *vEdificio = colonia->getEdificios();
	vector <Edificios*>::iterator it;
	int tamanho = vEdificio->size();

	colonia->setMoedas(colonia->getMoedas() + ((getCusto()) / 2 + (getNumeroUpgrades() * 5)));
	int j = 0;
	for (int i = 0; i < vEdificio->size(); i++) { //percorre os edificios todos
		if (vEdificio->at(i)->getEdificioID() == id) { // verifica se o edificio nesta posicao é igual ao recebido
			edifico = vEdificio->at(i);  // edificio auxiliar
			for (it = vEdificio->begin(); it != vEdificio->end(); it++) { //percorre o vector vEdificios
				if (edifico->getEdificioID() == vEdificio->at(j)->getEdificioID()) { //corre o vEdificio todo e encontra um igual
					it = vEdificio->erase(it); //apaga quando encontrar
				}
				if (it == vEdificio->end()) {
					return;
				}
				j++;
			}
		}
	}
}

void Quinta::repara(Colonia * colonia, int id)
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

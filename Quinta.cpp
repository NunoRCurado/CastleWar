#include "Quinta.h"
#include "Terreno.h"
#include "Colonia.h"
#include "Edificios.h"
#include "Mapa.h"
#include "Desenho.h"

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
	Desenho d;
	if (colonia->getMoedas() >= 10) {
		this->setDefesa(this->getDefesa() + 1);
		this->setNumeroUpgrades(this->getNumeroUpgrades() + 1);
		colonia->setMoedas(colonia->getMoedas() - 10);
		d.limpaLinhaProntoAvisos();
		cout << "Upgrade efectuado";
	}
	else {
		d.limpaLinhaProntoAvisos();
		cout << "Nao ha dinheiro para fazer upgrade a esta quinta";
	}
}

void Quinta::vende(Colonia * colonia, int id)
{
	vector <Edificios*>  *vEdificio = colonia->getEdificios();
	vector <Edificios*>::iterator it;

	colonia->setMoedas(colonia->getMoedas() + ((getCusto()) / 2 + (getNumeroUpgrades() * 5)));
	
	for (it = vEdificio->begin(); it != vEdificio->end(); it++) {
		if((*it)->getEdificioID() == id)
			it = vEdificio->erase(it);
		if (it == vEdificio->end())
			return;
	}
}

void Quinta::repara(Colonia * colonia, int id)
{
	Desenho d;
	if (this->getSaude() <= 0) {
		d.limpaLinhaProntoAvisos();
		cout << "Edificio impossivel de reparar devido a ter sustido danos irreversiveis";
	}
	else {
		if (getSaude() < 20) {
			if (colonia->getMoedas() >= (20 - getSaude())*1.1) {
				colonia->setMoedas(colonia->getMoedas() - (20 - getSaude()*1.1));
				setSaude(20);
			}
			else {
				d.limpaLinhaProntoAvisos();
				cout << "Nao ha dinheiro para reparar esta quinta";
			}
		}
		else {
			d.limpaLinhaProntoAvisos();
			cout << "Edificio nao danificado";
		}
	}
}

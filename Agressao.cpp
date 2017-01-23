#include "Agressao.h"
#include "Colonia.h"


Agressao::Agressao() : CaracteristicasSeres(7,1,1,true,"AGRESSAO")
{
}

Agressao::~Agressao()
{
}

void Agressao::efeito(Seres * ser, Mapa *mapa)
{

	Terreno * terreno = ser->getTerreno();
	if (terreno == NULL) {
		Colonia *colonia = ser->getColonia();
		terreno = colonia->getEdificios()->at(0)->getTerreno();
	}
	vector <Terreno*> *adj = terreno->getTerrenoAdjacentes();
	int n = adj->size();
	if (ser->getLocalizacao() == 0) {
		for (int i = 0; i < n; i++) {
			if (adj->at(i)->getSeres() != NULL) {
				if (ser->getColonia()->getId() != adj->at(i)->getSeres()->getColonia()->getId()) {
					int ataque = ser->getAtaque();
					int defesa = adj->at(i)->getSeres()->getDefesa();
					int dano = 0;
					if (ataque - defesa > 0) {
						dano = ataque - defesa;
						adj->at(i)->getSeres()->setSaude(adj->at(i)->getSeres()->getSaude() - dano);
					}
				}
			}
		}
	}
}

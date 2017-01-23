#include "Ecologico.h"
#include "Colonia.h"

Ecologico::Ecologico() : CaracteristicasSeres(8,1,1,true,"ECOLOGICO")
{
}

Ecologico::~Ecologico()
{
}

void Ecologico::efeito(Seres * ser, Mapa *mapa)
{
	Terreno * terreno = ser->getTerreno();
	char idSer = ser->getColonia()->getId();
	if (terreno == NULL) {
		Colonia *colonia = ser->getColonia();
		terreno = colonia->getEdificios()->at(0)->getTerreno();
	}
	vector <Terreno*> *adj = terreno->getTerrenoAdjacentes();
	int n = adj->size();
	if (ser->getLocalizacao() == 0) {
		for (int i = 0; i < n; i++) {
			if (adj->at(i)->getEdificios() != NULL) {
				if (ser->getColonia()->getId() != adj->at(i)->getEdificios()->getIdColonia()) {
					int ataque = ser->getAtaque();
						adj->at(i)->getEdificios()->setSaude(adj->at(i)->getEdificios()->getSaude() - ataque);
					}
				}
			}
		}
}

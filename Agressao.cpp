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
	vector <Terreno*> *adj = terreno->getTerrenoAdjacentes();
	int n = adj->size();

	for (int i = 0; i < n; i++) {
		if (adj->at(n)->getSeres() != NULL) {
			if (ser->getColonia()->getId() != adj->at(n)->getSeres()->getColonia()->getId()) {
				int ataque = ser->getAtaque();
				int defesa = adj->at(n)->getSeres()->getDefesa();
				int dano = 0;
				if (ataque - defesa > 0) {
					dano = ataque - defesa;
					adj->at(n)->getSeres()->setSaude(adj->at(n)->getSeres()->getSaude() - dano);
				}
			}
		}
	}
}

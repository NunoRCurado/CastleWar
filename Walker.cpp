#include "Walker.h"
#include "Colonia.h"

Walker::Walker() : CaracteristicasSeres(11,1,1,true,"WALKER")
{
}

Walker::~Walker()
{
}

void Walker::efeito(Seres * ser, Mapa *mapa)
{
	Desenho d;
	Terreno * terreno = ser->getTerreno();
	Edificios *edificio = ser->getColonia()->getEdificios().at(0);
	if (terreno == NULL) {
		Colonia *colonia = ser->getColonia();
		terreno = colonia->getEdificios().at(0)->getTerreno();
	}
	vector <Terreno*> *adj = terreno->getTerrenoAdjacentes();
	int verificaVectorAdj = 0;
	int n = adj->size();
	int posicaoDoSer = terreno->getPosicao();
	int posicaoParaMover = 0;
	vector <int> posicoesJaVistas;
	int verificaSeIgual = 0;

	do {
		if (posicoesJaVistas.size() == n) {
			return;
		}
		verificaSeIgual = 0;
		posicaoParaMover = mapa->randomSelector(0, adj->size()-1);

		if (posicoesJaVistas.size() == 0) {
			posicoesJaVistas.push_back(posicaoParaMover);
		}
		else {
			for (int i = 0; i < posicoesJaVistas.size(); i++) {
				if (posicoesJaVistas.at(i) == posicaoParaMover) {
					verificaSeIgual = 1;
				}
			}
			if (verificaSeIgual == 0) {
				posicoesJaVistas.push_back(posicaoParaMover);
			}
		}

	

	} while (adj->at(posicaoParaMover)->getSeres() != NULL && adj->at(posicaoParaMover)->getEdificios() != NULL);

		mapa->getTerreno().at(posicaoDoSer)->setSeres(NULL);
		ser->setTerreno((adj->at(posicaoParaMover)));
		mapa->getTerreno().at(posicaoDoSer)->getTerrenoAdjacentes()->at(posicaoParaMover)->setSeres(ser);
		ser->setLocalizacao(0);
		vector <Seres*>  *seresNoCastelo = edificio->getSeres();
		vector<Seres *>::iterator it;
		
		for (it = seresNoCastelo->begin(); it != seresNoCastelo->end(); it++) {
			if (ser->getLocalizacao()==0) {
				it = seresNoCastelo->erase(it);
			}
			if (it == seresNoCastelo->end() || seresNoCastelo->size() == 0) {
				break;
			}
		}

}

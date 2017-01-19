#include "Mapa.h"

Mapa::Mapa()
{
}

Mapa::~Mapa()
{
}

void Mapa::criarMapa(int numeroLinha, int numeroColuna){
	Desenho d;

	this->numeroLinha = numeroLinha;
	this->numeroColuna = numeroColuna;

	int posicao = 0; //vector de terrenos vai ter inves do 0 a primeira casa com posicao = 1?

	for (int i = 0; i < numeroLinha; i++) {
		for (int j = 0; j < numeroColuna; j++) {
			terrenos.push_back(new Terreno(i, j, posicao));
			posicao++;
		}

	}
	d.preencheMapa(terrenos, 0);
	for (int i = 0; i < numeroLinha*numeroColuna; i++) {
		setAdjacentes(this->terrenos.at(i));
	}
}

void Mapa::setAdjacentes(Terreno * terrenoPosicao)
{
	//posicao inicial esquerda
	if (terrenoPosicao->getPosicao() == 0) {
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(numeroColuna));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(numeroColuna + 1));
	}

	//posicao superior direita
	else if (terrenoPosicao->getPosicao() == numeroColuna - 1) {
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(numeroColuna - 2));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(numeroColuna * 2 - 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(numeroColuna * 2 - 2));
	}
	//posicoes do topo do mapa
	else if (terrenoPosicao->getPosicao() > 0 && terrenoPosicao->getPosicao() < numeroColuna) {
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + (numeroColuna - 1)));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + numeroColuna));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + numeroColuna + 1));
		
	}

	//posicao inferior esquerda
	else if (terrenoPosicao->getPosicao() == (numeroColuna * (numeroLinha - 1))) {
		terrenoPosicao->setTerrenoAdjacente(terrenos.at((numeroColuna*(numeroLinha - 2))));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at((numeroColuna*(numeroLinha - 1) + 1)));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at((numeroColuna*(numeroLinha - 2) + 1)));
	}

	//posicao inferior direita

	else if (terrenoPosicao->getPosicao() == (numeroColuna*numeroLinha - 1)) {
		terrenoPosicao->setTerrenoAdjacente(terrenos.at((numeroColuna*(numeroLinha - 1) - 1)));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at((numeroColuna*(numeroLinha - 1) - 2)));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(numeroColuna*numeroLinha - 2));
	}

	//posicao inferior do mapa
	else if (terrenoPosicao->getLinha() == numeroLinha - 1 && terrenoPosicao->getColuna() != 0 && terrenoPosicao->getColuna() != numeroColuna - 1) {
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - numeroColuna));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - numeroColuna - 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - numeroColuna +1));
	}

	//posicao esquerda coluna 0
	else if (terrenoPosicao->getColuna() == 0 && terrenoPosicao->getLinha() != 0 && terrenoPosicao->getLinha() != numeroLinha - 1) {
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - numeroColuna));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + numeroColuna));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - numeroColuna + 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + numeroColuna + 1));
	}
	
	//posicao direita coluna max
	else if (terrenoPosicao->getColuna() == (numeroColuna - 1) && terrenoPosicao->getLinha() != 0 && terrenoPosicao->getLinha() != numeroLinha - 1) {
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - numeroColuna));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + numeroColuna));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - numeroColuna - 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + numeroColuna-1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - 1));
	}

	//geral

	else {
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - numeroColuna));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + numeroColuna));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - numeroColuna - 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() - numeroColuna + 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + numeroColuna - 1));
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + numeroColuna + 1));
	}

}

void Mapa::setColonias(Colonia * colonia)
{
	Desenho d;

	if (this->colonias.size() == 0)
	{
		int posicao = randomSelector(0, (getNumeroColuna() * getNumeroLinha()-1));
		Castelo *castelo = new Castelo("C", getTerreno().at(posicao));
		colonia->setEdificios(castelo);
		this->colonias.push_back(colonia);
		this->terrenos.at(posicao)->setEdificios(castelo);
		//inserir random e depois inserir castelo no random
		d.preencheMapa(terrenos, 0);
	}
	else {
		//verificar as 10 casas a volta? 
	
		int posicao = randomSelector(0, (getNumeroColuna() * getNumeroLinha()-1));
		while (this->terrenos.at(posicao)->getEdificios() != NULL) {
			int posicao = randomSelector(0, getNumeroColuna() * getNumeroLinha());
		}
		Castelo *castelo = new Castelo("C", getTerreno().at(posicao)); //verificar isto pode rebentar
		colonia->setEdificios(castelo);
		this->colonias.push_back(colonia);
		this->terrenos.at(posicao)->setEdificios(castelo);
		d.preencheMapa(terrenos, 0);
	}
}

bool Mapa::verificaEdificios(int linhas, int colunas, string id, int raio)
{
	int Lmin = linhas - raio;
	int Lmax = linhas + raio;
	int Cmin = colunas - raio;
	int Cmax = colunas + raio;

	int verificaLmin = 0;
	int verificaCmin = 0;
	int verificaLmax = 0;
	int verificaCmax = 0;

	if (Lmin < 0) {
		verificaLmin = Lmin; //Lmin e sempre negativo?
		Lmin = 0;
		
	}
	if (Lmax > this->numeroLinha - 1) {
		verificaLmax = Lmax - this->numeroLinha - 1;
		Lmax = this->numeroLinha - 1;
	}
	if (Cmin < 0) {
		verificaCmin = Cmin;
		Cmin = 0;
	}
	if (Cmax > this->numeroColuna - 1) {
		verificaCmax = Cmax - this->numeroColuna - 1;
		Cmax = this->numeroColuna - 1;
	}

	int posicaoInicio = converteCoordenadasemPosicao(Lmin, Cmin);

	int colunaCalculo = raio*2 + verificaCmin - verificaCmax -1;
	int linhaCalculo =  raio*2 + verificaLmin - verificaLmax -1;

	for (int i = 0; i < colunaCalculo; i++) {
		for (int j = 0; j < linhaCalculo; j++) {
			int x = (posicaoInicio + i) + this->numeroColuna*j;
			if (this->terrenos.at(x)->getEdificios() != NULL) {
				for (int k = 0; k < this->colonias.size(); k++) {
					if (this->colonias.at(k)->getId() == id[0]){
						if (this->colonias.at(k)->getEdificios().at(0)->getTerreno() != this->terrenos.at(x)) {
							cout << "Existem edificios na area" << endl;
							return false;
						}
						else {
							cout << "Encontrei o castelo" << id << endl;
						}

					}
				}
			}
		}
	}
	return true;
}


int Mapa::converteCoordenadasemPosicao(int linhas, int colunas)
{
	if (linhas == 0) {
		linhas = 1;
	}
	if (colunas == 0) {
		colunas = 1;
	}
	int posicao = 0;
	posicao = (this->numeroColuna * (linhas - 1)) + (colunas - 1);
	return posicao;
}

int Mapa::randomSelector(int valInicial, int valFinal)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(valInicial, valFinal);
	return dist(mt);
}

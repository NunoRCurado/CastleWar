#include "Mapa.h"
#include "Terreno.h"
#include "Castelo.h"
#include "Colonia.h"
#include "Jogo.h"

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
	//d.MapaInicial();
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
		coloniaActual = this->colonias.at(0);
		//inserir random e depois inserir castelo no random
		//meter mapa d.preencheMapa(, 0);
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
		// meter mapa d.preencheMapa(terrenos, 0);
	}
}

void Mapa::addSer(int numeroSeres, string idPerfil)
{
	Desenho d;
	int custoParaFazerSeresTotal = 0;
	bool flag = false;
	vector <CaracteristicasSeres*> * aux = NULL;
	custoParaFazerSeresTotal= jogo.custoNumeroSerescomPerfil(idPerfil, numeroSeres);
	flag = comparaDinheiroNasColonias(custoParaFazerSeresTotal, coloniaActual);
	if(flag == true){
		coloniaActual->setMoedas(coloniaActual->getMoedas() - custoParaFazerSeresTotal);
		for (int i = 0; i < numeroSeres; i++) {
			Seres *ser = new Seres('S', idPerfil);
			aux = jogo.apanhaPerfilPeloId(idPerfil)->getCaracteristicas();
			ser->setCaracteristicasSeres(aux);
			ser->setForca(ser->getForca() - jogo.apanhaPerfilPeloId(idPerfil)->getForca());
			coloniaActual->getEdificios().at(0)->colocaSeres(ser);
			coloniaActual->setSeres(ser);
		}
		d.limpaLinhaProntoAvisos();
		cout << "Foram criados " << numeroSeres << " com sucesso"<<endl;
	}
	else {
		d.limpaLinhaProntoAvisos();
		cout << "nao ha dinheiro" << endl;
	}
}

void Mapa::mostraColonia(string idColonia)
{
	Desenho d;
	Colonia *aux;
	int l = 4;
	for (int c = 0; c < jogo.getMapa()->colonias.size(); c++) {
		if (jogo.getMapa()->colonias.at(c)->getId() == idColonia[0]) {
			aux = jogo.getMapa()->colonias.at(c);
			break;
		}
	}
	d.limpaLinhaInfo();
	d.escreveEmInfo(3);
	cout << "Colonia " << idColonia;
	
	for (int i = 0 ; i < aux->getEdificios().size(); i++) {
		d.escreveEmInfo(l);
		cout << "Id " << aux->getEdificios().at(i)->getId()
			<< " Sa " << aux->getEdificios().at(i)->getSaude()
			<< " De " << aux->getEdificios().at(i)->getDefesa()
			<< " At " << aux->getEdificios().at(i)->getAtaque()
			<< " Up " << aux->getEdificios().at(i)->getNumeroUpgrades()
			<< " Li " << aux->getEdificios().at(i)->getTerreno()->getLinha()
			<< " Co " << aux->getEdificios().at(i)->getTerreno()->getColuna();
		l++;
	}
	for (int y = 0; y < aux->getSeres().size(); y++) {
		d.escreveEmInfo(l);
		cout << "Id " << aux->getSeres().at(y)->getId()
			<< " Sa " << aux->getSeres().at(y)->getSaude()
			<< " De " << aux->getSeres().at(y)->getDefesa()
			<< " At " << aux->getSeres().at(y)->getAtaque()
			<< " Pe " << aux->getSeres().at(y)->getPerfil();
		//	<< " Li " << aux->getSeres().at(y)->getTerreno()->getLinha()
		//	<< " Co " << aux->getSeres().at(y)->getTerreno()->getColuna();
		l++;
	}
}

void Mapa::mostraPerfil(string idperfil)
{
	/*Desenho d;
	Perfil *aux;
	int l = 4;
	for (int c = 0; c < jogo.getPerfis().size(); c++) {	
		if (jogo.getPerfis().at(c)->getID == idperfil[0]) {
			aux = jogo.getPerfis().at(c);
			break;
		}
	}
	d.limpaLinhaInfo();
	d.escreveEmInfo(3);
	cout << "Perfil " << idperfil;

	for (int i = 0; i < aux->getCaracteristicas()->size(); i++) {
		d.escreveEmInfo(l);
		cout << "No " << aux->getCaracteristicas()->at(i)->getNome();
		l++;
	}
	*/
}


bool Mapa::focoMapa(int linhas, int colunas) 
{
	Desenho d;
	vector<int> pos;
	int pos_vector = 0;
	if (linhas <= 10 && colunas <= 20) {  // caso minimo  funciona
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 40; x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						pos.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos);
		return true;
	}
	else if(linhas <= 10){//caso linhas menor que 10 funciona
		for (int y = 0; y < 20; y++) {
			for (int x = colunas - 20; x < colunas + 20; x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						pos.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos);
		return true;
	}
	else if (colunas <= 20) {//caso coluna menor que 20 rebenta
		for (int y = linhas - 10; y < linhas + 10; y++) {
			for (int x = 0; x < 40; x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						pos.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos);
		return true;
	}
	else if (linhas >= this->getNumeroLinha() - 20 && colunas >= this->getNumeroColuna() - 40) { // caso maximo funciona
		for (int y = this->getNumeroLinha() - 20; y < this->getNumeroLinha(); y++) {
			for (int x = this->getNumeroColuna() - 40; x < this->getNumeroColuna(); x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						pos.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos);
		return true;
	}
	else if(linhas >= this->getNumeroLinha() - 20){ // caso as linhas excedam o mapa
		for (int y = this->getNumeroLinha() - 20; y < this->getNumeroLinha(); y++) {
			for (int x = colunas - 20; x < colunas + 20; x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						pos.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos);
		return true;
	}
	else if (colunas >= this->getNumeroColuna() - 40) { // caso as colunas excedam o mapa
		for (int y = linhas - 10; y < linhas + 10; y++) {//isto esta mal
			for (int x = this->getNumeroColuna() - 40; x < this->getNumeroColuna(); x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						pos.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos);
		return true;
	}
	else // caso normal
	{
		for (int y = linhas - 10; y < linhas + 10; y++) {
			for (int x = colunas - 20; x < colunas + 20; x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						pos.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos);
		return true;
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

	int colunaCalculo = raio*2 + verificaCmin - verificaCmax - 1;
	int linhaCalculo =  raio*2 + verificaLmin - verificaLmax - 1;

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
	
	int posicao = 0;
	posicao = (this->numeroColuna * linhas) + colunas;
	return posicao;
}

bool Mapa::comparaDinheiroNasColonias(int dinheiro, Colonia *coloniaActual)
{
	if (coloniaActual->getMoedas() >= dinheiro) {
		return true;
	}
	else
	return false;
}

void Mapa::setMoedasaUmaColonia(string id, int numero)
{
	for (int i = 0; i < colonias.size(); i++) {
		if (colonias.at(i)->getId() == id[0]) {
			colonias.at(i)->setMoedas(colonias.at(i)->getMoedas() - numero);
			cout << "Alteracoes feitas as moedas da colonia " << id << endl;
			break;
		}
	}
}

void Mapa::constroiEdificio(string id, int linha, int coluna)
{
	if (id == "TORRE") {

	}
	else if (id == "QUINTA") {

	}
}

int Mapa::randomSelector(int valInicial, int valFinal)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(valInicial, valFinal);
	return dist(mt);
}



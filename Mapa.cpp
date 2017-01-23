#include "Mapa.h"
#include "Terreno.h"
#include "Castelo.h"
#include "Colonia.h"
#include "Jogo.h"
#include "Torre.h"
#include "Quinta.h"

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
		terrenoPosicao->setTerrenoAdjacente(terrenos.at(terrenoPosicao->getPosicao() + 1));
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
		int posicao = randomSelector(0, (getNumeroColuna() * getNumeroLinha())-1);
		Castelo *castelo = new Castelo("C", getTerreno().at(posicao), 'a');
		colonia->setEdificios(castelo);
		this->colonias.push_back(colonia);
		this->terrenos.at(posicao)->setEdificios(castelo);
		coloniaActual = this->colonias.at(0);
		setColoniaActual(coloniaActual);
	}
	else {
		//verificar as 10 casas a volta? 
		bool flag = false;
		do {
			int linha = 0;
			int coluna = 0;
			linha = randomSelector(0, numeroLinha - 1);
			coluna = randomSelector(0, numeroColuna - 1);
			flag = verificaEdificios(linha, coluna, "", 10);
			if (flag == true) {
				 int posicao = converteCoordenadasemPosicao(linha, coluna);
				 Castelo *castelo = new Castelo("C", getTerreno().at(posicao), colonia->getId()); //verificar isto pode rebentar
				 colonia->setEdificios(castelo);
				 this->colonias.push_back(colonia);
				 this->terrenos.at(posicao)->setEdificios(castelo);
			}		
		} while (flag == false);


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
			Seres *ser = new Seres('S', idPerfil, coloniaActual);
			aux = jogo.apanhaPerfilPeloId(idPerfil)->getCaracteristicas();
			ser->setCaracteristicasSeres(aux);
			ser->setForca(ser->getForca() - jogo.apanhaPerfilPeloId(idPerfil)->getForca());
			ser->setSaude(ser->getSaude() + jogo.apanhaPerfilPeloId(idPerfil)->getSaude());
			ser->setDefesa(ser->getDefesa() + jogo.apanhaPerfilPeloId(idPerfil)->getDefesa());
			ser->setAtaque(ser->getAtaque() + jogo.apanhaPerfilPeloId(idPerfil)->getAtaque());
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
	for (int y = 0; y < aux->getSeres()->size(); y++) {
		d.escreveEmInfo(l);
		cout << "Id " << aux->getSeres()->at(y)->getId()
			<< " Sa " << aux->getSeres()->at(y)->getSaude()
			<< " De " << aux->getSeres()->at(y)->getDefesa()
			<< " At " << aux->getSeres()->at(y)->getAtaque()
			<< " Pe " << aux->getSeres()->at(y)->getPerfil();
		//	<< " Li " << aux->getSeres()->at(y)->getTerreno()->getLinha()
		//	<< " Co " << aux->getSeres()->at(y)->getTerreno()->getColuna();
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
	this->pos_foco.clear();
	if (linhas + 10 >= this->getNumeroLinha()) {
		int dif = linhas + 10 - this->getNumeroLinha();
		linhas = linhas - dif;
	}
	if (colunas + 20 >= this->getNumeroColuna()) {
		int dif = colunas + 20 - this->getNumeroColuna();
		colunas = colunas - dif;
	}
	Desenho d;
	int pos_vector = 0;
	if (linhas <= 10 && colunas <= 20) {  // caso minimo  funciona
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 40; x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						this->pos_foco.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos_foco);
		return true;
	}
	else if(linhas <= 10){//caso linhas menor que 10 funciona
		for (int y = 0; y < 20; y++) {
			for (int x = colunas - 20; x < colunas + 20; x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						this->pos_foco.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos_foco);
		return true;
	}
	else if (colunas <= 20) {//caso coluna menor que 20 
		for (int y = linhas - 10; y < linhas + 10; y++) {
			for (int x = 0; x < 40; x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						this->pos_foco.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos_foco);
		return true;
	}
	else if (linhas >= this->getNumeroLinha() - 10 && colunas >= this->getNumeroColuna() - 20) { // caso maximo funciona
		for (int y = this->getNumeroLinha() - 20; y < this->getNumeroLinha(); y++) {
			for (int x = this->getNumeroColuna() - 40; x < this->getNumeroColuna(); x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						this->pos_foco.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos_foco);
		return true;
	}
	else if(linhas > this->getNumeroLinha() - 10){ // caso as linhas excedam o mapa
		for (int y = this->getNumeroLinha() - 20; y < this->getNumeroLinha(); y++) {
			for (int x = colunas - 20; x < colunas + 20; x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						this->pos_foco.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos_foco);
		return true;
	}
	else if (colunas > this->getNumeroColuna() - 20) { // caso as colunas excedam o mapa
		for (int y = linhas - 10; y < linhas + 10; y++) {
			for (int x = this->getNumeroColuna() - 40; x < this->getNumeroColuna(); x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						this->pos_foco.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos_foco);
		return true;
	}
	else // caso normal
	{
		for (int y = linhas - 10; y < linhas + 10; y++) {
			for (int x = colunas - 20; x < colunas + 20; x++) {
				for (Terreno *p : terrenos) {
					if (p->getColuna() == x && p->getLinha() == y) {
						pos_vector = this->converteCoordenadasemPosicao(y, x);
						this->pos_foco.push_back(pos_vector);
					}
				}
			}
		}
		d.pintaMapa(this, pos_foco);
		return true;
	}
}


bool Mapa::verificaEdificios(int linhas, int colunas, string id, int raio)
{
	Desenho d;
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

	int posicaoActual = converteCoordenadasemPosicao(linhas, colunas);
	int posicaoInicio = converteCoordenadasemPosicao(Lmin, Cmin);

	if (terrenos.at(posicaoActual)->getEdificios() != NULL) {
		d.limpaLinhaProntoAvisos();
		cout << "Ja se encontra um edificio nesta posicao" << endl;
		return false;
	}


	int colunaCalculo = raio*2 + verificaCmin - verificaCmax - 1;
	int linhaCalculo =  raio*2 + verificaLmin - verificaLmax - 1;

	for (int i = 0; i < colunaCalculo; i++) {
		for (int j = 0; j < linhaCalculo; j++) {
			int x = (posicaoInicio + i) + this->numeroColuna*j;
			if (this->terrenos.at(x)->getEdificios() != NULL) {
				for (int k = 0; k < this->colonias.size(); k++) {
					if (this->colonias.at(k)->getId() == id[0]){
						if (this->colonias.at(k)->getEdificios().at(0)->getTerreno() != this->terrenos.at(x)) {
							d.limpaLinhaProntoAvisos();
							cout << "Existem edificios na area" << endl;
							return false;
						}
						else {
							d.limpaLinhaProntoAvisos();
							cout << "Encontrei o castelo" << id << endl;
						}

					}
					else {
						d.limpaLinhaProntoAvisos();
						cout << "Existem edificios na area" << endl;
						return false;
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
	posicao = ((this->numeroColuna * linhas) + (colunas));
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
	Desenho d;
	for (int i = 0; i < colonias.size(); i++) {
		if (colonias.at(i)->getId() == id[0]) {
			colonias.at(i)->setMoedas(colonias.at(i)->getMoedas() - numero);
			d.limpaLinhaProntoAvisos();
			cout << "Alteracoes feitas as moedas da colonia " << id << endl;
			break;
		}
	}
}

void Mapa::constroiEdificio(string id, int linha, int coluna)
{
	bool flag = false;
	if (id == "TORRE") {
		flag = verificaProximidadeAoProprioCasteloTorre(linha, coluna, coloniaActual, 10);
	}
	else if (id == "QUINTA") {
		flag = verificaProximidadeAoProprioCasteloQuinta(linha, coluna, coloniaActual, 10);
	}
}

bool Mapa::verificaProximidadeAoProprioCasteloTorre(int linhas, int colunas, Colonia * coloniaActual, int raio)
{
	Desenho d;

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
	int posicaoDoEdificio = converteCoordenadasemPosicao(linhas, colunas);
	int posicaoDoCastelo = coloniaActual->getEdificios().at(0)->getTerreno()->getPosicao();
	int edificioID = coloniaActual->getEdificios().back()->getEdificioID() + 1;
	

	int colunaCalculo = raio * 2 + verificaCmin - verificaCmax - 1;
	int linhaCalculo = raio * 2 + verificaLmin - verificaLmax - 1;
	
	if (this->terrenos.at(posicaoDoEdificio)->getEdificios() != NULL) {
		d.limpaLinhaProntoAvisos();
		cout << "Ja existem edificios nessa posicao" << endl;
		return false;
	}
	for (int i = 0; i < colunaCalculo; i++) {
		for (int j = 0; j < linhaCalculo; j++) {
			int x = (posicaoInicio + i) + this->numeroColuna*j;
			if (this->terrenos.at(x)->getPosicao() == posicaoDoCastelo) {
				Torre *torre = new Torre("T", terrenos.at(posicaoDoEdificio), edificioID, coloniaActual, coloniaActual->getId());
				double dinheiroColonia = coloniaActual->getMoedas();
				if (torre->getCusto() <= dinheiroColonia) {
					coloniaActual->setMoedas(coloniaActual->getMoedas() - torre->getCusto());
					coloniaActual->setEdificios(torre);
					terrenos.at(posicaoDoEdificio)->setEdificios(torre);
					d.pintaMapa(this, pos_foco);
					d.limpaLinhaProntoAvisos();
					cout << "Torre adicionada com sucesso" << endl;
					return true;
				}
			}
		}
	}
	d.limpaLinhaProntoAvisos();
	cout << "Nao foi possivel adicionar a Torre" << endl;
	return false;
}

bool Mapa::verificaProximidadeAoProprioCasteloQuinta(int linhas, int colunas, Colonia * coloniaActual, int raio)
{
	Desenho d;

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
	int posicaoDoEdificio = converteCoordenadasemPosicao(linhas, colunas);
	int posicaoDoCastelo = coloniaActual->getEdificios().at(0)->getTerreno()->getPosicao();
	int edificioID = coloniaActual->getEdificios().back()->getEdificioID() + 1;
	//pode dar erro se vec vazio utilizar o vec empty?

	int colunaCalculo = raio * 2 + verificaCmin - verificaCmax - 1;
	int linhaCalculo = raio * 2 + verificaLmin - verificaLmax - 1;


	if (this->terrenos.at(posicaoDoEdificio)->getEdificios() != NULL) {
		d.limpaLinhaProntoAvisos();
		cout << "Ja existem edificios nessa posicao" << endl;
		return false;
	}
	for (int i = 0; i < colunaCalculo; i++) {
		for (int j = 0; j < linhaCalculo; j++) {
			int x = (posicaoInicio + i) + this->numeroColuna*j;
			if (this->terrenos.at(x)->getPosicao() == posicaoDoCastelo) {
				Quinta *quinta = new Quinta("Q", terrenos.at(posicaoDoEdificio), edificioID, coloniaActual, coloniaActual->getId());
				double dinheiroColonia = coloniaActual->getMoedas();
				if (quinta->getCusto() <= dinheiroColonia) {
					coloniaActual->setMoedas(coloniaActual->getMoedas() - quinta->getCusto());
					coloniaActual->setEdificios(quinta);
					terrenos.at(posicaoDoEdificio)->setEdificios(quinta);
					d.pintaMapa(this, pos_foco);
					d.limpaLinhaProntoAvisos();
					cout << "Quinta adicionada com sucesso" << endl;
					return true;
				}
			}
		}
	}
	d.limpaLinhaProntoAvisos();
	cout << "Nao foi possivel adicionar a Quinta" << endl;
	return false;
}

void Mapa::controlaCicloColonias(int turnos)
{
	int tamanhoColonias = getColonias().size();
	int i = 0;
	for (int k = 0; k < turnos; k++) {
		i = 0;
		for (i = 0; i < tamanhoColonias; i++) {
			coloniaActual = getColonias().at(i);
			setColoniaActual(coloniaActual);
			if (i==0) {
				if (coloniaActual->getFlagAge() == 1) {
					actuamSeres();
				}
			}
			else {
				ComandosDoPC();
				if (i == tamanhoColonias - 1) {
					setColoniaActual(getColonias().at(0));
				}
			}
		}
	}
	
}

void Mapa::ComandosDoPC()
{
	
	int dinheiro = coloniaActual->getMoedas();
	int valorRandom = randomSelector(0, 3);
	
	switch (valorRandom) {

	case 0:
		if (dinheiro > 100) {
			int perfil = randomSelector(0, 4);
			string id;
			switch (perfil) {
			case 0:
				id = jogo.getPerfis().at(perfil)->getID();
				addSer(2, id);
				break;
			case 1:
				id = jogo.getPerfis().at(perfil)->getID();
				addSer(1, id);
			case 2:
				id = jogo.getPerfis().at(perfil)->getID();
				addSer(2, id);
			case 3:
				id = jogo.getPerfis().at(perfil)->getID();
				addSer(3, id);
			case 4:
				id = jogo.getPerfis().at(perfil)->getID();
				addSer(1, id);
			default:
				break;
			}
		}
		break;
	case 1:

		//if (dinheiro > 150) {
		//	//inserir construcao de edificios?
		//	int posicaoAdj = 0;
		//	Terreno *terreno = coloniaActual->getEdificios().at(0)->getTerreno();
		//	vector <Terreno*> *adj = terreno->getTerrenoAdjacentes();

		//}
		break;
	case 2:
		break;
	case 3:
		break;
	}
	coloniaActual->setFlagAge(1);
	actuamSeres();
}

void Mapa::actuamSeres()
{
	Desenho d;
	vector <Seres*> *seres = coloniaActual->getSeres();
	int n = seres->size();
	if (coloniaActual->getFlagAge() == 1){
		for (auto ser : *seres) {
			for (auto car : *ser->getCaracteristicasSeres()) {
				car->efeito(ser, this);
			}
		}
	}

	else {
		d.limpaLinhaProntoAvisos();
		cout << "Seres estao em modo pacifico" << endl;
	}
	
		
	
}

int Mapa::randomSelector(int valInicial, int valFinal)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(valInicial, valFinal);
	return dist(mt);
}



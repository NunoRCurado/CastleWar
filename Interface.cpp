#include "Interface.h"

Interface::Interface()
{

}

Interface::~Interface()
{

}

bool Interface::verificaComando(Mapa * mapa, Jogo *jogo, Colonia *colonia, int controlo)
{
	Desenho d;

	if (comObj.getArg1() != "DIM" && controlo == 0) {
		d.limpaLinhaProntoAvisos();
		cout << "ERRO! Insira primeiro o tamanho do mapa" << endl;
		return false;
	}

	else if(comObj.getArg1() == "DIM" && controlo == 0){
		if ((atoi(comObj.getArg2().c_str()) < 0 || atoi(comObj.getArg3().c_str()) < 0)){
			d.limpaLinhaProntoAvisos();
			cout << "ERRO! Mapa demasiado pequeno" << endl;
			return false;
		}
		else {
			mapa->criarMapa(atoi(comObj.getArg2().c_str()), atoi(comObj.getArg3().c_str()));
			d.limpaLinhaProntoAvisos();
			cout << "mapa feito" << endl;
			return true;
		}
	}
	else if (comObj.getArg1() != "MOEDAS" && controlo == 1) {
		d.limpaLinhaProntoAvisos();
		cout << "ERRO! Insira primeiro o numero de moedas" << endl;
		return false;
	}
	else if (comObj.getArg1() == "MOEDAS" && controlo == 1) {
		if (atoi(comObj.getArg2().c_str()) <= 20) {
			d.limpaLinhaProntoAvisos();
			cout << "ERRO! Numero de moedas muito reduzido, insira valor maior que 20" << endl;
			return false;
		}
		else {
			jogo->setMoedasInicial(atoi(comObj.getArg2().c_str())); //verificao se introduzir strings
			d.limpaLinhaProntoAvisos();
			cout << "moedas inseridas" << endl;
			return true;
		}
	}
	else if (comObj.getArg1() != "OPONENTES" && controlo == 2) {
		d.limpaLinhaProntoAvisos();
		cout << "ERRO! Insira primeiro o numero de jogadores " << endl;
		return false;
	}

	else if (comObj.getArg1() == "OPONENTES" && controlo == 2) {
		if (atoi(comObj.getArg2().c_str()) <= 0) {
			d.limpaLinhaProntoAvisos();
			cout << "ERRO!Insira numero de jogadores valido" << endl;
			return false;
		}
		else {
			jogo->setNumeroJogadores(atoi(comObj.getArg2().c_str()));
			char id = 'A';
			for (int i = 0; i < jogo->getNumeroJogadores(); i++) {
				mapa->setColonias(new Colonia(jogo->getMoedasInicial(), id));
				d.limpaLinhaProntoAvisos();
				cout << "jogador criado " << i << " com o id " << id << endl;
				id++;
				
			}
			return true;
		}
	}

		d.limpaLinhaProntoAvisos();
		if (atoi(comObj.getArg3().c_str()) > mapa->getNumeroLinha() || atoi(comObj.getArg4().c_str()) > mapa->getNumeroColuna()) {
			d.limpaLinhaProntoAvisos();
			cout << "ERRO! Numero de linha/coluna invalido" << endl;
			return false;
		}
		else {
			bool flag = mapa->verificaEdificios(atoi(comObj.getArg3().c_str()), atoi(comObj.getArg4().c_str()), comObj.getArg2(), 10);
			if (flag == false){
				return false;
			}
			else {
				int y = mapa->converteCoordenadasemPosicao(atoi(comObj.getArg3().c_str()), atoi(comObj.getArg4().c_str()));
				for(int i = 0; i< mapa->getColonias().size();i++)
					if (mapa->getColonias().at(i)->getId() == comObj.getArg2()[0]) {
						int x = mapa->getColonias().at(i)->getEdificios().at(0)->getTerreno()->getPosicao();
						mapa->getTerreno().at(x)->getEdificios()->setTerreno(mapa->getTerreno().at(y));
						mapa->getTerreno().at(y)->setEdificios(mapa->getColonias().at(0)->getEdificios().at(0));
						mapa->getTerreno().at(x)->setEdificios(NULL);
						
						cout << "Castelo "<< comObj.getArg2()<< " mudado com sucesso." << endl;
						return true;
					}
			}
		}
	}	
	
}

bool Interface::verificaComandoFase2(Jogo * jogo, int controlo)
{
	Desenho d;

	if (comObj.getArg1() == "MKPERFIL") {
		if (jogo->getPerfis().size() == 5) {
			d.limpaLinhaProntoAvisos();
			cout << "ERRO!Ja estao 5 perfis criados" << endl;
			return false;
		}
		else {
				for (int i = 0; i < jogo->getPerfis().size(); i++) {
					if (jogo->getPerfis().at(i)->getID() == comObj.getArg2()) {
						d.limpaLinhaProntoAvisos();
						cout << "ERRO!Ja existe perfil com o mesmo id" << endl;
						return false;
					}
				}
				Perfil *p = new Perfil(comObj.getArg2(), 10, 0);
				jogo->setPerfis(p);
				return true;
			}
		}

	else if (comObj.getArg1() == "ADDPERFIL") {
		jogo->setPerfilNoVector(comObj.getArg2(), comObj.getArg3());
		return false;
	}
	else if (comObj.getArg1() == "RMPERFIL") {
		jogo->removePerfil(comObj.getArg2());
		return false;
	}
	else if (comObj.getArg1() == "SUBPERFIL") {
		jogo->removeCaracteristicaDoPerfil(comObj.getArg2(), comObj.getArg3());
	}
	return false;
}

void Interface::setComando(Comando  comObj)
{
	this->comObj = comObj;
}



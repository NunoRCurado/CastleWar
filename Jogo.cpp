#include "Jogo.h"
#include "Comando.h"
#include "Interface.h"
#include "Agressao.h"
#include "Aluno.h"
#include "Armadura.h"
#include "Bandeira.h"
#include "BuildSeeker.h"
#include "Ecologico.h"
#include "Espada.h"
#include "Faca.h"
#include "HeatSeeker.h"
#include "PeleDura.h"
#include "Remedio.h"
#include "SecondChance.h"
#include "Superior.h"
#include "Walker.h"



Jogo::Jogo()
{
	this->itf = new Interface(*this);
	this->mapa = new Mapa(*this);

}

Jogo::~Jogo()
{
}

void Jogo::ConfiguraJogoFicheiro() {
	string comando;
	Comando comObj;
	Desenho d;

	int controlo = 0;
	bool flag = false;
	char s;
	
	ifstream ifi("Setup.txt");
	if (ifi.is_open() == false) {
		d.limpaLinhaProntoAvisos();
		cout << "Erro a abrir ficheiro" << endl;
		return;
	}
	while (getline(ifi, comando)) {			//ConfiguraJogoInicio
		comObj = comObj.separaComando(comando, comObj);
		itf->setComando(comObj);
		flag = itf->verificaComando(controlo);
		if (comObj.getArg1() == "NEXT" && controlo == 3) {
			d.limpaLinhaProntoAvisos();
			cout << "Vamos passar a proxima fase de configuracao" << endl;
			break;
		}
		if (flag == true) {
			controlo++;
		}
		if (controlo == 4) {
			d.limpaLinhaProntoAvisos();
			cout << "Deseja alterar a posicao do castelo?[s/n]" << endl;
			d.limpaLinhaProntoComandos();
			cin >> s;
			if (s == 's') {
				controlo = 3;
			}
			else
				controlo = 5;
		}
		if (controlo == 5) {
			d.limpaLinhaProntoAvisos();
			cout << "Vamos passar a proxima fase de configuracao" << endl;
		}
	}

	while (getline(ifi, comando)){			//ConfiguraJogoInicioProximo
	comObj = comObj.separaComando(comando, comObj);
	itf->setComando(comObj);
	flag = itf->verificaComandoFase2(controlo);
	controlo = perfis.size();
	if (comObj.getArg1() == "INICIO" && controlo != 5) { //adicionar controlo que verifica se existem 5 perfis preenchidos
		d.limpaLinhaProntoAvisos();
		cout << "Nao existem 5 perfis criados";
	}
	if (comObj.getArg1() == "INICIO" && controlo == 5)
		controlo = 6;
	if (controlo == 6) {
		d.limpaLinhaProntoAvisos();
		cout << "Configuracao finalizado, vamos dar inicio ao jogo" << endl;
		}
	}

	this->InicioJogo();

}

bool Jogo::Menu() {
	Desenho d;
	string opcao;
	d.SetTitulo(17);
	cout << "1 - Criar Jogo";
	d.SetTitulo(18);
	cout << "2 - Carregar Jogo";
	while (1) {
		d.SetTitulo(19);
		getline(cin, opcao);
		int opcaon = atoi(opcao.c_str());
		switch (opcaon) {
			case 1:
				return true;
				break;
			case 2:
				return false;
				break;
		}
	}
		
}

void Jogo::ConfiguraJogoInicio()
{
	string comando;
	Comando comObj;
	Desenho d;

	int controlo = 0;
	bool flag = false;
	char s;

	do{
		d.limpaLinhaProntoComandos();
		getline(cin, comando);
		comObj = comObj.separaComando(comando, comObj);
		itf->setComando(comObj);
		flag = itf->verificaComando(controlo);
		if (comObj.getArg1() == "NEXT" && controlo == 3) {
			cout << "Vamos passar a proxima fase de configuracao" << endl;
			break;
		}
		if (flag == true) {
			controlo++;
		}
		if (controlo == 4) {
			d.limpaLinhaProntoAvisos();
			cout << "Deseja alterar a posicao do castelo?[s/n]" << endl;
			d.limpaLinhaProntoComandos();
			cin >> s;
			if (s == 's') {
				controlo = 3;
			}
			else
				controlo = 5;
		}
		if (controlo == 5) {
			d.limpaLinhaProntoAvisos();
			cout << "Vamos passar a proxima fase de configuracao" << endl;
		}
	} while (controlo != 5);
	
}

void Jogo::ConfiguraJogoInicioProximo()
{
	string comando;
	Comando comObj;
	Desenho d;
	bool flag = 0;
	int controlo = 0;

	do{
		d.limpaLinhaProntoComandos();
		getline(cin, comando);
		comObj = comObj.separaComando(comando, comObj);
		itf->setComando(comObj);
		flag = itf->verificaComandoFase2(controlo);
		controlo = perfis.size();
		if (comObj.getArg1() == "INICIO" && controlo != 5) { //adicionar controlo que verifica se existem 5 perfis preenchidos
			d.limpaLinhaProntoAvisos();
			cout << "Nao existem 5 perfis criados";
		}
		if (comObj.getArg1() == "INICIO" && controlo == 5)
			controlo = 6;
		if (controlo == 6) {
			d.limpaLinhaProntoAvisos();
			cout << "Configuracao finalizado, vamos dar inicio ao jogo" << endl;
		}
	} while (controlo != 6);
	
}

void Jogo::InicioJogo()
{
	Desenho d;
	string comando;
	Comando comObj;
	bool flag = false;
	int controlo = 0;

	do {
		d.limpaLinhaProntoComandos();
		getline(cin, comando);
		comObj = comObj.separaComando(comando, comObj);
		itf->setComando(comObj);
		flag = itf->verificaComandoInicioJogo();
	} while (controlo != 6);//adicionar aqui saida ou outro pc
}

void Jogo::setPerfis(Perfil * perfil)
{
	this->perfis.push_back(perfil);
}

void Jogo::setPerfilNoVector(string id, string caracteristica){
	Desenho d;

	if (this->perfis.size() == 0) {
		d.limpaLinhaProntoAvisos();
		cout << "Ainda nao criou nenhum perfil." << endl;
	}
	for (int i = 0; i < this->perfis.size(); i++) {
		if (this->perfis.at(i)->getID() == id) {

			if (caracteristica == "AGRESSAO") {
				if (this->perfis.at(i)->getForca() - 1 < 0) { //ver se da para mudar estes custos fixos 
					d.limpaLinhaProntoAvisos();
					cout << "nao e possivel inserir esta caracteristica devido ao custo" << endl;
					break;
				}
				else {
					Agressao *agressao = new Agressao();
					this->perfis.at(i)->setCaracteristicas(agressao);
					this->perfis.at(i)->setForca(this->perfis.at(i)->getForca()-1);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 1);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
				}
			}
			if (caracteristica == "ALUNO") {
					Aluno *aluno = new Aluno();
					this->perfis.at(i)->setCaracteristicas(aluno);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
			}
			if (caracteristica == "ARMADURA") {
				if (this->perfis.at(i)->getForca() - 3 < 0) { //ver se da para mudar estes custos fixos 
					d.limpaLinhaProntoAvisos();
					cout << "nao e possivel inserir esta caracteristica devido ao custo" << endl;
					break;
				}
				else {
					Armadura *armadura = new Armadura();
					this->perfis.at(i)->setCaracteristicas(armadura);
					this->perfis.at(i)->setForca(this->perfis.at(i)->getForca() - 3);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 2);
					this->perfis.at(i)->setDefesa(this->perfis.at(i)->getDefesa() + 2);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
				}
			}
			if (caracteristica == "BANDEIRA") {
					Bandeira *bandeira = new Bandeira();
					this->perfis.at(i)->setCaracteristicas(bandeira);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 1);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
			}
			if (caracteristica == "BUILDSEEKER") {
				if (this->perfis.at(i)->getForca() - 1 < 0) { //ver se da para mudar estes custos fixos 
					d.limpaLinhaProntoAvisos();
					cout << "nao e possivel inserir esta caracteristica devido ao custo" << endl;
					break;
				}
				else {
					BuildSeeker *buildseeker = new BuildSeeker();
					this->perfis.at(i)->setCaracteristicas(buildseeker);
					this->perfis.at(i)->setForca(this->perfis.at(i)->getForca() - 1);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 1);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
				}
			}
			if (caracteristica == "ECOLOGICO") {
				if (this->perfis.at(i)->getForca() - 1 < 0) { //ver se da para mudar estes custos fixos 
					d.limpaLinhaProntoAvisos();
					cout << "nao e possivel inserir esta caracteristica devido ao custo" << endl;
					break;
				}
				else {
					Ecologico *ecologico = new Ecologico();
					this->perfis.at(i)->setCaracteristicas(ecologico);
					this->perfis.at(i)->setForca(this->perfis.at(i)->getForca() - 1);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 1);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
				}
			}
			if (caracteristica == "ESPADA") {
				if (this->perfis.at(i)->getForca() - 2 < 0) { //ver se da para mudar estes custos fixos 
					d.limpaLinhaProntoAvisos();
					cout << "nao e possivel inserir esta caracteristica devido ao custo" << endl;
					break;
				}
				else {
					Espada *espada = new Espada();
					this->perfis.at(i)->setCaracteristicas(espada);
					this->perfis.at(i)->setForca(this->perfis.at(i)->getForca() - 2);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 2);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
				}
			}
			if (caracteristica == "FACA") {
				if (this->perfis.at(i)->getForca() - 1 < 0) { //ver se da para mudar estes custos fixos 
					d.limpaLinhaProntoAvisos();
					cout << "nao e possivel inserir esta caracteristica devido ao custo" << endl;
					break;
				}
				else {
					Faca *faca = new Faca();
					this->perfis.at(i)->setCaracteristicas(faca);
					this->perfis.at(i)->setForca(this->perfis.at(i)->getForca() - 1);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 1);
					this->perfis.at(i)->setAtaque(this->perfis.at(i)->getAtaque() + 1);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
				}
			}
			if (caracteristica == "HEATSEEKER") {
				if (this->perfis.at(i)->getForca() - 1 < 0) { //ver se da para mudar estes custos fixos 
					d.limpaLinhaProntoAvisos();
					cout << "nao e possivel inserir esta caracteristica devido ao custo" << endl;
					break;
				}
				else {
					HeatSeeker *heatseeker = new HeatSeeker();
					this->perfis.at(i)->setCaracteristicas(heatseeker);
					this->perfis.at(i)->setForca(this->perfis.at(i)->getForca() - 1);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 1);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
				}
			}
			if (caracteristica == "PELEDURA") {
				if (this->perfis.at(i)->getForca() - 2 < 0) { //ver se da para mudar estes custos fixos 
					d.limpaLinhaProntoAvisos();
					cout << "nao e possivel inserir esta caracteristica devido ao custo" << endl;
					break;
				}
				else {
					PeleDura *peledura = new PeleDura();
					this->perfis.at(i)->setCaracteristicas(peledura);
					this->perfis.at(i)->setForca(this->perfis.at(i)->getForca() - 2);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 2);
					this->perfis.at(i)->setDefesa(this->perfis.at(i)->getDefesa() + 1);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
				}
			}
			if (caracteristica == "REMEDIO") {
				if (this->perfis.at(i)->getForca() - 1 < 0) { //ver se da para mudar estes custos fixos 
					d.limpaLinhaProntoAvisos();
					cout << "nao e possivel inserir esta caracteristica devido ao custo" << endl;
					break;
				}
				else {
					Remedio *remedio = new Remedio();
					this->perfis.at(i)->setCaracteristicas(remedio);
					this->perfis.at(i)->setForca(this->perfis.at(i)->getForca() - 1);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 2);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
				}
			}
			if (caracteristica == "SECONDCHANCE") {		
					SecondChance *secondChance = new SecondChance();
					this->perfis.at(i)->setCaracteristicas(secondChance);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 3);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
			}
			if (caracteristica == "SUPERIOR") {
				if (this->perfis.at(i)->getForca() - 1 < 0) { //ver se da para mudar estes custos fixos 
					d.limpaLinhaProntoAvisos();
					cout << "nao e possivel inserir esta caracteristica devido ao custo" << endl;
					break;
				}
				else {
					Superior *superior = new Superior();
					this->perfis.at(i)->setCaracteristicas(superior);
					this->perfis.at(i)->setForca(this->perfis.at(i)->getForca() - 1);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 1);
					this->perfis.at(i)->setSaude(this->perfis.at(i)->getSaude() + 1);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
				}
			}
			if (caracteristica == "WALKER") {
				if (this->perfis.at(i)->getForca() - 1 < 0) { //ver se da para mudar estes custos fixos 
					d.limpaLinhaProntoAvisos();
					cout << "nao e possivel inserir esta caracteristica devido ao custo" << endl;
					break;
				}
				else {
					Walker *walker = new Walker();
					this->perfis.at(i)->setCaracteristicas(walker);
					this->perfis.at(i)->setForca(this->perfis.at(i)->getForca() - 1);
					this->perfis.at(i)->setCusto(this->perfis.at(i)->getCusto() + 1);
					d.limpaLinhaProntoAvisos();
					cout << "Caracteristica adicionada com sucesso" << endl;
					break;
				}
			}
		}
		else {
			d.limpaLinhaProntoAvisos();
			cout << "Perfil nao encontrado." << endl;
		}
	}
}

bool Jogo::removePerfil(string id){
	Desenho d;

	if (this->perfis.size() == 0) {
		d.limpaLinhaProntoAvisos();
		cout << "Ainda nao criou nenhum perfil." << endl;
		return false;
	}
	if (1 == 1) {
		for (int i = 0; i < this->perfis.size(); i++) {
			if (this->perfis.at(i)->getID() == id) {
				this->perfis.erase(remove(this->perfis.begin(), this->perfis.end(), this->perfis.at(i)), this->perfis.end());
				d.limpaLinhaProntoAvisos();
				cout << "Apagou perfil com sucesso" << endl;
				return false;
			}
		}
		d.limpaLinhaProntoAvisos();
		cout << "Nenhum perfil encontrado" << endl;
		return false;
	}

	return false;
}

bool Jogo::removeCaracteristicaDoPerfil(string id, string id1){
	Desenho d;
	
	if (this->perfis.size()==0) {
		d.limpaLinhaProntoAvisos();
		cout << "Nao existem perfis criados" << endl;
		return false;
	}
		for (int i = 0; i < this->perfis.size(); i++) {
			if (this->perfis.at(i)->getID() == id) {
				//por aqui vector aux do tipo caract
				vector <CaracteristicasSeres*> *aux = perfis.at(i)->getCaracteristicas();
	
				for (int j = 0; j <aux->size(); j++) {
					if (aux->at(j)->getNome() == id1){
						aux->erase(remove(aux->begin(), aux->end(), aux->at(j)), aux->end());
						perfis.at(i)->setVectorCaracteristicas(*aux);
						d.limpaLinhaProntoAvisos();
						cout << "TODAS as caracteristicas com este nome foram apagadas!" << endl;
						return false;
					}
				}
			}
	}
	d.limpaLinhaProntoAvisos();
	cout << "Caracteristica/Perfil nao encontrado" << endl;
	return false;
}

int Jogo::custoNumeroSerescomPerfil(string id, int numeroSeres)
{
	int custoTotal = 0;
	for (int i = 0; i < this->perfis.size(); i++) {
		if (this->perfis.at(i)->getID() == id) {
			custoTotal = this->perfis.at(i)->getCusto() * numeroSeres;
			return custoTotal;
		}

	}
	return 0;
}

Perfil * Jogo::apanhaPerfilPeloId(string id)
{
	for (int i = 0; i < perfis.size(); i++) {
		if (perfis.at(i)->getID() == id)
			return perfis.at(i);
	}
	return NULL;
	
}


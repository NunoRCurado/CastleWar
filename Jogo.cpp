#include "Jogo.h"



Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::ConfiguraJogoInicio()
{
	Interface itf;
	string comando;
	Comando comObj;
	Mapa mapa;
	Jogo jogo;
	Colonia colonia;
	Desenho d;

	int controlo = 0;
	bool flag = false;
	char s;

	do{
		d.limpaLinhaProntoComandos();
		getline(cin, comando);
		comObj = comObj.separaComando(comando, comObj);
		itf.setComando(comObj);
		flag = itf.verificaComando(&mapa, &jogo, &colonia, controlo);
		if (comObj.getArg1() == "NEXT" && controlo == 3)
			break;
		if (flag == true) {
			controlo++;
		}
		if (controlo == 4) {
			d.limpaLinhaProntoAvisos();
			cout << "Deseja alterar a posicao do castelo?[s/n]" << endl;
			cin >> s;
			if (s == 's') {
				controlo = 3;
			}
			else
				controlo = 5;
		}
	} while (controlo != 5);
	
}

void Jogo::ConfiguraJogoInicioProximo()
{
	Interface itf;
	string comando;
	Comando comObj;
	Mapa mapa;
	Desenho d;
	Colonia colonia;
	Jogo jogo;
	bool flag = 0;
	int controlo = 0;

	do{
		d.limpaLinhaProntoComandos();
		getline(cin, comando);
		comObj = comObj.separaComando(comando, comObj);
		itf.setComando(comObj);
		flag = itf.verificaComandoFase2(&jogo, controlo);
		controlo = perfis.size();
		if (comObj.getArg1() == "INICIO" && controlo != 5) //adicionar controlo que verifica se existem 5 perfis preenchidos
			d.limpaLinhaProntoAvisos();
			cout << "Nao existem 5 perfis criados" << endl;
		if (comObj.getArg1() == "INICIO" && controlo == 5)
			controlo = 6;
	} while (controlo != 6);
	
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
				vector <CaracteristicasSeres*> aux = perfis.at(i)->getCaracteristicas();
	
				for (int j = 0; j <aux.size(); j++) {
					if (aux.at(j)->getNome() == id1){
						aux.erase(remove(aux.begin(), aux.end(), aux.at(j)), aux.end());
						perfis.at(i)->setVectorCaracteristicas(aux);
						d.limpaLinhaProntoAvisos();
						cout << "Caracteristica apagada" << endl;
						return false;
					}
				}
			}
	}
	d.limpaLinhaProntoAvisos();
	cout << "Caracteristica/Perfil nao encontrado" << endl;
	return false;
}

#include <iostream>
#include <vector>
#include <string>
#include "CaracteristicasSeres.h"
#include "Seres.h"
#include "Edificios.h"
#include "Mapa.h"
#include "Castelo.h"
#include "Comando.h"
#include "Interface.h"
#include "Desenho.h"
#include "Torre.h"
#include "Jogo.h"


using namespace std;


int main() {

	string escreve;
	Comando comando;
	Interface IE;
	Desenho desenho;
	Colonia colonia;
	Jogo jogo;

	jogo.ConfiguraJogoInicio();
	/*jogo.ConfiguraJogoInicioProximo();*/

	cout << "rekt" << endl;

	/*desenho.DesenhaScreenSize();*/
	/*desenho.DesenhaTudo();*/
	/*desenho.DesenhoLimitesInfo();
	desenho.DesenhoMapa();*/
	
	//desenho.DesenhaLimpa();
	//desenho.DesenhoLimitesComandos();
	
	
	/*mapa.getTerreno().at(21)->setSeres(new Seres(mapa.getTerreno().at(21)));

	mapa.getTerreno().at(20)->setEdificios(new Torre("T",mapa.getTerreno().at(20)));
	mapa.getTerreno().at(20)->getEdificios()->efeito(&colonia);
	*/

	//while (comando.getArg1() != "INICIO") {
	//	cout << "Introduza um comando: ";
	//	getline(cin, escreve);
	//	comando = IE.separaComando(escreve, comando);
	//	if (comando.getArg1() == "DIM") {
	//		if (comando.getArg2() != "0" && comando.getArg3() != "0") {
	//			cout << " Criado Mapa com as medidas: " << comando.getArg2() << "x" << comando.getArg3() << endl;
	//		}
	//		else {
	//			cout << "Comando mal escrito" << endl;
	//		}
	//	}
	//	if (comando.getArg1() == "OPONENTES") {
	//		if (comando.getArg2() != "0") {
	//			cout << "Existem : " << comando.getArg2() << " Oponentes" << endl;
	//		}
	//		else {
	//			cout << "Comando mal escrito" << endl;
	//		}
	//	}
	//	if (comando.getArg1() == "CASTELO") {
	//		if (comando.getArg2() != "0" && comando.getArg3() != "0" && comando.getArg4() != "0") { //corrigir
	//			cout << "Castelo " << comando.getArg2() << " criado na posicao :" << comando.getArg3() << "x" << comando.getArg4() << endl;
	//		}
	//		else {
	//			cout << "Comando mal escrito" << endl;
	//		}
	//	}
	//	if (comando.getArg1() == "MOEDAS") {
	//		if (comando.getArg2() != "0") {
	//			cout << "Adicionadas " << comando.getArg2() << " moedas" << endl;
	//		}
	//		else {
	//			cout << "Comando mal escrito" << endl;
	//		}
	//	}
	//	if (comando.getArg1() == "MKPERFIL") {
	//		if (comando.getArg2() != "0") {
	//			cout << "Perfil Criado: " << comando.getArg2() << endl;
	//		}
	//		else {
	//			cout << "Comando mal escrito" << endl;
	//		}
	//	}
	//	if (comando.getArg1() == "ADDPERFIL") {
	//		if (comando.getArg2() != "0" && comando.getArg3() != "0") {
	//			cout << "Caracteristica adicionada" << comando.getArg3() << "no perfil : " << comando.getArg2() << endl;
	//		}
	//		else {
	//			cout << "Comando mal escrito" << endl;
	//		}
	//	}
	//	if (comando.getArg1() == "SUBPERFIL") {
	//		if (comando.getArg2() != "0" && comando.getArg3() != "0") {
	//			cout << "Caracteristica Removida : " << comando.getArg3() << "no perfil : " << comando.getArg2() << endl;
	//		}
	//		else {
	//			cout << "Comando mal escrito" << endl;
	//		}
	//	}
	//	if (comando.getArg1() == "RMPERFIL") {
	//		if (comando.getArg2() != "0") {
	//			cout << "Perfil removido: " << comando.getArg2() << endl;
	//		}
	//		else {
	//			cout << "Comando mal escrito" << endl;
	//		}
	//	}
	//	if (comando.getArg1() == "LOAD") {
	//		if (comando.getArg2() != "0") {
	//			cout << "Leitura feita com sucesso" << endl;
	//		}
	//		else {
	//			cout << "Comando mal escrito" << endl;
	//		}
	//	}
	//}
	//cout << "Jogo Comecou" << endl;



	

}

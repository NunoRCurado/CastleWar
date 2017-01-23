#include "Desenho.h"
#include "Mapa.h"
#include "Colonia.h"


Desenho::Desenho()
{

}

Desenho::Desenho(int x, int y)
{
	this->x = x;
	this->y = y;
}

Desenho::~Desenho(void)
{

}

void Desenho::SetTitulo(int linha) {
	Consola c;
	int i;
	for (i = 0; i < 130; i++) {
		c.gotoxy(i, linha);
		cout << " ";
	}
	c.gotoxy(25, linha);
}

void Desenho::DesenhoLimitesComandos()
{
	Consola c;
	c.gotoxy(2, 27);
	cout << "Comandos : ";
	//inicio da borda dos Comandos

	c.gotoxy(12, 26);
	cout << (char)218; // canto superior esquerdo
	c.gotoxy(13, 26);
	for (int i = 13; i < 83; i++) //top
	{
		c.gotoxy(i, 26);
		cout << (char)196;
	}
	c.gotoxy(83, 26);
	cout << (char)191; //canto superior direito

	c.gotoxy(83, 27); //direita
	cout << (char)179;
	c.gotoxy(83, 28); //direita
	cout << (char)179;

	c.gotoxy(83, 29); //canto inferior direito
	cout << (char)217;
	c.gotoxy(13, 29); //baixo
	for (int i = 13; i < 83; i++)
	{
		c.gotoxy(i, 29);
		cout << (char)196;
	}
	c.gotoxy(12, 29); //canto inferior esquerdo
	cout << (char)192;

	c.gotoxy(12, 27); // esquerda
	cout << (char)179;
	c.gotoxy(12, 28); // esquerda
	cout << (char)179;

	//fim da borda de Comandos
	c.gotoxy(13, 27);
}


void Desenho::DesenhaTudo()
{
	DesenhaScreenSize();
	DesenhoLimitesMapa();
	DesenhoLimitesInfo();
	DesenhoLimitesComandos();
}

void Desenho::limpaLinhaProntoComandos()
{
	Consola c;
	int i;
	for (i = 13; i < 83; i++) {
		c.gotoxy(i, 27);
		cout << " ";
	}
	c.gotoxy(13, 27);

}

void Desenho::limpaLinhaProntoAvisos()
{
	Consola c;
	int i;
	for (i = 13; i < 83; i++) {
		c.gotoxy(i, 28);
		cout << " ";
	}
	c.gotoxy(13, 28);

}
void Desenho::limpaLinhaInfo()
{
	Consola c;
	int x, y;
	for (x = 92; x < 135; x++) {
		for (y = 3; y < 29; y++) {
			c.gotoxy(x, y);
			cout << " ";
		}
	}
}


void Desenho::escreveEmInfo(int linha)
{
	Consola c;
	c.gotoxy(92, linha);
}

void Desenho::pintaMapa(Mapa *mapa, vector<int> pos)
{
	Consola c;
	int posActual = 0;
	for (int y = 3; y < 23; y++) { // 23
		for (int x = 3; x < 83; x++) { // 83
			c.gotoxy(x, y);
			int posEnvia = pos.at(posActual);
			this->DesenhaMapa(mapa, posEnvia);
			x++;
			posActual++;
		}
	}
}

void Desenho::MapaInicial() {
	Consola c;
	for (int y = 3; y < 23; y++) {
		for (int x = 3; x < 83; x++) {
			c.gotoxy(x, y);
			cout << ".";
		}
	}
	c.gotoxy(27, 13);
}

void Desenho::DesenhaMapa(Mapa * mapa, int pos)
{
	Consola c;
			if (mapa->getTerreno().at(pos)->getEdificios() != NULL) {
				for (int nCol = 0; nCol < mapa->getColonias().size(); nCol++) {
					for (int nEdi = 0; nEdi < mapa->getColonias().at(nCol)->getEdificios()->size(); nEdi++) {
						if (mapa->getColonias().at(nCol)->getEdificios()->at(nEdi)->getTerreno()->getPosicao() == pos) {
							c.setTextColor(mapa->getColonias().at(nCol)->getCor());
							break;
						}
					}
				}
				cout << mapa->getTerreno().at(pos)->getEdificios()->getId();
				c.setTextColor(7);
				return;
			}
			else
				if (mapa->getTerreno().at(pos)->getSeres() != NULL) {
					for (int nCol = 0; nCol < mapa->getColonias().size(); nCol++) {
						for (int nSer = 0; nSer < mapa->getColonias().at(nCol)->getSeres()->size(); nSer++) {
							if (mapa->getColonias().at(nCol)->getSeres()->at(nSer)->getTerreno()->getPosicao() == pos) {
								c.setTextColor(mapa->getColonias().at(nCol)->getCor());
								break;
							}
						}
					}
					cout << mapa->getTerreno().at(pos)->getSeres()->getId();
					c.setTextColor(7);
					return;
				}
				else {
					cout << ".";
					return;
				}
	
}

//void Desenho::preencheMapa(Mapa *mapa, int inicio)
//{
//	Consola c;
//	int nCol = 0;
//	int nEdi = 0;
//	for (int y = 3; y < 23; y++) { // 23
//		for (int x = 3; x < 83; x++) { // 83
//			c.gotoxy(x, y);
//			if (mapa->getTerreno().at(inicio)->getEdificios() != NULL) {
//				for (nCol = 0; nCol < mapa->getColonias().size(); nCol++) {
//					for (nEdi = 0; nEdi < mapa->getColonias().at(nCol)->getEdificios().size(); nEdi++) {
//						if (mapa->getColonias().at(nCol)->getEdificios().at(nEdi)->getTerreno()->getPosicao() == inicio) {
//							c.setTextColor(mapa->getColonias().at(nCol)->getCor());
//							break;
//						}
//					}
//				}
//				cout << mapa->getTerreno().at(inicio)->getEdificios()->getId();
//				inicio++;
//				nCol++;
//				c.setTextColor(7);
//			}
//			else if (mapa->getTerreno().at(inicio)->getSeres() != NULL) {
//				for (nCol = 0; nCol < mapa->getColonias().size(); nCol++) {
//					for (nEdi = 0; nEdi < mapa->getColonias().at(nCol)->getSeres()->size(); nEdi++) {
//						if (mapa->getColonias().at(nCol)->getSeres()->at(nEdi)->getTerreno()->getPosicao() == inicio) {
//							c.setTextColor(mapa->getColonias().at(nCol)->getCor());
//							break;
//						}
//					}
//				}
//				cout << mapa->getTerreno().at(inicio)->getSeres()->getId();
//				inicio++;
//				c.setTextColor(7);
//			}
//			else {
//				cout << ".";
//				inicio++;
//			}
//			x++;
//		}
//	}
//	c.gotoxy(27, 13);
//	
//}

void Desenho::DesenhoLimitesInfo()
{
	Consola c;
	c.gotoxy(100, 1);
	cout << "INFORMACAO";
	//inicio da borda de status
	c.gotoxy(91, 2); //desenha esquina superior esquerda
	cout << (char)218;
	c.gotoxy(92, 2);
	for (int i = 92; i < 135; i++)//desenha linha horizontal top
	{
		c.gotoxy(i, 2);
		cout << (char)196;
	}
	c.gotoxy(135, 2); //desenha esquina superior direita
	cout << (char)191;
	for (int i = 3; i < 29; i++) //desenha linha vertical direita
	{
		c.gotoxy(135, i);//posicao do inicio do desenho da linha direita
		cout << (char)179;
	}

	for (int i = 92; i < 135; i++) //desenha linha horizontal inferior
	{
		c.gotoxy(i, 29);
		cout << (char)196;
	}
	c.gotoxy(135, 29);
	cout << (char)217; //desenha esquina direita inferior


	for (int i = 3; i < 29; i++) //desenha linha vertical esquerda
	{
		c.gotoxy(91, i);
		cout << (char)179;
	}

	c.gotoxy(91, 29);
	cout << (char)192;
	//fim da borda do status
}

void Desenho::DesenhoLimitesMapa()
{

	Consola c;
	c.gotoxy(40, 1);
	cout << "CASTLEWAR";

	//borda do mapa
	c.gotoxy(2, 2);
	cout << (char)218;

	c.gotoxy(3, 2);
	for (int i = 3; i < 83; i++)
	{
		c.gotoxy(i, 2);
		cout << (char)196;
	}

	c.gotoxy(83, 2);
	cout << (char)191;

	for (int i = 3; i < 23; i++)
	{
		c.gotoxy(2, i);
		cout << (char)179;
	}

	c.gotoxy(2, 23);
	cout << (char)192;

	c.gotoxy(3, 23);
	for (int i = 3; i < 83; i++)
	{
		c.gotoxy(i, 23);
		cout << (char)196;
	}

	for (int i = 3; i < 23; i++)
	{
		c.gotoxy(83, i);
		cout << (char)179;
	}

	c.gotoxy(83, 23);
	cout << (char)217;

}

void Desenho::DesenhaScreenSize()
{
	Consola c;
	c.setScreenSize(35, 140);
}

void Desenho::DesenhaLimpa()
{
	Consola c;
	c.clrscr();
}


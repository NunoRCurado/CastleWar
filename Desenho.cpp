#include "Desenho.h"


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


void Desenho::DesenhoLimitesComandos()
{
	Consola c;
	c.gotoxy(2, 27);
	cout << "Comandos : ";
	//inicio da borda dos Comandos

	c.gotoxy(12, 26);
	cout << (char)218; // canto superior esquerdo
	c.gotoxy(13, 26);
	for (int i = 13; i < 117; i++) //top
	{
		c.gotoxy(i, 26);
		cout << (char)196;
	}
	c.gotoxy(117, 26);
	cout << (char)191; //canto superior direito

	c.gotoxy(117, 27); //direita
	cout << (char)179;
	c.gotoxy(117, 28); //direita
	cout << (char)179;

	c.gotoxy(117, 29); //canto inferior direito
	cout << (char)217;
	c.gotoxy(13, 29); //baixo
	for (int i = 13; i < 117; i++)
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
	for (i = 13; i < 117; i++) {
		c.gotoxy(i, 27);
		cout << " ";
	}
	c.gotoxy(13, 27);

}

void Desenho::limpaLinhaProntoAvisos()
{
	Consola c;
	int i;
	for (i = 13; i < 117; i++) {
		c.gotoxy(i, 28);
		cout << " ";
	}
	c.gotoxy(13, 28);

}
void Desenho::limpaLinhaInfo()
{
	Consola c;
	int x, y;
	for (x = 92; x < 117; x++) {
		for (y = 3; y < 22; y++) {
			c.gotoxy(x, y);
			cout << " ";
		}
	}
}


void Desenho::escreveEmInfo(int linha)
{
	Consola c;
	c.gotoxy(92, linha+2);
}

void Desenho::preencheMapa(vector <Terreno *> terreno , int inicio)
{
	Consola c;
		for (int x = 3; x < 83; x++) {
			for (int y = 3; y < 23; y++) {
				c.gotoxy(x, y);
				if (terreno.at(inicio)->getEdificios() != NULL) {
					cout << terreno.at(inicio)->getEdificios()->getId();
					inicio++;
				}
				else if (terreno.at(inicio)->getSeres() != NULL) {
					cout << terreno.at(inicio)->getSeres()->getId();
					inicio++;
				}
				else {
					cout << ".";
					inicio++;
				}
		}
			x++;
	}
	c.gotoxy(27, 13);
	
}
void Desenho::DesenhoLimitesInfo()
{
	Consola c;
	c.gotoxy(100, 1);
	cout << "INFORMACAO";
	//inicio da borda de status
	c.gotoxy(91, 2); //desenha esquina superior esquerda
	cout << (char)218;
	c.gotoxy(92, 2);
	for (int i = 92; i < 118; i++)//desenha linha horizontal top
	{
		c.gotoxy(i, 2);
		cout << (char)196;
	}
	c.gotoxy(117, 2); //desenha esquina superior direita
	cout << (char)191;
	for (int i = 3; i < 24; i++) //desenha linha vertical direita
	{
		c.gotoxy(117, i);//posicao do inicio do desenho da linha direita
		cout << (char)179;
	}

	for (int i = 92; i < 118; i++) //desenha linha horizontal inferior
	{
		c.gotoxy(i, 24);
		cout << (char)196;
	}
	c.gotoxy(117, 24);
	cout << (char)217; //desenha esquina direita inferior


	for (int i = 3; i < 24; i++) //desenha linha vertical esquerda
	{
		c.gotoxy(91, i);
		cout << (char)179;
	}

	c.gotoxy(91, 24);
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
	c.setScreenSize(35, 130);
}

void Desenho::DesenhaLimpa()
{
	Consola c;
	c.clrscr();
}


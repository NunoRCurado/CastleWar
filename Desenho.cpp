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
	c.gotoxy(40, 22);
	cout << "Linha de Comandos";
	//inicio da borda dos Comandos

	c.gotoxy(4, 23);
	cout << (char)218;
	c.gotoxy(5, 23);
	for (int i = 5; i < 80; i++)
	{
		c.gotoxy(i, 23);
		cout << (char)196;
	}
	c.gotoxy(80, 23);
	cout << (char)191;
	for (int i = 24; i < 26; i++)
	{
		c.gotoxy(4, i);
		cout << (char)179;
	}
	c.gotoxy(4, 26);
	cout << (char)192;
	c.gotoxy(5, 26);
	for (int i = 5; i < 80; i++)
	{
		c.gotoxy(i, 26);
		cout << (char)196;
	}
	c.gotoxy(80, 26);
	cout << (char)217;
	for (int i = 24; i < 26; i++)
	{
		c.gotoxy(80, i);
		cout << (char)179;
	}
	//fim da borda de Comandos

}

//void Desenho::DesenhaSer()
//{
//}

void Desenho::DesenhaEdificio()
{
}

void Desenho::DesenhaTudo()
{
	DesenhaScreenSize();
	DesenhoLimitesInfo();
	DesenhoMapa();

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
	for (int i = 3; i < 22; i++) //desenha linha vertical direita
	{
		c.gotoxy(117, i);//posicao do inicio do desenho da linha direita
		cout << (char)179;
	}
	
	for (int i = 92; i < 118; i++) //desenha linha horizontal inferior
	{
		c.gotoxy(i, 22);
		cout << (char)196;
	}
	c.gotoxy(117, 22);
	cout << (char)217; //desenha esquina direita inferior


	for (int i = 3; i < 22; i++) //desenha linha vertical esquerda
	{
		c.gotoxy(91, i);
		cout << (char)179;
	}

	c.gotoxy(91, 22);
	cout << (char)192;
	//fim da borda do status
}

void Desenho::DesenhoMapa()
{

	Consola c;
	c.gotoxy(40, 1);
	cout << "CASTLEWAR";

	//borda do mapa
	c.gotoxy(2, 2);
	cout << (char)218;

	c.gotoxy(3, 2);
	for (int i = 3; i < 88; i++)
	{
		c.gotoxy(i, 2);
		cout << (char)196;
	}

	c.gotoxy(88, 2);
	cout << (char)191;

	for (int i = 3; i < 23; i++)
	{
		c.gotoxy(2, i);
		cout << (char)179;
	}

	c.gotoxy(2, 22);
	cout << (char)192;

	c.gotoxy(3, 22);
	for (int i = 3; i < 88; i++)
	{
		c.gotoxy(i, 22);
		cout << (char)196;
	}

	for (int i = 3; i < 22; i++)
	{
		c.gotoxy(88, i);
		cout << (char)179;
	}

	c.gotoxy(88, 22);
	cout << (char)217;

	//linha vertical 1º

	c.gotoxy(28, 22);
	cout << (char)217;

	c.gotoxy(28, 2);
	cout << (char)191;

	for (int i = 3; i < 22; i++)
	{
		c.gotoxy(28, i);
		cout << (char)179;
	}


	//linha vertical 2º

	c.gotoxy(60, 22);
	cout << (char)217;

	c.gotoxy(60, 2);
	cout << (char)191;

	for (int i = 3; i < 22; i++)
	{
		c.gotoxy(60, i);
		cout << (char)179;
	}

	//linha horizontal 1º

	c.gotoxy(88, 8);
	cout << (char)217;

	c.gotoxy(2, 8);
	cout << (char)192;

	for (int i = 3; i < 88; i++)
	{
		c.gotoxy(i,8);
		cout << (char)196;
	}
	//linha horizontal 2º


	//linha horizontal 1º

	c.gotoxy(88, 15);
	cout << (char)217;

	c.gotoxy(2, 15);
	cout << (char)192;

	for (int i = 3; i < 88; i++)
	{
		c.gotoxy(i, 15);
		cout << (char)196;
	}







	c.gotoxy(2, 30);

}

void Desenho::DesenhaScreenSize()
{
	Consola c;
	c.setScreenSize(150,250);
}

void Desenho::DesenhaLimpa()
{
	Consola c;
	c.clrscr();
}

void Desenho::limpaPosicaoActual(int posA) {


}

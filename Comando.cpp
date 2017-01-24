#include "Comando.h"



Comando::Comando(string arg1, string arg2, string arg3, string arg4, string arg5)
{
	this->arg1 = arg1;
	this->arg2 = arg2;
	this->arg3 = arg3;
	this->arg4 = arg4;
	this->arg5 = arg5;

}
Comando::Comando()
{}

string Comando::getArg1()
{
	return this->arg1;
}

string Comando::getArg2()
{
	return this->arg2;
}

string Comando::getArg3()
{
	return this->arg3;
}

string Comando::getArg4()
{
	return this->arg4;
}
string Comando::getArg5()
{
	return this->arg5;
}


void Comando::setArg1(string sub)
{
	this->arg1 = sub;
}

void Comando::setArg2(string sub)
{
	this->arg2 = sub;
}

void Comando::setArg3(string sub)
{
	this->arg3 = sub;
}

void Comando::setArg4(string sub)
{
	this->arg4 = sub;
}

void Comando::setArg5(string sub)
{
	this->arg5 = sub;
}


void Comando::setPos(int pos) {

	this->pos = pos;

}

int Comando::getPos() {

	return pos;

}



Comando::~Comando(void)
{
}

Comando Comando::separaComando(string & comando,Comando comandos)
{
	int i = 0;
	locale loc;

	for (std::string::size_type i = 0; i < comando.length(); ++i) //
		comando[i] = std::toupper(comando[i], loc);            // POE TUDO EM UPPERCASE

	istringstream iss(comando);

	comandos.setArg1("0");

	comandos.setArg2("0");

	comandos.setArg3("0");

	comandos.setArg4("0");

	comandos.setArg5("0");
	do
	{
		string sub;
		iss >> sub;

		if (i == 0)
			comandos.setArg1(sub);
		else if (i == 1)
			comandos.setArg2(sub);
		else if (i == 2)
			comandos.setArg3(sub);
		else if (i == 3)
			comandos.setArg4(sub);
		else if (i == 4)
			comandos.setArg5(sub);

		i++;
	} while (iss);
	return comandos;
}


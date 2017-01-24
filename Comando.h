#pragma once
#ifndef COMANDO_H
#define COMANDO_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <locale> 

using namespace std;
class Comando
{
	string arg1, arg2, arg3, arg4, arg5;
	int pos;

public:
	Comando(string arg1, string arg2, string arg3, string arg4, string arg5);
	Comando();
	Comando separaComando(string & comando, Comando comandos);
	void setArg1(string sub);
	void setArg2(string sub);
	void setArg3(string sub);
	void setArg4(string sub);
	void setArg5(string sub);
	void setPos(int pos);

	int getPos();
	string getArg1();
	string getArg2();
	string getArg3();
	string getArg4();
	string getArg5();

	~Comando(void);
};

#endif
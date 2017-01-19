#include "Espada.h"

Espada::Espada() : CaracteristicasSeres(6, 2, 2, true,"ESPADA")
{
	this->nAtaques = 0;
	this->flag = 0;
}

Espada::~Espada()
{
}

void Espada::efeito(Seres * ser, Mapa *mapa){
	if (flag == 0){
		ser->setAtaque(ser->getAtaque() + 2);
		flag = 1;
	}
	if (nAtaques <= 2){
		if (flag == 1) {
			ser->setAtaque(ser->getAtaque() + 1);
			flag++;
		}
	}
	else {
		if (flag == 2){
			ser->setAtaque(ser->getAtaque() - 1);
			flag++;
		}
	}
	nAtaques++;
	if (ser->getLocalizacao() == 1 ){ //id do castelo ver com o ponteiro do mapa
		flag = 1;
		nAtaques = 0;
	}
}

#include "Remedio.h"

Remedio::Remedio() : CaracteristicasSeres(12,2,1,true,"REMEDIO")
{
	this->flag = 0;
}

Remedio::~Remedio()
{
}

void Remedio::efeito(Seres * ser, Mapa *mapa)
{
	if (ser->getSaude() <=3) {
		if (flag == 0){
			ser->setSaude(ser->getSaude() + 2);
			flag = 1;
		}
	}
	if (ser->getLocalizacao() == 1) { // ver com o ponteiro do mapa
		flag = 0;
	}
}

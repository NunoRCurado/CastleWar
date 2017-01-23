#include "SecondChance.h"

SecondChance::SecondChance() : CaracteristicasSeres(13,3,0,true,"SECONDCHANCE")
{
	
}

SecondChance::~SecondChance()
{
}

void SecondChance::efeito(Seres * ser, Mapa *mapa)
{
	if (ser->getSaude() <= 0) {             //confirmar que unidades nao ficam com hp negativo
		if (getActivo() == true) {
			ser->setSaude(10);			//resto dos bonus?
			ser->setLocalizacao(1);  //alterar de forma a ir para o castelo, preciso saber a pos do castelo 
			setActivo(false);		// ver com o ponteiro do mapa
		}
	}
}

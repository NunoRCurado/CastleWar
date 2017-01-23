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
			ser->setLocalizacao(1);  
			setActivo(false);		
		}
		else {
			mapa->removeSeresDaColonia(ser->getColonia(), ser);
		}
	}
}

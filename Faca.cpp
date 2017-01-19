#include "Faca.h"

Faca::Faca() : CaracteristicasSeres(5,1,1,false,"FACA")
{
}

Faca::~Faca()
{
}

void Faca::efeito(Seres * ser, Mapa *mapa)
{
	ser->setAtaque(ser->getAtaque() + 1);
}

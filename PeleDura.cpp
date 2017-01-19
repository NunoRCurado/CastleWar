#include "PeleDura.h"

PeleDura::PeleDura() : CaracteristicasSeres(3, 2, 2, false,"PELEDURA")
{
}

PeleDura::~PeleDura()
{
}

void PeleDura::efeito(Seres * ser, Mapa *mapa)
{
	ser->setDefesa(ser->getDefesa() + 1);
}

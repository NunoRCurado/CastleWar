#include "Armadura.h"

Armadura::Armadura() : CaracteristicasSeres(4, 2, 3, false, "ARMADURA")
{
}

Armadura::~Armadura()
{
}

void Armadura::efeito(Seres * ser, Mapa *mapa)
{
	ser->setDefesa(ser->getDefesa() + 1);
}

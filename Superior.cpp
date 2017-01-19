#include "Superior.h"

Superior::Superior() : CaracteristicasSeres(2, 1, 1, false,"SUPERIOR")
{
}

Superior::~Superior()
{
}

void Superior::efeito(Seres * ser, Mapa *mapa)
{
	ser->setSaude(ser->getSaude() + 1);
}

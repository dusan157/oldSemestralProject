#include "Obec.h"



Obec::Obec()
{
}


Obec::~Obec()
{
	okres = nullptr;
	delete okres;
	kraj = nullptr;
	delete kraj;
}

void Obec::setKraj(Oblast * pKraj)
{
	kraj = pKraj;
}

void Obec::setOkres(Oblast * pOkres)
{
	okres = pOkres;
}

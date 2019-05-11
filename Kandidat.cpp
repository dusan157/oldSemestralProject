#include "Kandidat.h"



Kandidat::Kandidat(std::string pMeno)
{
	meno = pMeno;
	hlasy = new structures::Array<int>(2);
	(*hlasy)[0] = -1;
	(*hlasy)[1] = -1;
}


Kandidat::~Kandidat()
{
	delete hlasy;
}

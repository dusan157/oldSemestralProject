#include "Okres.h"



Okres::Okres()
{
	//obce = new structures::SortedSequenceTable<int, Obec*>;
}


Okres::~Okres()
{
	/*for (auto item : *this) {
		delete item->accessData();
		delete item;
	}*/
	kraj = nullptr;
	delete kraj;
}

void Okres::setKraj(Oblast * pKraj)
{
	kraj = pKraj;
}

void Okres::setObce()
{
	for (auto item : *this) {
		item->accessData()->setKraj(kraj);
		item->accessData()->setOkres(this);
	}
}

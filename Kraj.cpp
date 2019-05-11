#include "Kraj.h"



Kraj::Kraj() :Oblast()
{
	//okresy = new structures::SortedSequenceTable<int, Okres*>;
}

void Kraj::setOkresy()
{
	for (auto item : *this) {
		item->accessData()->setKraj(this);
	}
}

void Kraj::addOkres(int kluc,Okres * pOkres)
{
	this->insert(kluc, pOkres);
}
Kraj::~Kraj()
{
	/*for (auto item : *this) {
		delete item->accessData();
		delete item;
	}*/
}

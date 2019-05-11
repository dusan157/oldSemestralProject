#pragma once
#include "Komparator.h"

class KomparatorUcast : public Komparator<int, Obec *> {
public:
	virtual bool porovnaj(structures::TableItem<int, Obec*> oblast1, structures::TableItem<int, Obec*> oblast2) override
	{
		if (usporiadanie == 0) {
			return (oblast1.accessData()->getUcast(kolo) > oblast2.accessData()->getUcast(kolo));
		}
		else {
			return (oblast1.accessData()->getUcast(kolo) < oblast2.accessData()->getUcast(kolo));
		}
	}
	void setUsporiadanie(int pUspo) {
		usporiadanie = pUspo;
	}
	void setKolo(int pKolo) {
		kolo = pKolo;
	}
private:
	int usporiadanie;
	int kolo;
};


#pragma once
#include "Komparator.h"

class KomparatorVolici : public Komparator<int, Obec *> {
public:
	virtual bool porovnaj(structures::TableItem<int, Obec*> oblast1, structures::TableItem<int, Obec*> oblast2) override
	{
		if (usporiadanie == 0) {
			return (oblast1.accessData()->getVolici(kolo) > oblast2.accessData()->getVolici(kolo));
		}
		else {
			return (oblast1.accessData()->getVolici(kolo) < oblast2.accessData()->getVolici(kolo));
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


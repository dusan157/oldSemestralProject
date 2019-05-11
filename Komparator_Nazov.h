#pragma once
#include "Komparator.h"

class KomparatorNazov : public Komparator<int, Obec *> {
public:
	virtual bool porovnaj(structures::TableItem<int, Obec*> oblast1, structures::TableItem<int, Obec*> oblast2) override
	{
		if (usporiadanie == 0) {
			return (oblast1.accessData()->getNazov() > oblast2.accessData()->getNazov());
		}
		else {
			return (oblast1.accessData()->getNazov() < oblast2.accessData()->getNazov());
		}
	}
	void setUsporiadanie(int pUspo) {
		usporiadanie = pUspo;
	}
private:
	int usporiadanie;
};


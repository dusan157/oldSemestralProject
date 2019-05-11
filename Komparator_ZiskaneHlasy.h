#pragma once
#include "Komparator.h"
#include "Kandidat.h"

class KomparatorZiskaneHlasy : public Komparator<std::string, Kandidat *> {
public:
	virtual bool porovnaj(structures::TableItem<std::string, Kandidat*> kandidat1, structures::TableItem<std::string, Kandidat*> kandidat2) override
	{
		if (usporiadanie == 0) {
			return (kandidat1.accessData()->getHlasy(kolo) > kandidat2.accessData()->getHlasy(kolo));
		}
		else {
			return (kandidat1.accessData()->getHlasy(kolo) < kandidat2.accessData()->getHlasy(kolo));
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


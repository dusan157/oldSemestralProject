#pragma once
#include "Kandidat.h"
#include "Kriterium.h"
class KriteriumHlasy : public Kriterium<int, Kandidat> {
public:
	int evaluate(Kandidat& kand) override
	{
		return kand.getHlasy(kolo);
	}
	inline void setKolo(int pKolo) {
		kolo = pKolo;
	}

private:
	int kolo;
};
#pragma once
#include "Oblast.h"
#include "Kriterium.h"
class KriteriumVolici : public Kriterium<int, Oblast> {
public:
	int evaluate(Oblast& a) override
	{
		return a.getVolici(kolo);
	}
	inline void setKolo(int pKolo) {
		kolo = pKolo;
	}
private:
	int kolo;
};

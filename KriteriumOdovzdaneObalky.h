#pragma once
#include "Oblast.h"
#include "Kriterium.h"
class KriteriumOdovzdaneObalky : public Kriterium<int, Oblast> {
public:
	int evaluate(Oblast& oblast) override
	{
		return oblast.getOdovzdaneObalky(kolo);
	}
	inline void setKolo(int pKolo) {
		kolo = pKolo;
	}
private:
	int kolo;
};
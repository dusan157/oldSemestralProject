#pragma once
#include "Oblast.h"
#include "Kriterium.h"
class KriteriumOdovzdaneHlasy : public Kriterium<int, Oblast> {
public:
	int evaluate(Oblast& oblast) override
	{
		return oblast.getHlasy(kolo);
	}
	inline void setKolo(int pKolo) {
		kolo = pKolo;
	}
private:
	int kolo;
};
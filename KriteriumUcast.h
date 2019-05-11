#pragma once
#include "Oblast.h"
#include "Kriterium.h"
class KriteriumUcast :  public Kriterium<float, Oblast>{
public:
	float evaluate(Oblast& oblast) {
		//TODO dorobit kola v oblasti
		return oblast.getUcast(kolo);
	}
	inline void setKolo(int pKolo) {
		kolo = pKolo;
	}
private:
	int kolo;
};
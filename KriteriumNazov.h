#pragma once
#include "Kriterium.h"
#include "Oblast.h"
class KriteriumNazov : public Kriterium<std::string,Oblast> {
public: 
	std::string evaluate(Oblast& a) override 
	{ 
		return a.getNazov(); 
	}
};
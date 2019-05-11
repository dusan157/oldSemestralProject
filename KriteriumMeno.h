#pragma once
#include "Kriterium.h"
#include "Oblast.h"
class KriteriumMeno : public Kriterium<std::string, Kandidat> {
public:
	std::string evaluate(Kandidat& a) override
	{
		return a.getMeno();
	}
};
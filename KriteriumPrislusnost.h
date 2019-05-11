#pragma once
#include "Oblast.h"
#include "Kriterium.h"
class KriteriumPrislusnost : public Kriterium<bool,Obec> {
public:
	bool evaluate(Obec& obec) override
	{
		return obec.patriPod(oblast);
	}
	inline void setOblast(std::string pOblast) 
	{
		oblast = pOblast;
	};
private:
	std::string oblast;
};
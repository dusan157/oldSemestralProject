#pragma once
#include "Oblast.h"
class Obec :
	public Oblast
{
public:
	Obec();
	~Obec();
	void setOkres(Oblast*);
	void setKraj(Oblast*);
	Oblast* getOkres() { return okres; };
	Oblast* getKraj() { return kraj; };
	bool patriPod(std::string oblast) { return (okres->getNazov() == oblast || kraj->getNazov() == oblast); };
	inline std::string vypisK_nazov() { return (kraj->getNazov() + "\t" + okres->getNazov() + "\t" + nazov); };
private:
	Oblast *okres;
	Oblast *kraj;
};


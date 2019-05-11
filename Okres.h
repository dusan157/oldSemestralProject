#pragma once
#include "Oblast.h"
#include "structures/table/sorted_sequence_table.h"
#include "Obec.h"
class Okres :
	public Oblast,public structures::SortedSequenceTable<int, Obec*>
{
public:
	Okres();
	~Okres();
	void setKraj(Oblast*);
	Oblast* getKraj() { return kraj; }
	void setObce();
	bool patriPod(Oblast* oblast) { return (kraj == oblast); };
	std::string vypisK_nazov() { return (kraj->getNazov() + " " + nazov); };
private:
	Oblast *kraj;
	//structures::SortedSequenceTable<int, Obec*> *obce;

};


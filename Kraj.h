#pragma once
#include "structures/table/sorted_sequence_table.h"
#include "Oblast.h"
#include "Okres.h"
class Kraj :
	public Oblast, public structures::SortedSequenceTable<int, Okres*>
{
public:
	Kraj();
	void setOkresy();
	void addOkres(int,Okres*);
	std::string vypisK_nazov() { return nazov; };
	~Kraj();
private:
	//structures::SortedSequenceTable<int, Okres*> *okresy;
};


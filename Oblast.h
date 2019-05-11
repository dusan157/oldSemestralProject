	#pragma once
#include "structures/array/array.h"
#include <string>
#include "ZaznamOblast.h"
#include "structures/array/array.h"
#include "Kandidat.h"
#include "structures/table/unsorted_sequence_table.h"
#include <fstream>
class Oblast
{
public:
	Oblast();
	~Oblast();
	virtual std::string vypisK_nazov() = 0;
	inline std::string getNazov() { return nazov; };
	inline int getVolici(int kolo) { return (*volici)[kolo]; };
	inline int getVydaneObalky(int kolo) { return (kolo == 0 || kolo == 1) ? (*vydaneObalky)[kolo] : ((*vydaneObalky)[0] + (*vydaneObalky)[1]);};
	inline int getOdovzdaneObalky(int kolo) { return (kolo == 0 || kolo == 1) ? (*odovzdaneObalky)[kolo] : ((*odovzdaneObalky)[0] + (*odovzdaneObalky)[1]);};
	inline int getHlasy(int kolo) { return (kolo == 0 || kolo == 1) ? (*hlasy)[kolo] : ((*hlasy)[0] + (*hlasy)[1]);};
	inline float getUcast(int kolo) {return (*ucast)[kolo]; };
	inline structures::UnsortedSequenceTable<std::string, Kandidat*> * getKandidati() { return kandidati; };
	int getKandidatHlasy(std::string,int);
	void setData(int,std::string);
	void setDataKandidati(std::string,int,int);

protected:
	std::string nazov;
	structures::Array<int> *volici;
	structures::Array<int> *vydaneObalky;
	structures::Array<int> *odovzdaneObalky;
	structures::Array<float> *ucast;
	structures::Array<int> *hlasy;
	structures::UnsortedSequenceTable<std::string, Kandidat*> *kandidati;
};


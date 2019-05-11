#pragma once
#include <string>
#include "structures/array/array.h"
class Kandidat
{
public:
	Kandidat(std::string);
	//inline void setOblast(Oblast * pOblast) { oblast = pOblast; };
	std::string getMeno() { return meno; };
	void setHlasy(int kolo, int hodnota) { (*hlasy)[kolo] = hodnota; };
	int getHlasy(int kolo) { return (kolo == 0 || kolo == 1) ? (*hlasy)[kolo] : ((*hlasy)[0] + (*hlasy)[1]); };
	~Kandidat();
private:
	std::string meno;
	structures::Array<int> *hlasy;
	

};


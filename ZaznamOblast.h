#pragma once
#include <string>
class ZaznamOblast
{
public:
	ZaznamOblast(int,int,int,int,double);
	~ZaznamOblast();
	inline int getVolici() { return volici; };
	inline int getVydaneObalky() { return vydaneObalky; };
	inline int getOdovzdaneObalky() { return odovzdaneObalky; };
	inline int	getOdovzdaneHlasy() { return odovzdaneHlasy; };
	inline double getUcast() { return ucast; };
protected:
	int volici;
	int vydaneObalky;
	int odovzdaneObalky;
	int odovzdaneHlasy;
	double ucast;
};


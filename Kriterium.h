#pragma once
enum Kolo {prve,druhe,obe};
template<typename T, typename O>
class Kriterium
{
public:
	virtual T evaluate(O& object) = 0;
};

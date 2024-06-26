#pragma once
#include "Kriterium.h"
template<typename T, typename O>
class Filter
{
public:
	virtual bool evaluate(O& o, Kriterium<T, O>& c) = 0;
};

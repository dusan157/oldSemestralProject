#pragma once
#include "Filter.h"
template <typename T, typename O>
class Filter_fi: public Filter<T, O>
{
  public: 
	  bool evaluate(O& o,Kriterium<T, O>& c) override 
	  {
		  return (c.evaluate(o).find(alpha) != string::npos);
	  }
	  void setAlpha(T pAlpha) {
		  alpha = pAlpha;
	  }
  private: 
	  T alpha;
};
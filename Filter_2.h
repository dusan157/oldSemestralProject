#pragma once
#include "Filter.h"
template <typename T, typename O>
class Filter_FI: public Filter<T, O>
{
  public: 
	  bool evaluate(O& o, Kriterium<T, O>& c) override {
		  T result = c.evaluate(o);
		  return (result >= alpha && beta >= result);
	  }

	  void setAlpha(T pAlpha) {
		  alpha = pAlpha;
	  }
	  void setBeta(T pBeta) {
		  beta = pBeta;
	  }
  private: 
	  T alpha; //min
	  T beta;	//max
};
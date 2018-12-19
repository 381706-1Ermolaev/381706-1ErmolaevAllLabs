#pragma once

#include "Monom.h"

class TPolynom {
protected:
	TMonom *start;
	TMonom *end;
	int n; //x1x2...xn
public:
	TPolynom() { start = end = 0; n = 0; }
	TPolynom(int _n) { n = _n; start = end = 0;}
	TPolynom(int _n, TMonom _start, TMonom _end) { n = _n; start =new TMonom (_start); end = new TMonom(_end); }
	TPolynom(TPolynom &p);
	void setStart(TMonom *_start) { start = _start; }
	void setEnd(TMonom *_end) { end = _end; }
	TPolynom& operator+=(TMonom &m);
	TPolynom& operator=(TPolynom &p);
	TPolynom operator+(TPolynom &p);
	TPolynom operator*(TPolynom &p);
	friend std::ostream& operator << (std::ostream& _s, TPolynom& Tm);
};

std::ostream& operator << (std::ostream& _s, TPolynom& Tm)
{
	
	while (Tm.start != Tm.end) 
	{
		_s << *Tm.start;
		Tm.start = Tm.start->GetNext();
	}
	_s << *Tm.start;
			
	return _s;
}
#include "Polynom.h"

//Возможно только этот оператор нужен будет на экзамене, стоит уточнить
TPolynom TPolynom::operator+ (TPolynom &p) {
	TPolynom temp(n);
	TMonom *i1 = start, *i2 = p.start, *i = 0;
	while ((i1 != 0) && (i2 != 0)) 
	{
		TMonom *t1;
		if ((*i1) == (*i2))
		{	
			t1 = new TMonom((*i1) + (*i2));
			i1 = i1->GetNext();
			i2 = i2->GetNext();
		}
		else 
			//для понимания стоит рисовать картинку для: (x0^2 + x1 + x2^2) + (x0^2 + x0 + x2^2 + x2)
		{
			if ((*i1) < (*i2)) 
			{
				t1 = new TMonom((*i2));
				i2 = i2->GetNext();
			}
			else 
			{
				t1 = new TMonom((*i1));
				i1 = i1->GetNext();
			}
		}
		if (temp.start == 0)
		{
			temp.start = t1; //если полином пустой, то туда впихиваем t1
			i = t1; //переходим к t1
		}
		else
		{
			i->SetNext(t1); //добавляем t1 к полиному, если он не пустой
			i = t1; //переходим к t1
		}
	}
	if (i1 == 0)
		i1 = i2; //если дошли до конца первого полинома, то перекидываем итератор второого на первый
	while (i1 != 0) //докидываем остаток
	{
		i->SetNext(new TMonom(*i1));
		i1 = i1->GetNext();
	}
	return temp;
}

TPolynom::TPolynom(TPolynom &p) {
	n = p.n;

	TMonom* a = p.start;
	TMonom* b;
	if (p.start == 0)
	{
		start = 0;
		end = 0;
	}
	else
	{
		start = new TMonom(*p.start); 
		b = start;
		while (a->GetNext() != end) {
			b->SetNext(new TMonom(*(a->GetNext()))); 
			a = a->GetNext();
			b = b->GetNext();
		}
	}
}

TPolynom& TPolynom::operator+=(TMonom &m)
{
	TMonom *_start, *_end;
	_start = start;
	_end = start->GetNext();
	if (start == 0) // если полином пуст
	{
		start = new TMonom(m);
		end = start;
	}
	else
	{
		if (*start < m) // если моном меньше, чем первый член полинома
		{
			TMonom* tmp = new TMonom(m);
			tmp->SetNext(start);
			start = tmp;
		}
		else
		{
			while (_end != 0)// пробегаемся по всему полиному
			{
				if (*_start < m && m < *_end)
				{
					TMonom* tmp = new TMonom(m);
					_start->GetNext();
					tmp->SetNext(_end);
					break;
				}
				_start = _end;
				_end = _end->GetNext();
			}
			if (_end == 0)
			{
				start->SetNext(new TMonom(m));
				end = start->GetNext();
			}
		}
	}
	return *this;
}

TPolynom& TPolynom::operator=(TPolynom &p) 
{
	return *this;
}

TPolynom TPolynom::operator*(TPolynom &p)
{
	TPolynom temp(n);
	TMonom *_start = start;
	TMonom *_pstart = p.start;
	while (_start != 0)
		while (_pstart != 0) {
			temp += (*_start) * (*_pstart);
			_start = _start->GetNext();
			_pstart = _pstart->GetNext();
		}
	return temp;
}